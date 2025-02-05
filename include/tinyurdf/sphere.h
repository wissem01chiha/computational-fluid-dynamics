#ifndef INCLUDE_TINYURDF_GEOMETRY_SPHERE_H_
#define INCLUDE_TINYURDF_GEOMETRY_SPHERE_H_

// Copyright 2025 Wissem CHIHA

#include <string>
#include <ostream>
#include <loguru/loguru.hpp>
#include "geometry_base.h"

class Sphere : public GeometryBase {
 public:
  Sphere();
  Sphere(double r);
  bool isA(const char* name) override;
  void print(std::ostream& os) override;
  void clear() override;
  const char* getTypename() override;
  double getRadius() const;
  void setRadius(double r);
  void setOrigin(double x, double y, double z) override;
  void getOrigin(double* xyz) const override;
  double getRadius() override;
  bool empty() const override;

 private:
  double radius;
};

#endif  // INCLUDE_TINYURDF_GEOMETRY_SPHERE_H_
