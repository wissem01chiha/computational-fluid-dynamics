#ifndef INCLUDE_TINYURDF_COLLISION_H_
#define INCLUDE_TINYURDF_COLLISION_H_

// Copyright 2025 Wissem CHIHA

#include <memory>

#include "property_base.h"
#include "geometry_base.h"
#include "pose.h"

class Collision : public PropertyBase 
{
public:
    Collision();
    bool isA(const char* name) override;
    void clear() override;
    void print(std::ostream& os) override;
    void setGeometry(std::shared_ptr<GeometryBase> geometry);
    std::shared_ptr<GeometryBase> getGeometry() const;
    void setOrigin(std::shared_ptr<Pose> o_);
    void getOrigin(double* xyz) const;
private:
    std::shared_ptr<GeometryBase> geometry;
    std::shared_ptr<Pose> origin;
};

#endif // TINYURDF_COLLISION_H