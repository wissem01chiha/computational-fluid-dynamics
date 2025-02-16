#include "core/joint_dynamics.h"
#include <sstream>

JointDynamics::JointDynamics() 
    : damping(0.0), friction(0.0), inertia(0.0) {}

bool JointDynamics::isA(const char* name) const {
    return std::string(name) == "dynamics";
}

std::string JointDynamics::toString() const {

    std::ostringstream os;
    os << "Dynamics : [" 
       << "damping=" << damping 
       << ", " << "friction=" << friction 
       << ", " << "inertia=" << inertia 
       << "]";
    return os.str();
}

void JointDynamics::clear() {
    damping = 0.0;
    friction = 0.0;
    inertia = 0.0;
}

void JointDynamics::setDamping(double d) {
    if (d > 0) {
        damping = d;
    }
}

void JointDynamics::setFriction(double f) {
    if (f > 0) {
        friction = f;
    }
}

void JointDynamics::setInertia(double i) {
    if (i > 0) {
        inertia = i;
    }
}