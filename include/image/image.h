
// 
#pragma once 

#include <memory>
#include <string>

#include <Eigen/Dense>
#include <opencv2/core/core.hpp>
#include <opencv2/core/eigen.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Image {
public:
  Image():grayscale_(false);
  ~Image();

  Image(const Image& other);
  Image(size_t width, size_t height, size_t channels);
  Image(const std::string& filename, bool grayscale = false);

  explicit Image(const cv::Mat& other);

  template <typename T>
  inline T& at(size_t u, size_t v);

  template <typename T>
  const inline T& at(size_t u, size_t v) const;

  void toCV(cv::Mat& out) const;
  void fromCV(const cv::Mat& in);

  void toEigen(MatrixXf& eigen_out);
  void read(const std::string& filename, bool grayscale = false);
  void write(const std::string& filename) const;

  size_t width() const;
  size_t height() const;
  size_t cols() const { return Width(); }
  size_t rows() const { return Height(); }
  size_t channels() const;
  bool isColor() const { return !grayscale_; }
  void resize(double scale);
  void resize(size_t new_width, size_t new_height);
  void transpose();
  void rotateClockwise();
  void rotateCounterClockwise();
  void flipLR();
  void flipUD();
  void convertToGrayscale();
  void convertToRGB();
  void imShow(const std::string& window_name = std::string(),
              unsigned int wait_time = 0);
private:
  bool grayscale_;
  std::shared_ptr<cv::Mat> image_;
}; 






// Non-member conversion from OpenCV to Eigen matrices.
template <typename T>
inline void OpenCVToEigenMat(
    const cv::Mat& cv_mat,
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& eigen_mat);

// Non-member conversions from Eigen to OpenCV matrices.
template <typename T>
inline void EigenMatToOpenCV(
    const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& eigen_mat,
    cv::Mat& cv_mat);

// ------------------- Implementation ------------------- //

template <typename T>
T& Image::at(size_t u, size_t v) {
  CHECK_NOTNULL(image_.get());
  return image_->template at<T>(u, v);
}

template <typename T>
const T& Image::at(size_t u, size_t v) const {
  CHECK_NOTNULL(image_.get());
  return image_->template at<T>(u, v);
}

// Non-member conversion from OpenCV to Eigen matrices.
template <typename T>
void OpenCVToEigenMat(
    const cv::Mat& cv_mat,
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& eigen_mat) {

  // Make sure the data is grayscale and floating point before converting to an
  // eigen matrix.
  if (cv_mat.channels() != 1) {
    cv::Mat grayscale_mat;
    cv::cvtColor(cv_mat, grayscale_mat, CV_RGB2GRAY);
    cv::cv2eigen(grayscale_mat, eigen_mat);
  } else {
    cv::cv2eigen(cv_mat, eigen_mat);
  }
}

// Non-member conversion from Eigen to OpenCV matrices.
template <typename T>
void EigenMatToOpenCV(
    const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& eigen_mat,
    cv::Mat& cv_mat) {
  cv::eigen2cv(eigen_mat, cv_mat);
}
#endif
