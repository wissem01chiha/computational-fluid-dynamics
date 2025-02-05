#include "joint_mimic.h"

JointMimic::JointMimic() 
    : offset(0.0), multiplier(1.0), name("") {}

bool JointMimic::isA(const char* name) {
    return std::string(name) == "mimic";
}

void JointMimic::print(std::ostream& os) {
    os << "Mimic : [" 
       << "offset=" << offset 
       << ", " << "multiplier=" << multiplier 
       << ", " << "name=" << name.c_str() 
       << "]";
}

void JointMimic::clear() {
    offset = 0.0;
    multiplier = 1.0;
    name.clear();
}

void JointMimic::setOffset(double o) {
    offset = o;
}

void JointMimic::setMultiplier(double m) {
    if (m != 0) {
        multiplier = m;
    }
}

void JointMimic::setName(std::string& n_) {
    if (!n_.empty()) {
        name = n_;
    }
}
