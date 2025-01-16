#include "../../include/common/camera.h"

Camera::Camera(CameraExtrinsics extrinsics, CameraIntrinsics intrinsics){

  extrinsics_ = std::make_shared<CameraExtrinsics>(extrinsics);
  intrinsics_ = std::make_shared<CameraIntrinsics>(intrinsics);
}

void Camera::setExtrinsics(const CameraExtrinsics &extrinsics) {
  *extrinsics_ = extrinsics;
}

void Camera::setIntrinsics(const CameraIntrinsics &intrinsics) {
  *intrinsics_ = intrinsics;
}

Matrix34d Camera::P() const {
  return intrinsics_->K() * extrinsics_->Rt();
}

Eigen::Matrix3d Camera::K() const {
  return intrinsics_->K();
}

Matrix34d Camera::Rt() const {
  return extrinsics_->Rt();
}

Eigen::Vector3d Camera::translation() const {
  return extrinsics_->translation();
}

Eigen::Matrix3d Camera::rotation() const {
  return extrinsics_->rotation();
}

Eigen::Vector3d Camera::axisAngleRotation() const {
  return extrinsics_->worldToCamera().axisAngle();
}

void Camera::worldToCamera(double wx, double wy, double wz, double *cx,
                           double *cy, double *cz) const {
  extrinsics_->worldToCamera(wx, wy, wz, cx, cy, cz);
}

void Camera::cameraToWorld(double cx, double cy, double cz, double *wx,
                           double *wy, double *wz) const {
  extrinsics_->cameraToWorld(cx, cy, cz, wx, wy, wz);
}

bool Camera::cameraToImage(double cx, double cy, double cz, double *u_distorted,
                           double *v_distorted) const {
  return intrinsics_->cameraToImage(cx, cy, cz, u_distorted, v_distorted);
}

bool Camera::worldToImage(double wx, double wy, double wz, double *u_distorted,
                          double *v_distorted) const {
  double cx = 0.0, cy = 0.0, cz = 0.0;
  worldToCamera(wx, wy, wz, &cx, &cy, &cz);
  return cameraToImage(cx, cy, cz, u_distorted, v_distorted);
}

bool Camera::directionToImage(double u_normalized, double v_normalized,
                              double *u_distorted, double *v_distorted) const {
  return intrinsics_->directionToImage(u_normalized, v_normalized, u_distorted,
                                      v_distorted);
}

void Camera::imageToDirection(double u_distorted, double v_distorted,
                              double *u_normalized,
                              double *v_normalized) const {
  intrinsics_->imageToDirection(u_distorted, v_distorted, u_normalized,
                               v_normalized);
}

void Camera::distort(double u, double v, double *u_distorted,
                     double *v_distorted) const {
  intrinsics_->distort(u, v, u_distorted, v_distorted);
}

void Camera::undistort(double u_distorted, double v_distorted, double *u,
                       double *v) const {
  intrinsics_->undistort(u_distorted, v_distorted, u, v);
}
