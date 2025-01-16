#pragma once 

#include <eigen3/Eigen/Core>
#include <glog/logging.h>
#include "../util/types.h"

class DistanceMetric {
 public:
  enum Metric {
    SCALED_L2,
    HAMMING
  };
  DistanceMetric();
  static DistanceMetric& instance();
  void setMetric(const Metric& metric = Metric::SCALED_L2);
  void setMetric(const std::string& metric = "SCALED_L2");

  // Set a maximum tolerable distance between two descriptors. This is not
  // required, but is useful for comparisons like:
  //
  // DistanceMetric& distance = DistanceMetric::Instance();
  // if (distance(descriptor1, descriptor2) < DistanceMetric::Max()) {
  //    // This is a good match.
  //  }
  //
  //  By default, a maximum distance is set to infinity, so if this function is
  //  not called, distance(descriptor1, descriptor2) < DistanceMetric::Max()
  //  will always evaluate to true.
  void setMaximumDistance(double maximum_distance);

  // Returns the maximum tolerable distance between two descriptors. If this
  // value has not been set with 'SetMaximumDistance', returns 0.
  double max() const;

  // Functor method computes distance between two input descriptors.
  double operator()(const Descriptor& descriptor1,
                    const Descriptor& descriptor2);

  // Depending on the distance metric used, normalize descriptors.
  bool MaybeNormalizeDescriptors(std::vector<Descriptor>& descriptors) const;

 private:

  // Compute the L2 norm of the difference between two descriptor vectors. If both
  // descriptors have unit length, the L2 norm is equal to 2*(1-x.y). Since all
  // distances are computed this way, we can drop the leading 2*. The L2 norm
  // induces an inner product space over R^{n}, and we can test as such.
  double getScaledL2Distance(const Descriptor& descriptor1,
                             const Descriptor& descriptor2) const;

  // Compute the Hamming distance between two binary descriptor vectors. This is
  // the number of bits that are in disagreement (i.e. bit1 ^ bit2 == 1).
  double getHammingDistance(const Descriptor& descriptor1,
                            const Descriptor& descriptor2) const;
  void normalizeDescriptors(std::vector<Descriptor>& descriptors) const;

  Metric metric_;

  // A maximum tolerable distance between two descriptors. Defaults to
  // std::numeric_limits<double>::max(), which would imply that all descriptors
  // match to one another.
  double maximum_distance_;
};
