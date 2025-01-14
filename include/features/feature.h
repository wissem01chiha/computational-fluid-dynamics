#pragma once

class Feature {
public:
  Feature() : u_(0.0), v_(0.0) {}
  Feature(double u, double v) : u_(u), v_(v) {}
  bool operator==(const Feature& rhs) const {
    return u_ == rhs.u_ && v_ == rhs.v_;
  }
private:
  double u_, v_;
};  
