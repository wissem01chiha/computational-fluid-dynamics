#pragma once

#include <string>
#include <eigen3/Eigen/Core>

class Covariance3D {
public:
  Covariance3D();
  Covariance3D(double x11, double x12, double x13,
               double x21, double x22, double x23,
               double x31, double x32, double x33);
  Covariance3D(const Covariance3D& in);
  Covariance3D(const Eigen::Matrix3d& in);
  static Covariance3D zero();
  static Covariance3D identity();
  void set(const Covariance3D& in);
  void set(const Eigen::Matrix3d& in);
  double& operator()(int row, int col);
  const double& operator()(int row, int col) const;
  const Eigen::Matrix3d& get() const;
  void print(const std::string& prefix = std::string()) const;
  ~Covariance3D();
private:
  Eigen::Matrix3d data_;
};  
