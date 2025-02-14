#ifndef INCLUDE_TINYURDF_CORE_JOINT_DYNAMICS_H
#define INCLUDE_TINYURDF_CORE_JOINT_DYNAMICS_H

// Copyright 2025 Wissem CHIHA

#include "common/property_base.h"
#include <string>

class JointDynamics : public PropertyBase {
 public:
   JointDynamics();
   bool isA(const char* name) const override;
   std::string toString() const override;
   void clear() override;
   void setDamping(double d);
   void setFriction(double f);
   void setInertia(double i);
 private:
   double damping, friction, inertia;
};
#endif // INCLUDE_TINYURDF_CORE_JOINT_DYNAMICS_H