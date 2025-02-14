#ifndef INCLUDE_TINYURDF_VISUAL_H_
#define INCLUDE_TINYURDF_VISUAL_H_

// Copyright 2025 Wissem CHIHA

#include <type_traits>
#include <memory>
#include "core/pose.h"
#include "core/material.h"
#include "common/geometry_base.h"
#include "common/property_base.h"

class Visual : public PropertyBase {
 public:
  Visual();
  void clear() override;
  bool isA(const char* name) const override;
  void setOrigin(std::shared_ptr<Pose> o);
  void getOrigin(double* xyz) const;
  std::shared_ptr<Pose> getPose() const;
  std::string toString() const override;
  bool empty() const;
  const char* getTypename();
  void setGeometry(std::shared_ptr<GeometryBase> geo);
  std::shared_ptr<GeometryBase> getGeometry() const;
  void setMaterial(std::shared_ptr<Material> mat);
  void setMaterialName(const std::string& name);
  ~Visual();
 private:
  std::shared_ptr<Pose> origin;
  std::shared_ptr<GeometryBase> geometry;
  std::string material_name;
  std::shared_ptr<Material> material;
};
#endif // INCLUDE_TINYURDF_VISUAL_H_