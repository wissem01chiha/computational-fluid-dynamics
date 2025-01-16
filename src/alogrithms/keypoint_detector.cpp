
#include "keypoint_detector.h"

#include <glog/logging.h>


KeypointDetector::KeypointDetector()
    : grid_filter_(false),
      grid_rows_(0),
      grid_cols_(0),
      grid_min_num_points_(0) {
  cv::initModule_nonfree();
}

void KeypointDetector::SetDetector(const std::string& detector_type) {

  detector_type_ = detector_type;

  // Create an OpenCV feature detector.
    if (grid_filter_) {
      detector_ =
          cv::Ptr<cv::FeatureDetector>(new cv::GridAdaptedFeatureDetector(
              cv::FeatureDetector::create(detector_type), grid_min_num_points_,
              grid_rows_, grid_cols_));
    } else {
      detector_ = cv::FeatureDetector::create(detector_type);
    }
}

bool KeypointDetector::DetectKeypoints(const Image& image,
                                       KeypointList& keypoints_out) {
  // Make the user has called SetDetector().
  if (detector_type_.empty()) {
    VLOG(1) << "Detector has not been specified via SetDetector(). Failed to "
               "detect keypoints.";
    return false;
  }
  CHECK(detector_) << "The feature detector is null.";

  // Clear the output.
  keypoints_out.clear();

  // Convert the input image to OpenCV's format.
  cv::Mat cv_image;
  image.ToCV(cv_image);

  // Convert to grayscale if the image was in color.
  if (image.IsColor()) {
    cv::cvtColor(cv_image, cv_image, CV_BGR2GRAY);
  }

  // Detect keypoints in the image.
  try {
    detector_->detect(cv_image, keypoints_out);
  } catch (const std::exception& e) {
    VLOG(1) << "Failed to detect keypoints: " << e.what();
    return false;
  }

  return true;
}

// Turn the grid filter on.
void KeypointDetector::SetGridOn(unsigned int rows, unsigned int cols,
                                 unsigned int min_num_points) {
  grid_filter_ = true;
  grid_rows_ = rows;
  grid_cols_ = cols;
  grid_min_num_points_ = min_num_points;

  // If the feature detector is already set, re-initialize it.
  if (detector_ != nullptr) {
    SetDetector(detector_type_);
  }
}

// Turn grid filter off.
void KeypointDetector::SetGridOff() {
  grid_filter_ = false;
  grid_rows_ = 0;
  grid_cols_ = 0;
  grid_min_num_points_ = 0;

  // If the feature detector is already set, re-initialize it.
  if (detector_ != nullptr) {
    SetDetector(detector_type_);
  }
}

}  //\namespace bsfm
