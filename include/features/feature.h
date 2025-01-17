#pragma once

#include <cmath>  
#include <iostream> 

class Feature {
public:
  Feature() : u(0.0), v(0.0) {}
  Feature(double u, double v) : u(u), v(v) {}
  virtual ~Feature() = default;
  double getU() const { return u; }
  double getV() const { return v; }
  void setU(double u_) { u = u_; }
  void setV(double v_) { v = v_; }
  bool operator==(const Feature& rhs) const {
      constexpr double EPSILON = 1e-9;
      return std::fabs(u - rhs.u) < EPSILON && std::fabs(v - rhs.v) < EPSILON;
  }
  virtual double distanceTo(const Feature& other) const {
      return std::sqrt((u - other.u) * (u - other.u) + (v - other.v) * (v - other.v));
  }
  virtual void print() const {
    std::cout << "Feature(u: " << u << ", v: " << v << ")\n";
  }
private:
  double u, v;
};
