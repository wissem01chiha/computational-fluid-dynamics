#pragma  once

#include <opencv2/features2d/features2d.hpp>
#include <string>

#include "../common/image.h"

class KeypointDetector {
 public:
  KeypointDetector();
  ~KeypointDetector();

  void setDetector(const std::string& detector_type);

  // Detects keypoints in the input image, returning them in the output list.
  bool detectKeypoints(const Image& image, KeypointList& keypoints_out);

  // Turn on grid filter counts.
  // - rows:           number of grid rows.
  // - cols:           number of grid columns.
  // - min_num_points: minimum number of points to return.
  void setGridOn(unsigned int rows, unsigned int cols, unsigned int min_num_points);
  void setGridOff();

 private:
  std::string detector_type_;
  cv::Ptr<cv::FeatureDetector> detector_;
  bool grid_filter_;
  unsigned int grid_rows_;
  unsigned int grid_cols_;
  unsigned int grid_min_num_points_;
};
