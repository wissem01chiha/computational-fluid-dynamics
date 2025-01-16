

#include <Eigen/Core>
#include <glog/logging.h>
#include <opencv2/features2d/features2d.hpp>

#include "feature.h"
#include "keypoint_detector.h"

#include "../util/types.h"

class DescriptorExtractor {
 public:

  DescriptorExtractor() {}
  ~DescriptorExtractor() { }

  // The descriptor type must be set prior to calling ExtractDescriptors().
  bool SetDescriptor(const std::string& descriptor_type);

  // Creates a list of features by extracting descriptors for each keypoint and
  // associating the two together into an object.
  bool DescribeFeatures(const Image& image, KeypointList& keypoints,
                        std::vector<Feature>& features_out,
                        std::vector<Descriptor>& descriptors_out);

 private:

  std::string descriptor_type_;
  cv::Ptr<cv::DescriptorExtractor> extractor_;
}; 
