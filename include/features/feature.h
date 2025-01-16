#pragma once

#include <memory.h>

class Feature {
public:
  Feature() : u(0.0), v(0.0) {}
  Feature(double u, double v) : u(u), v(v) {}
  bool operator==(const Feature& rhs) const {
    return u == rhs.u && v == rhs.v;
  }
private:
  double u, v;
};  
