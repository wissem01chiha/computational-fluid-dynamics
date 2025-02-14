#include "core/joint_mimic.h"

JointMimic::JointMimic() 
    : offset(0.0), multiplier(1.0), name("") {}

bool JointMimic::isA(const char* name) const {
    return std::string(name) == "mimic";
}

std::string JointMimic::toString() const {

    std::ostringstream os;
    os << "Mimic : [" 
       << "offset=" << offset 
       << ", " << "multiplier=" << multiplier 
       << ", " << "name=" << name.c_str() 
       << "]";
    return os.str();
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
