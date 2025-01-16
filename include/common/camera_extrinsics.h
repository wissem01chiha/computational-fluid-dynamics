#pragma once

#include <glog/logging.h>
#include <eigen3/Eigen/Core>
#include "../geometry/pose.h"
#include "../util/types.h"

class CameraExtrinsics { 
public:
  CameraExtrinsics();
  CameraExtrinsics(const Pose& world_to_camera);
  void setWorldToCamera(const Pose& world_to_camera);
  Pose worldToCamera() const;
  Pose cameraToWorld() const;
  void setRotation(const Eigen::Matrix3d& rotation);
  void setRotation(double phi, double theta, double psi);
  void rotate(const Eigen::Matrix3d& delta);
  void rotate(double dphi, double dtheta, double dpsi);
  Eigen::Matrix3d rotation() const;
  void setTranslation(const Eigen::Vector3d& translation);
  void setTranslation(double wx, double wy, double wz);
  void translate(const Eigen::Vector3d& delta);
  void translate(double dx, double dy, double dz);
  void translateX(double dx);
  void translateY(double dy);
  void translateZ(double dz);
  Eigen::Vector3d translation() const;
  Matrix34d Rt() const;
  void worldToCamera(double wx, double wy, double wz,
                     double* cx, double* cy, double* cz) const;
  void cameraToWorld(double cx, double cy, double cz,
                     double* wx, double* wy, double* wz) const;
  ~CameraExtrinsics();
private:
  Pose world_to_camera_;
}; 
