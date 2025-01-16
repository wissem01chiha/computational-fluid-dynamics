#pragma once 

#include <memory>
#include <string>

#include <eigen3/Eigen/Dense>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <glog/logging.h>

class Image{
public:
  Image();
  Image(const Image& other);
  Image(size_t width, size_t height, size_t channels);
  Image(const std::string& filename);
  explicit Image(const cv::Mat& other);
  void toCV(cv::Mat& out) const;
  void fromCV(const cv::Mat& in);
  void toEigen(Eigen::MatrixXf& eigen_out);
  void toArray(double* array);
  void read(const std::string& filename);
  void write(const std::string& filename) const;
  size_t width() const;
  size_t height() const;
  size_t cols() const { return width(); }
  size_t rows() const { return height(); }
  size_t channels() const;
  void resize(double scale);
  void resize(size_t new_width, size_t new_height);
  void transpose();
  void rotateClockwise();
  void rotateCounterClockwise();
  void flipLR();
  void flipUD();
  void convertToGrayscale();
  void convertToRGB();
  void imshow(const std::string& window_name = std::string(),
              unsigned int wait_time = 1);
  ~Image();
private:
  std::shared_ptr<cv::Mat> image_;
}; 