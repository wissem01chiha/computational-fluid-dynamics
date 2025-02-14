#ifndef INCLUDE_TINYURDF_CORE_JOINT_MIMIC_H
#define INCLUDE_TINYURDF_CORE_JOINT_MIMIC_H

// Copyright 2025 Wissem CHIHA

#include "common/property_base.h"

class JointMimic : public PropertyBase {
 public:
    JointMimic();
    bool isA(const char* name) const override;
    std::string toString() const override;
    void clear() override;
    void setOffset(double o);
    void setMultiplier(double m);
    void setName(std::string& n_);
 private:
    double offset, multiplier;
    std::string name;
};
#endif // INCLUDE_TINYURDF_CORE_JOINT_MIMIC_H_
