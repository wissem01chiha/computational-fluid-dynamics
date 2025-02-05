#include "version.h"

Version::Version(){}

Version::Version(const char *attr)
{
  if (attr == nullptr)
  {
    major_ = 1;
    minor_ = 0; 
    return;
  }
  std::vector<std::string> split_vector;
  std::string delimiter = ".";
  split(std::string(attr), split_vector, delimiter );
  if (split_vector.size() == 2)
  {
    str2double(split_vector[0].c_str(), this->major_ );
    str2double(split_vector[1].c_str(), this->minor_ );
  }
  else
  {
    LOG_F(ERROR,"The version attribute should be in the form 'x.y'");
    LOG_F(WARNING, "defaulting to version '1.0' ");
    major_ = 1;
    minor_ = 0;
    return;
  }
  split_vector.clear();
  split_vector.shrink_to_fit();
}

Version::Version(const Version &rhs)
{
  this->minor_ = rhs.minor_;
  this->major_ = rhs.major_;
}

Version::~Version()
{
  this->clear();
}

Version &Version::operator=(const Version &rhs)
{
  if (this != &rhs) {
      PropertyBase::operator=(rhs);
      major_ = rhs.major_;
      minor_ = rhs.minor_;
  }
  return *this;
}

bool Version::isA(const char *name)
{
  return std::string(name)=="version";
}

void Version::clear()
{
  major_ =1; minor_ = 0;
}

void Version::print(std::ostream &os)
{
  os <<  "version: [" << major_  << ", " << minor_ << "]\n";
}

bool Version::equal(double maj, double min)
{
  return this->major_ == maj && this->minor_ == min;
}

double Version::getMajor() const
{
  return major_;
}

double Version::getMinor() const
{
  return minor_;
}