#ifndef TINYURDF_JOINTLIMITS_H
#define TINYURDF_JOINTLIMITS_H

// Copyright 2025 Wissem CHIHA

#include "property_base.h"
#include <ostream>
#include <string>

class JointLimits : public PropertyBase 
{
public:
    JointLimits();
    bool isA(const char* name) override;
    void print(std::ostream& os) override;
    void clear() override;
    void setEffort(double effort_);
    void setVelocity(double vel_);
private:
    double lower, upper, effort, velocity;
};
#endif // TINYURDF_JOINTLIMITS_H
