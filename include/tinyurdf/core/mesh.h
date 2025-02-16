#ifndef INCLUDE_TINYURDF_CORE_MESH_H_
#define INCLUDE_TINYURDF_CORE_MESH_H_

// Copyright 2025 Wissem CHIHA

#include <string>
#include <loguru/loguru.hpp>
#include "common/geometry_base.h"
#include "core/color.h"
#include "utility/utils.h"

class Mesh final : public GeometryBase {
 public:
  Mesh();
  ~Mesh();
  bool isA(const char* name) const override;
  void clear() override;
  void setFilename(const std::string& path);
  std::string getFilename() override;
  void setScale(double xs, double ys, double zs);
  Vec3 getScale() override;
  void setColor(Color c);
  void setColor(double r, double g, double b, double a = 1.0);
  std::string toString() const override;
  void setOrigin(double x, double y, double z) override;
  void getOrigin(double* xyz) const override;
  bool empty() const override;
  const char* getTypename() const override;
 private:
  std::string filename;
  Vec3 scale;
  Color color;
};
#endif  // INCLUDE_TINYURDF_CORE_GEOMETRY_MESH_H_
