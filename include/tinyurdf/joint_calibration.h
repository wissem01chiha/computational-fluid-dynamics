#ifndef TINYURDF_JOINTCALIBRATION_H
#define TINYURDF_JOINTCALIBRATION_H

// Copyright 2025 Wissem CHIHA

#include "property_base.h"
#include <string>
#include <ostream>

class JointCalibration : public PropertyBase {
public:
    JointCalibration();
    bool isA(const char* name) override;
    void print(std::ostream& os) override;
    void clear() override;
    void setRising(double r);
    void setFalling(double f);
    void setReferencePosition(double rp);

private:
    double referencePosition, rising, falling;
};
#endif // TINYURDF_JOINTCALIBRATION_H