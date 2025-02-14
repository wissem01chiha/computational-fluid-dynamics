#ifndef INCLUDE_TINYURDF_CORE_JOINT_LIMITS_H
#define INCLUDE_TINYURDF_CORE_JOINT_LIMITS_H

// Copyright 2025 Wissem CHIHA

#include "common/property_base.h"

class JointLimits : public PropertyBase {
 public:
    JointLimits();
    bool isA(const char* name) const override;
    std::string toString() const override;
    void clear() override;
    void setEffort(double effort_);
    void setVelocity(double vel_);
 private:
    double lower, upper, effort, velocity;
};
#endif // INCLUDE_TINYURDF_CORE_JOINT_LIMITS_H_