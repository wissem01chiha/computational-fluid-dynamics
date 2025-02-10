#ifndef TINYURDF_JOINT_MIMIC_H
#define TINYURDF_JOINT_MIMIC_H

// Copyright 2025 Wissem CHIHA

#include "property_base.h"
#include <string>
#include <ostream>

class JointMimic : public PropertyBase {
public:
    JointMimic();
    bool isA(const char* name) override;
    void print(std::ostream& os) override;
    void clear() override;
    void setOffset(double o);
    void setMultiplier(double m);
    void setName(std::string& n_);
private:
    double offset, multiplier;
    std::string name;
};
#endif // TINYURDF_JOINTMIMIC_H