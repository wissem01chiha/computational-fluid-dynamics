#include "../../include/common/camera_extrinsics.h"

CameraExtrinsics::CameraExtrinsics() {
  world_to_camera_ = Pose();
}

CameraExtrinsics::CameraExtrinsics(const Pose& world_to_camera)
    : world_to_camera_(world_to_camera) {}

void CameraExtrinsics::setWorldToCamera(const Pose& world_to_camera) {
  world_to_camera_ = world_to_camera;
}

Pose CameraExtrinsics::worldToCamera() const {
  return world_to_camera_;
}

Pose CameraExtrinsics::cameraToWorld() const {
  return CameraExtrinsics::worldToCamera().inverse();
}

void CameraExtrinsics::setRotation(const Eigen::Matrix3d& rotation) {
  const Eigen::Vector3d t = world_to_camera_.translation();
  const Eigen::Matrix3d R = world_to_camera_.rotation();
  const Eigen::Vector3d c = -R.transpose() * t;

  world_to_camera_.setRotation(rotation);
  world_to_camera_.setTranslation(-rotation * c);
}

void CameraExtrinsics::setRotation(double phi, double theta, double psi) {
  
}

void CameraExtrinsics::rotate(const Eigen::Matrix3d& delta) {
  const Eigen::Matrix3d R = world_to_camera_.rotation();
  setRotation(delta * R);
}

void CameraExtrinsics::rotate(double dphi, double dtheta, double dpsi) {
  
}

Eigen::Matrix3d CameraExtrinsics::rotation() const {
  return world_to_camera_.rotation();
}

void CameraExtrinsics::setTranslation(const Eigen::Vector3d& translation) {
  const Eigen::Matrix3d R = world_to_camera_.rotation();
  world_to_camera_.setTranslation(-R * translation);
}

void CameraExtrinsics::setTranslation(double x, double y, double z) {
  setTranslation(Eigen::Vector3d(x, y, z));
}

void CameraExtrinsics::translate(const Eigen::Vector3d& delta) {
  const Eigen::Vector3d t = world_to_camera_.translation();
  const Eigen::Matrix3d R = world_to_camera_.rotation();
  Eigen::Vector3d c = -R.transpose() * t;

  c += delta;
  world_to_camera_.setTranslation(-R*c);
}

void CameraExtrinsics::translate(double dx, double dy, double dz) {
  translate(Eigen::Vector3d(dx, dy, dz));
}

void CameraExtrinsics::translateX(double dx) {
  translate(Eigen::Vector3d(dx, 0, 0));
}

void CameraExtrinsics::translateY(double dy) {
  translate(Eigen::Vector3d(0, dy, 0));
}

void CameraExtrinsics::translateZ(double dz) {
  translate(Eigen::Vector3d(0, 0, dz));
}

Eigen::Vector3d CameraExtrinsics::translation() const {
  const Eigen::Vector3d t = world_to_camera_.translation();
  const Eigen::Matrix3d R = world_to_camera_.rotation();
  return -R.transpose() * t;
}

Matrix34d CameraExtrinsics::Rt() const {
  return worldToCamera().dehomogenize();
}

void CameraExtrinsics::worldToCamera(double wx, double wy, double wz,
                                     double* cx, double* cy, double* cz) const {
  CHECK_NOTNULL(cx);
  CHECK_NOTNULL(cy);
  CHECK_NOTNULL(cz);

  const Eigen::Vector4d w_h(wx, wy, wz, 1.0);
  const Eigen::Vector4d c_h = CameraExtrinsics::worldToCamera().project(w_h);

  *cx = c_h(0);
  *cy = c_h(1);
  *cz = c_h(2);
}

void CameraExtrinsics::cameraToWorld(double cx, double cy, double cz,
                                     double* wx, double* wy, double* wz) const {
  CHECK_NOTNULL(wx);
  CHECK_NOTNULL(wy);
  CHECK_NOTNULL(wz);

  const Eigen::Vector4d c_h(cx, cy, cz, 1.0);
  const Eigen::Vector4d w_h = CameraExtrinsics::cameraToWorld().project(c_h);

  *wx = w_h(0);
  *wy = w_h(1);
  *wz = w_h(2);
}
CameraExtrinsics::~CameraExtrinsics(){}