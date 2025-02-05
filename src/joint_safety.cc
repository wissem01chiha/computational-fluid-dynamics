#include "joint_safety.h"

JointSafety::JointSafety()
    : soft_upper_limit(0.0),
      soft_lower_limit(0.0),
      k_position(0.0),
      k_velocity(0.0) {}

bool JointSafety::isA(const char* name) {
    return std::string(name) == "safety";
}

void JointSafety::print(std::ostream& os) {
    os << "Safety: [soft_upper_limit=" << soft_upper_limit
       << ", soft_lower_limit=" << soft_lower_limit
       << ", k_position=" << k_position
       << ", k_velocity=" << k_velocity
       << "]";
}

void JointSafety::clear() {
    soft_upper_limit = 0.0;
    soft_lower_limit = 0.0;
    k_position = 0.0;
    k_velocity = 0.0;
}

void JointSafety::setSoftUpperLimit(double value) { soft_upper_limit = value; }

void JointSafety::setSoftLowerLimit(double value) { soft_lower_limit = value; }

void JointSafety::setKPosition(double value) { k_position = value; }

void JointSafety::setKVelocity(double value) { k_velocity = value; }
