#ifndef TINYURDF_JOINT_DYNAMICS_H
#define TINYURDF_JOINT_DYNAMICS_H

// Copyright 2025 Wissem CHIHA

#include "property_base.h"
#include <string>
#include <ostream>

class JointDynamics : public PropertyBase {
public:
    JointDynamics();
    bool isA(const char* name) override;
    void print(std::ostream& os) override;
    void clear() override;
    void setDamping(double d);
    void setFriction(double f);
    void setInertia(double i);
private:
    double damping, friction, inertia;
};
#endif // TINYURDF_JOINTDYNAMICS_H