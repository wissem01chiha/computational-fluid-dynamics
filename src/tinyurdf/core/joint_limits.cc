#include "core/joint_limits.h"

JointLimits::JointLimits() 
    : lower(0.0), upper(0.0), effort(0.0), velocity(0.0) {}

bool JointLimits::isA(const char* name) const {
    return std::string(name) == "limits";
}

std::string JointLimits::toString() const {

    std::ostringstream os;
    os << "Limits : [" 
       << "lower=" << lower 
       << ", " << "upper=" << upper 
       << ", " << "effort=" << effort 
       << ", " << "velocity=" << velocity 
       << "]";
    return os.str();
}

void JointLimits::clear() {
    lower = 0.0;
    upper = 0.0;
    effort = 0.0;
    velocity = 0.0;
}

void JointLimits::setEffort(double effort_) {
    effort = effort_;
}

void JointLimits::setVelocity(double vel_) {
    velocity = vel_;
}
