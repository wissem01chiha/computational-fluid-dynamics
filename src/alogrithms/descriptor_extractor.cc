#include "descriptor_extractor.h"


bool DescriptorExtractor::SetDescriptor(const std::string& descriptor_type) {

  descriptor_type_ = descriptor_type;
  bool valid_descriptor_type = true;

  // Create an OpenCV descriptor extractor.
  if (descriptor_type.compare("SIFT") == 0) {
    extractor_ = cv::DescriptorExtractor::create("SIFT");
  } else if (descriptor_type_.compare("SURF") == 0) {
    extractor_ = cv::DescriptorExtractor::create("SURF");
  } else if (descriptor_type_.compare("BRIEF") == 0) {
    extractor_ = cv::DescriptorExtractor::create("BRIEF");
  } else if (descriptor_type_.compare("BRISK") == 0) {
    extractor_ = cv::DescriptorExtractor::create("BRISK");
  } else if (descriptor_type_.compare("FREAK") == 0) {
    extractor_ = cv::DescriptorExtractor::create("FREAK");
  } else if (descriptor_type_.compare("ORB") == 0) {
    extractor_ = cv::DescriptorExtractor::create("ORB");
  } else {
    VLOG(1) << "Descriptor type \"" << descriptor_type
            << "\"is not available. Defaulting to SIFT.";
    extractor_ = cv::DescriptorExtractor::create("SIFT");
    valid_descriptor_type = false;
    descriptor_type_ = "SIFT";
  }

  return valid_descriptor_type;
}

bool DescriptorExtractor::DescribeFeatures(
    const Image& image, KeypointList& keypoints,
    std::vector<Feature>& features_out,
    std::vector<Descriptor>& descriptors_out) {
  // Make the user has called SetDescriptor().
  if (descriptor_type_.empty()) {
    VLOG(1)
        << "Descriptor has not been specified via SetDescriptor(). Failed to "
           "extract descriptors.";
    return false;
  }

  CHECK(extractor_) << "The descriptor extractor is null.";
  features_out.clear();

  // Convert the input image to OpenCV's format.
  cv::Mat cv_image;
  image.ToCV(cv_image);

  // Convert to grayscale if the image was in color.
  if (image.IsColor()) {
    cv::cvtColor(cv_image, cv_image, CV_BGR2GRAY);
  }

  // Extract descriptors from the provided keypoints in the image.
  cv::Mat cv_descriptors;
  try {
    extractor_->compute(cv_image, keypoints, cv_descriptors);
  } catch (const std::exception& e) {
    VLOG(1) << "Failed to extract descriptors: " << e.what();
    return false;
  }


  for (size_t ii = 0; ii < keypoints.size(); ++ii) {
    Feature feature;
    feature.u_ = keypoints[ii].pt.x;
    feature.v_ = keypoints[ii].pt.y;
    features_out.push_back(feature);

    MatrixXd descriptor_mat;
    OpenCVToEigenMat<double>(cv_descriptors.row(ii), descriptor_mat);

    // Need to explicitly convert from matrix to vector.
    Descriptor descriptor = descriptor_mat.row(0).transpose();
    descriptors_out.push_back(descriptor);
  }

  return true;
}
