#include "../../include/image/image.h"

template <typename T>
inline void openCVToEigenMat(
    const cv::Mat& cv_mat,
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& eigen_mat);


template <typename T>
inline void EigenMatToOpenCV(
    const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& eigen_mat,
    cv::Mat& cv_mat);


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

template <typename T>
void OpenCVToEigenMat(
    const cv::Mat& cv_mat,
    Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& eigen_mat) {

  if (cv_mat.channels() != 1) {
    cv::Mat grayscale_mat;
    cv::cvtColor(cv_mat, grayscale_mat, CV_RGB2GRAY);
    cv::cv2eigen(grayscale_mat, eigen_mat);
  } else {
    cv::cv2eigen(cv_mat, eigen_mat);
  }
}

template <typename T>
void EigenMatToOpenCV(
    const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& eigen_mat,
    cv::Mat& cv_mat) {
  cv::eigen2cv(eigen_mat, cv_mat);
}

