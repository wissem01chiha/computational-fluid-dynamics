#ifndef TINYURDF_JOINTSAFETY_H
#define TINYURDF_JOINTSAFETY_H

// Copyright 2025 Wissem CHIHA

#include "property_base.h"
#include <ostream>
#include <string>

class JointSafety : public PropertyBase{
public:
    JointSafety();
    bool isA(const char* name) override;
    void print(std::ostream& os) override;
    void clear() override;
    void setSoftUpperLimit(double value);
    void setSoftLowerLimit(double value);
    void setKPosition(double value);
    void setKVelocity(double value);
private:
    double soft_upper_limit, soft_lower_limit;
    double k_position, k_velocity;
};
#endif // TINYURDF_JOINTSAFETY_H