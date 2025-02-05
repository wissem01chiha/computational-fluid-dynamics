#include "joint_calibration.h"

JointCalibration::JointCalibration() 
    : referencePosition(0.0), rising(0.0), falling(0.0) {}

bool JointCalibration::isA(const char* name) {
    return std::string(name) == "calibration";
}

void JointCalibration::print(std::ostream& os) {
    os << "Calibration : [" 
       << "reference=" << referencePosition 
       << ", " << "rising=" << rising 
       << ", " << "falling=" << falling << "]";
}

void JointCalibration::clear() {
    referencePosition = 0.0;
    rising = 0.0;
    falling = 0.0;
}

void JointCalibration::setRising(double r) {

    if (r > 0) {rising = r;}
}

void JointCalibration::setFalling(double f) {

    if (f > 0) {falling = f;}
}

void JointCalibration::setReferencePosition(double rp) {
    referencePosition = rp;
}