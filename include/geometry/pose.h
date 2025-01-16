#pragma once

#include <ostream>
#include <iostream>
#include <eigen3/Eigen/Dense>
#include "../util/types.h"

class Pose {
public:
  Pose();
  Pose(const Eigen::Matrix3d& R, const Eigen::Vector3d& t);
  Pose(const Matrix34d& Rt);
  Pose(const Pose& other);
  Pose(const Eigen::Matrix4d& other);
  double& operator()(int i, int j);
  const double& operator()(int i, int j) const;
  Eigen::Matrix4d& get();
  const Eigen::Matrix4d& get() const;
  Eigen::Matrix3d rotation() const;
  Eigen::Vector3d translation() const;
  void set(const Eigen::Matrix4d& transformation);
  void set(const Matrix34d& Rt);
  void setRotation(const Eigen::Matrix3d& rotation);
  void setTranslation(const Eigen::Vector3d& translation);
  Pose operator*(const Pose& other) const;
  Eigen::Vector4d project(const Eigen::Vector4d&);
  Eigen::Vector2d projectTo2D(const Eigen::Vector3d&);
  bool isApprox(const Pose&) const;
  void compose(const Pose& other);
  Pose inverse() const;
  Matrix34d dehomogenize();
  Eigen::Vector3d axisAngle() const;
  Eigen::Matrix4d fromAxisAngle(const Eigen::Vector3d& aa);
  void setX(double x);
  void setY(double y);
  void setZ(double z);
  const double& getX() const;
  const double& getY() const;
  const double& getZ() const;
  void translateX(double dx);
  void translateY(double dy);
  void translateZ(double dz);
  Pose delta(const Pose& rhs) const;
  void print(std::ostream os) const;
  ~Pose();
private:
  Eigen::Matrix4d Rt_;  
}; 