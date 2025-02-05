#ifndef INCLUDE_TINYURDF_GEOMETRY_BOX_H_
#define INCLUDE_TINYURDF_GEOMETRY_BOX_H_

// Copyright 2025 Wissem CHIHA

#include <string>
#include <ostream>

#include "utils.h"
#include "geometry_base.h"

class Box : public GeometryBase{
public:
  Box();
  explicit Box(double* xyz);
  Box(double x, double y, double z);
  bool isA(const char* name) override;
  const char* getTypename() override;
  bool empty() const override;
  void print(std::ostream& os)  override;
  void setOrigin(double x, double y, double z) override;
  void getOrigin(double* xyz) const override;
  Vec3 getDim() const;
  void clear() override;
  ~Box();
 private:
  Vec3 dim;
};
#endif  // INCLUDE_TINYURDF_GEOMETRY_BOX_H_
