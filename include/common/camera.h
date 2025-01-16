#pragma once 

#include <memory>
#include "camera_extrinsics.h"
#include "camera_intrinsics.h"

class Camera {
public:
  Camera();
  Camera(CameraExtrinsics, CameraIntrinsics);
  void setExtrinsics(const CameraExtrinsics&);
  void setIntrinsics(const CameraIntrinsics&);
  const CameraExtrinsics& getExtrinsics() const;
  const CameraIntrinsics& getIntrinsics() const;
  Matrix34d P() const;
  Eigen::Matrix3d K() const;
  Matrix34d Rt() const;
  Eigen::Vector3d translation() const;
  Eigen::Matrix3d rotation() const;
  Eigen::Vector3d axisAngleRotation() const;
  void worldToCamera(double wx, double wy, double wz, double* cx, double* cy,
                  double* cz) const;
  void cameraToWorld(double cx, double cy, double cz,
                    double* wx, double* wy, double* wz) const;
  bool cameraToImage(double cx, double cy, double cz,
                    double* u_distorted, double* v_distorted) const;
  bool worldToImage(double wx, double wy, double wz,
                  double* u_distorted, double* v_distorted) const;
  bool directionToImage(double u_normalized, double v_normalized,
                      double* u_distorted, double* v_distorted) const;
  void imageToDirection(double u_distorted, double v_distorted,
                      double* u_normalized, double* v_normalized) const;
  void distort(double u, double v,double* u_distorted, double* v_distorted) const;
  void undistort(double u_distorted, double v_distorted, double* u, double* v) const;
  ~Camera();
private:
  std::shared_ptr<CameraExtrinsics> extrinsics_;
  std::shared_ptr<CameraIntrinsics> intrinsics_;
};  
