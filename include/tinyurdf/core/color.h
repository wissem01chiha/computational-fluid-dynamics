#ifndef INCLUDE_TINYURDF_CORE_COLOR_H_
#define INCLUDE_TINYURDF_CORE_COLOR_H_

// Copyright 2025 Wissem CHIHA

#include "common/property_base.h"
#include <loguru/loguru.hpp>

class Color : public PropertyBase{
 public:
  enum class Type
  {
    Red,
    Green,
    Blue,
    Black,
    White,
    Yellow,
    Cyan,
    Magenta
  };
  Color();
  Color& operator=(const Color& rhs);
  Color(const double& r_,const  double& g_,const double& b_,const double& a_);
  Color(const double* rgba);
  Color(const std::string &vector_str);
  Color(const Type type_);
  bool isA(const char* name) const override;
  void clear() override;
  std::string toString() const override;
  void set(double&r, double& g, double& b, double& a);
  ~Color();
  double getR() const;
  double getG() const;
  double getB() const;
  double getA() const;
  private:
    double r, g, b, a;
};
#endif // TINYURDF_COLOR_H_