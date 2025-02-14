#ifndef INCLUDE_TINYURDF_CORE_JOINT_SAFETY_H_
#define INCLUDE_TINYURDF_CORE_JOINT_SAFETY_H_

// Copyright 2025 Wissem CHIHA

#include "common/property_base.h"

class JointSafety : public PropertyBase{
 public:
    JointSafety();
    bool isA(const char* name) const override;
    std::string toString() const override;
    void clear() override;
    void setSoftUpperLimit(double value);
    void setSoftLowerLimit(double value);
    void setKPosition(double value);
    void setKVelocity(double value);
 private:
    double soft_upper_limit, soft_lower_limit;
    double k_position, k_velocity;
};
#endif // INCLUDE_TINYURDF_CORE_JOINTSAFETY_H