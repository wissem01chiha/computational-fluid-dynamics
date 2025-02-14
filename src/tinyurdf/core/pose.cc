#include "core/pose.h"

Pose::Pose()
{
  position = Vec3::Zero();
  rotation = Rot3::Identity();
}

Pose::Pose(const Pose &rhs)
{
  this->position = rhs.position;
  this->rotation = rhs.rotation;
}

Pose &Pose::operator=(const Pose &rhs)
{
  if (this != &rhs) {
    PropertyBase::operator=(rhs);
    position = rhs.position;
    rotation = rhs.rotation;
  }
  return *this;
}

bool Pose::isA(const char *name) const
{
  return std::string(name) == "pose";
}

std::string Pose::toString() const
{
  std::ostringstream os;
  os << "pose xyz-xyzw = [" << position[0] << ", " << position[1] << ", " << position[2] 
  << ", " << rotation.coeffs()[0] <<  ", "<<  rotation.coeffs()[1] <<  ", " << 
  rotation.coeffs()[2] <<  ", " << rotation.coeffs()[3]  << "]";
  return os.str();
}

void Pose::clear()
{
  position.setZero();
  rotation = Rot3::Identity();
}

Vec3 Pose::getPosition()
{
  return position;
}

Rot3 Pose::getRotation()
{
  return rotation;
}

void Pose::setPosition(double x, double y, double z)
{
  this->position[0] =x; this->position[1] = y; this->position[2] =z;
}

void Pose::setRotation(double x, double y, double z, double w)
{
  this->rotation.coeffs()[0] = x;
  this->rotation.coeffs()[1] = y;
  this->rotation.coeffs()[2] = x;
  this->rotation.coeffs()[3] = w;
}

void Pose::setRotation(double r, double p, double y)
{
  this->rotation = Eigen::Quaternion<double>(
            Eigen::AngleAxis<double>(y, Eigen::Matrix<double, 3, 1>::UnitZ()) *
            Eigen::AngleAxis<double>(p, Eigen::Matrix<double, 3, 1>::UnitY()) *
            Eigen::AngleAxis<double>(r, Eigen::Matrix<double, 3, 1>::UnitX())
  );
}

Pose::~Pose()
{
  this->clear();
}
