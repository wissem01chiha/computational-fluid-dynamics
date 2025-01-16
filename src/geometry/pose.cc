#include "../../include/geometry/pose.h"
#include <ostream>

Pose::Pose() {
  Rt_ = Eigen::Matrix4d::Identity();
}

Pose::Pose(const Eigen::Matrix3d& R, const Eigen::Vector3d& t) {
  Rt_ = Eigen::Matrix4d::Identity();
  Rt_.block(0, 0, 3, 3) = R;
  Rt_.col(3).head(3) = t;
}

Pose::Pose(const Matrix34d& Rt) {
  Rt_ = Eigen::Matrix4d::Identity();
  Rt_.block(0, 0, 3, 4) = Rt;
}

Pose::Pose(const Eigen::Matrix4d& Rt) {
  Rt_ << Rt;
}

Pose::Pose(const Pose& other) {
  Rt_ << other.Rt_;
}

double& Pose::operator()(int i, int j) {
  return Rt_(i, j);
}

const double& Pose::operator()(int i, int j) const {
  return Rt_(i, j);
}

Eigen::Matrix4d& Pose::get() {
  return Rt_;
}

const Eigen::Matrix4d& Pose::get() const {
  return Rt_;
}

Eigen::Matrix3d Pose::rotation() const {
  return Rt_.block(0, 0, 3, 3);
}

Eigen::Vector3d Pose::translation() const {
  return Rt_.block(0, 3, 3, 1);
}

void Pose::set(const Eigen::Matrix4d& transformation) {
  Rt_ = transformation;
}

void Pose::set(const Matrix34d& Rt) {
  Rt_.block(0, 0, 3, 4) = Rt;
}

void Pose::setRotation(const Eigen::Matrix3d& rotation) {
  Rt_.block(0, 0, 3, 3) = rotation;
}

void Pose::setTranslation(const Eigen::Vector3d& translation) {
  Rt_.block(0, 3, 3, 1) = translation;
}

Pose Pose::operator*(const Pose& other) const {
  Eigen::Matrix4d Rt_out = Rt_ * other.Rt_;
  return Pose(Rt_out);
}

Eigen::Vector4d Pose::project(const Eigen::Vector4d& pt3d) {
  Eigen::Vector4d proj = Rt_ * pt3d;
  return proj;
}

Eigen::Vector2d Pose::projectTo2D(const Eigen::Vector3d& pt3d) {
  Eigen::Vector4d pt3d_h = Eigen::Vector4d::Constant(1.0);
  pt3d_h.head(3) = pt3d;

  const Eigen::Vector4d proj_h = Rt_ * pt3d_h;
  Eigen::Vector2d proj = proj_h.head(2);
  proj /= proj_h(2);

  return proj;
}

bool Pose::isApprox(const Pose& other) const {
  return Rt_.isApprox(other.Rt_);
}

void Pose::compose(const Pose& other) {
  Rt_ *= other.Rt_;
}

Pose Pose::inverse() const {
  Eigen::Matrix4d Rt_inverse = Rt_.inverse();
  Pose out(Rt_inverse);
  return out;
}

Matrix34d Pose::dehomogenize() {
  return Rt_.block(0, 0, 3, 4);
}

Eigen::Vector3d Pose::axisAngle() const {
  
  const double angle = acos(0.5 * (Rt_.trace() - 2.0));
  Eigen::Vector3d axis = Eigen::Vector3d(Rt_(2, 1) - Rt_(1, 2),
					                 Rt_(0, 2) - Rt_(2, 0),
					                 Rt_(1, 0) - Rt_(0, 1));

  if (axis.isApprox(Eigen::Vector3d::Zero(), 1e-16)) {
    return axis;
  }
  axis /= axis.norm();
  return axis * angle;
}

Eigen::Matrix4d Pose::fromAxisAngle(const Eigen::Vector3d& aa) {

  double angle = aa.norm();
  Eigen::Vector3d axis = aa / angle;

  Eigen::Matrix3d cross;
  cross <<
    0.0, -axis(2), axis(1),
    axis(2), 0.0, -axis(0),
    -axis(1), axis(0), 0.0;

  Eigen::Matrix3d tensor;
  tensor <<
    axis(0)*axis(0), axis(0)*axis(1), axis(0)*axis(2),
    axis(0)*axis(1), axis(1)*axis(1), axis(1)*axis(2),
    axis(0)*axis(2), axis(1)*axis(2), axis(2)*axis(2);

  Eigen::Matrix3d R =
    cos(angle) * Eigen::Matrix3d::Identity() +
    sin(angle) * cross + (1-cos(angle)) * tensor;
  Rt_.block(0, 0, 3, 3) = R;

  return Rt_;
}

void Pose::setX(double x) {
  Rt_(0, 3) = x;
}

void Pose::setY(double y) {
  Rt_(1, 3) = y;
}

void Pose::setZ(double z) {
  Rt_(2, 3) = z;
}

const double& Pose::getX() const {
  return Rt_(0, 3);
}

const double& Pose::getY() const {
  return Rt_(1, 3);
}

const double& Pose::getZ() const {
  return Rt_(2, 3);
}

void Pose::translateX(double dx) {
  Rt_(0, 3) += dx;
}

void Pose::translateY(double dy) {
  Rt_(1, 3) += dy;
}

void Pose::translateZ(double dz) {
  Rt_(2, 3) += dz;
}

void Pose::print(std::ostream os) const {
  
  os << Rt_;
}

Pose Pose::delta(const Pose& rhs) const {
  return this->inverse() * rhs;
}

Pose::~Pose(){}