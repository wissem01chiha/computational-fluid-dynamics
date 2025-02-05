#ifndef INCLUDE_TINYURDF_VISUAL_H_
#define INCLUDE_TINYURDF_VISUAL_H_

// Copyright 2025 Wissem CHIHA

#include <type_traits>
#include <memory>

#include "pose.h"
#include "material.h"
#include "geometry_base.h"
#include "property_base.h"

class Visual : public PropertyBase {
public:
  Visual();
  void clear() override;
  bool isA(const char* name) override;
  void setOrigin(std::shared_ptr<Pose> o);
  void getOrigin(double* xyz) const;
  std::shared_ptr<Pose> getPose() const;
  void print(std::ostream& os) override;
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