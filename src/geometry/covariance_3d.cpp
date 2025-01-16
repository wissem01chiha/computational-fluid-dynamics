
#include "covariance_3d.h"


Covariance3D::Covariance3D() : data_(Matrix3d::Identity()) {}

// Element-wise constructor.
Covariance3D::Covariance3D(double x11, double x12, double x13,
                           double x21, double x22, double x23,
                           double x31, double x32, double x33) {
  data_(0, 0) = x11;
  data_(0, 1) = x12;
  data_(0, 2) = x13;
  data_(1, 0) = x21;
  data_(1, 1) = x22;
  data_(1, 2) = x23;
  data_(2, 0) = x31;
  data_(2, 1) = x32;
  data_(2, 1) = x33;
}

Covariance3D::Covariance3D(const Covariance3D& in) : data_(in.Get()) {}

Covariance3D::Covariance3D(const Matrix3d& in) : data_(in) {}

// Static zero.
Covariance3D Covariance3D::Zero() {
  return Covariance3D(Matrix3d::Zero());
}

// Static identity.
Covariance3D Covariance3D::Identity() {
  return Covariance3D(Matrix3d::Identity());
}

// Default destructor.
Covariance3D::~Covariance3D() {}

// Setters.
void Covariance3D::Set(const Covariance3D& in) {
  data_ = in.Get();
}

void Covariance3D::Set(const Matrix3d& in) {
  data_ = in;
}

// Getters.
double& Covariance3D::operator()(int row, int col) {
  // No bound-checking. Be careful!
  return data_(row, col);
}

const double& Covariance3D::operator()(int row, int col) const {
  // No bound-checking. Be careful!
  return data_(row, col);
}

const Matrix3d& Covariance3D::Get() const {
  return data_;
}

// Utility.
void Covariance3D::Print(const std::string& prefix) const {
  if (!prefix.empty()) {
    std::cout << prefix << std::endl;
  }

  std::cout << data_ << std::endl;
}

}  //\namespace bsfm
