#ifndef INCLUDE_TINYURDF_GEOMETRY_CYLINDER_H_
#define INCLUDE_TINYURDF_GEOMETRY_CYLINDER_H_

// Copyright 2025 Wissem CHIHA

#include <ostream>
#include <string>

#include "geometry_base.h"

class Cylinder : public GeometryBase {
public:
  Cylinder();
  Cylinder(double r, double l);
  bool isA(const char* name) override;
  void print(std::ostream& os) override;
  void clear() override;
  bool empty() const override;
  const char* getTypename() override;
  void setOrigin(double x, double y, double z) override;
  void getOrigin(double* xyz) const override;
  void setLength(double l);
  void setRadius(double r);
  double getLength() override;
  double getRadius() override;
private:
  double length, radius;
};
#endif  // INCLUDE_TINYURDF_GEOMETRY_CYLINDER_H_
