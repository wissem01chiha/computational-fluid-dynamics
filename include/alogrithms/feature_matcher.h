
#include <unordered_map>

#include <glog/logging.h>

#include "feature.h"
#include "feature_matcher_options.h"

#include "../image/image.h"
#include "../util/types.h"

class FeatureMatcher {
 public:
  FeatureMatcher() { }
  virtual ~FeatureMatcher() { }


  virtual void AddImageFeatures(
      const std::vector<Feature>& image_features,
      const std::vector<Descriptor>& image_descriptors);

  // Add features from a set of images for matching.
  virtual void AddImageFeatures(
      const std::vector<std::vector<Feature> >& image_features,
      const std::vector<std::vector<Descriptor> >& image_descriptors);

  // Match images together using the input options.
  virtual bool MatchImages(const FeatureMatcherOptions& options,
                           PairwiseImageMatchList& image_matches);

 protected:
  // Abstract method to match a pair of images using the input options. Override
  // this in the derived feature matching strategy class to implement it.
  virtual bool MatchImagePair(int image_index1, int image_index2,
                              PairwiseImageMatch& image_match) = 0;

  // Find the set intersection of the two sets of input feature matches, and
  // store that set in the second argument.
  virtual void SymmetricMatches(
      const std::vector<LightFeatureMatch>& feature_matches_lhs,
      std::vector<LightFeatureMatch>& feature_matches_rhs);

  // Each image has a list of features and descriptors (one per feature).
  std::vector<std::vector<Feature> > image_features_;
  std::vector<std::vector<Descriptor> > image_descriptors_;

  // A set of options used for matching features and images.
  FeatureMatcherOptions options_;

 private:

}; 
