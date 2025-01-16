#include "../../include/common/camera_intrinsics.h"

CameraIntrinsics::CameraIntrinsics()
    : image_left_(0),
      image_top_(0),
      image_width_(0),
      image_height_(0),
      fu(0.0),
      fv(0.0),
      cu(0.0),
      cv(0.0),
      k1(0.0),
      k2(0.0),
      k3(0.0),
      k4(0.0),
      k5(0.0),
      horizontal_fov_(0.0),
      vertical_fov_(0.0) {}

CameraIntrinsics::CameraIntrinsics(const Eigen::Matrix3d &K, int image_width,
                                   int image_height)
    : image_left_(0),
      image_top_(0),
      image_width_(image_width),
      image_height_(image_height),
      fu(K(0, 0)),
      fv(K(1, 1)),
      cu(K(0, 2)),
      cv(K(1, 2)),
      k1(0.0),
      k2(0.0),
      k3(0.0),
      k4(0.0),
      k5(0.0) {
  horizontal_fov_ = 2.0 * atan2(0.5 * image_width_, fu);
  vertical_fov_ = 2.0 * atan2(0.5 * image_height_, fv);
}

CameraIntrinsics::CameraIntrinsics(int image_left, int image_top,
                                   int image_width, int image_height,
                                   double f_u, double f_v, double c_u,
                                   double c_v, double k1, double k2, double k3,
                                   double k4, double k5)
    : image_left_(image_left),
      image_top_(image_top),
      image_width_(image_width),
      image_height_(image_height),
      fu(f_u),
      fv(f_v),
      cu(c_u),
      cv(c_v),
      k1(k1),
      k2(k2),
      k3(k3),
      k4(k4),
      k5(k5) {
  horizontal_fov_ = 2.0 * atan2(0.5 * image_width_, fu);
  vertical_fov_ = 2.0 * atan2(0.5 * image_height_, fv);
}

void CameraIntrinsics::setImageLeft(int image_left) {
  image_left_ = image_left;
}

void CameraIntrinsics::setImageTop(int image_top) {
  image_top_ = image_top;
}

void CameraIntrinsics::setImageWidth(int image_width) {
  image_width_ = image_width;
  horizontal_fov_ = 2.0 * atan2(0.5 * image_width_, fu);
}

void CameraIntrinsics::setImageHeight(int image_height) {
  image_height_ = image_height;
  vertical_fov_ = 2.0 * atan2(0.5 * image_height_, fv);
}

void CameraIntrinsics::setFU(double f_u) {
  fu = f_u;
  horizontal_fov_ = 2.0 * atan2(0.5 * image_width_, fu);
}

void CameraIntrinsics::setFV(double f_v) {
  fv = f_v;
  vertical_fov_ = 2.0 * atan2(0.5 * image_height_, fv);
}

void CameraIntrinsics::setCU(double c_u) {
  cu= c_u;
}

void CameraIntrinsics::setCV(double c_v) {
  cv= c_v;
}

void CameraIntrinsics::setK(double k1, double k2, double k3, double k4,
                            double k5) {
  k1 = k1;
  k2 = k2;
  k3 = k3;
  k4 = k4;
  k5 = k5;
}

void CameraIntrinsics::setK1(double k1) {
  k1 = k1;
}

void CameraIntrinsics::setK2(double k2) {
  k2 = k2;
}

void CameraIntrinsics::setK3(double k3) {
  k3 = k3;
}

void CameraIntrinsics::setK4(double k4) {
  k4 = k4;
}

void CameraIntrinsics::setK5(double k5) {
  k5 = k5;
}

void CameraIntrinsics::setHorizontalFOV(double horizontal_fov) {
  horizontal_fov_ = horizontal_fov;
  fu = 0.5 * image_width_ / tan(0.5 * horizontal_fov_);
}

void CameraIntrinsics::setVerticalFOV(double vertical_fov) {
  vertical_fov_ = vertical_fov;
  fv = 0.5 * image_height_ / tan(0.5 * vertical_fov_);
}

int CameraIntrinsics::imageLeft() const {
  return image_left_;
}

int CameraIntrinsics::imageTop() const {
  return image_top_;
}

int CameraIntrinsics::imageWidth() const {
  return image_width_;
}

int CameraIntrinsics::imageHeight() const {
  return image_height_;
}

double CameraIntrinsics::getFU() const {
  return fu;
}

double CameraIntrinsics::getFV() const {
  return fv;
}

double CameraIntrinsics::getCU() const {
  return cu;
}

double CameraIntrinsics::getCV() const {
  return cv;
}

double CameraIntrinsics::getK1() const {
  return k1;
}

double CameraIntrinsics::getK2() const {
  return k2;
}

double CameraIntrinsics::getK3() const {
  return k3;
}

double CameraIntrinsics::getK4() const {
  return k4;
}

double CameraIntrinsics::getK5() const {
  return k5;
}

double CameraIntrinsics::getHorizontalFOV() const {
  return horizontal_fov_;
}

double CameraIntrinsics::getVerticalFOV() const {
  return vertical_fov_;
}

Eigen::Matrix3d CameraIntrinsics::K() const {
  Eigen::Matrix3d K;
  K << fu, 0.0, cu, 0.0, fv, cv, 0.0, 0.0, 1.0;

  return K;
}

Eigen::Matrix3d CameraIntrinsics::Kinv() const {
  return CameraIntrinsics::K().inverse();
}

bool CameraIntrinsics::pointInImage(double u, double v) const {
    const bool in_cols = u >= image_left_ && u < image_left_ + image_width_;
    const bool in_rows = v >= image_top_ && v < image_top_ + image_height_;

    return in_cols && in_rows;
}


bool CameraIntrinsics::cameraToImage(double cx, double cy, double cz,
                                     double *u_distorted,
                                     double *v_distorted) const {

  CHECK_NOTNULL(u_distorted);
  CHECK_NOTNULL(v_distorted);

  if (cz < 0.0) return false;

  const double u_normalized = cx / cz;
  const double v_normalized = cy / cz;

  return directionToImage(u_normalized, v_normalized, u_distorted, v_distorted);
}

bool CameraIntrinsics::directionToImage(double u_normalized,
                                        double v_normalized,
                                        double *u_distorted,
                                        double *v_distorted) const {
  CHECK_NOTNULL(u_distorted);
  CHECK_NOTNULL(v_distorted);

  double u = 0.0, v = 0.0;
  distort(u_normalized, v_normalized, &u, &v);
  Eigen::Vector3d p;
  p << u, v, 1.0;

  const Eigen::Vector3d p_out = CameraIntrinsics::K() * p;
  *u_distorted = p_out(0);
  *v_distorted = p_out(1);

  return pointInImage(*u_distorted, *v_distorted);
}

void CameraIntrinsics::imageToDirection(double u_distorted, double v_distorted,
                                        double *u_normalized,
                                        double *v_normalized) const {
  CHECK_NOTNULL(u_normalized);
  CHECK_NOTNULL(v_normalized);

  Eigen::Vector3d p_distorted;
  p_distorted << u_distorted, v_distorted, 1.0;

  const Eigen::Vector3d p = CameraIntrinsics::Kinv() * p_distorted;

  undistort(p(0), p(1), u_normalized, v_normalized);
}

void CameraIntrinsics::distort(double u, double v, double *u_distorted,
                               double *v_distorted) const {

  CHECK_NOTNULL(u_distorted);
  CHECK_NOTNULL(v_distorted);

  const double r_sq = u * u + v * v;
  const double radial_dist =
      1.0 + k1 * r_sq + k2 * r_sq * r_sq + k5 * r_sq * r_sq * r_sq;

  if (radial_dist < 0.85 || radial_dist > 1.15) {

    const double radius = hypot(image_width_, image_height_);
    *u_distorted = u / sqrt(r_sq) * radius;
    *v_distorted = v / sqrt(r_sq) * radius;
  } else {
    const double dx0 = 2.0 * k3 * u * v + k4 * (r_sq + 2.0 * u * u);
    const double dx1 = k3 * (r_sq + 2.0 * v * v) + 2.0 * k4 * u * v;

    *u_distorted = radial_dist * u + dx0;
    *v_distorted = radial_dist * v + dx1;
  }
}

void CameraIntrinsics::undistort(double u_distorted, double v_distorted,
                                 double *u, double *v, int iterations) const {

  CHECK_NOTNULL(u);
  CHECK_NOTNULL(v);

  double u_refine = u_distorted;
  double v_refine = v_distorted;
  for (int i = 0; i < iterations; ++i) {
    const double r_sq = u_refine * u_refine + v_refine * v_refine;
    const double dx0 = 2.0 * k3 * u_refine * v_refine +
                       k4 * (r_sq + 2.0 * u_refine * u_refine);
    const double dx1 = k3 * (r_sq + 2.0 * v_refine * v_refine) +
                       2.0 * k4 * u_refine * v_refine;
    u_refine = u_distorted - dx0;
    v_refine = v_distorted - dx1;
  }

  *u = u_refine;
  *v = v_refine;
}