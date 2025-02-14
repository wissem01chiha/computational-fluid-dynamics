#ifndef INCLUDE_TINYURDF_CORE_COLLISION_H_
#define INCLUDE_TINYURDF_CORE_COLLISION_H_

// Copyright 2025 Wissem CHIHA

#include <memory>
#include "common/property_base.h"
#include "common/geometry_base.h"
#include "core/pose.h"

class Collision : public PropertyBase {
 public:
    Collision();
    bool isA(const char* name) const override;
    void clear() override;
    std::string toString() const override;
    void setGeometry(std::shared_ptr<GeometryBase> geometry);
    std::shared_ptr<GeometryBase> getGeometry() const;
    void setOrigin(std::shared_ptr<Pose> o_);
    void getOrigin(double* xyz) const;
 private:
    std::shared_ptr<GeometryBase> geometry;
    std::shared_ptr<Pose> origin;
};
#endif // TINYURDF_COLLISION_H_