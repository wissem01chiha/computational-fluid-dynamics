#ifndef INCLUDE_TINYURDF_COMMON_GEOMETRY_BASE_H_
#define INCLUDE_TINYURDF_COMMON_GEOMETRY_BASE_H_

// Copyright 2025 Wissem CHIHA

#include "common/object_base.h"
#include "utility/utils.h"

/**
 * @brief base class for all geometry entities 
 */
class GeometryBase : public ObjectBase {
 public:
  virtual ~GeometryBase() = default;
  virtual void setOrigin(double x, double y, double z) = 0;
  virtual void getOrigin(double* xyz) const = 0;
  virtual double getRadius(){return 0;};
  virtual double getLength(){return 0;};
  virtual std::string getFilename(){return std::string("");};
  virtual Vec3 getScale(){return Vec3(0,0,0);};
 protected:
  GeometryBase(){};
};
#endif  // INCLUDE_TINYURDF_COMMON_GEOMETRY_BASE_H_
