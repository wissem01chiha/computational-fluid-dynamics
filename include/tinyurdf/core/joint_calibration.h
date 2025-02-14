#ifndef INCLUDE_TINYURDF_CORE_JOINT_CALIBRATION_H_
#define INCLUDE_TINYURDF_CORE_JOINT_CALIBRATION_H_

// Copyright 2025 Wissem CHIHA

#include "common/property_base.h"
#include <string>

class JointCalibration : public PropertyBase {
 public:
  JointCalibration();
  bool isA(const char* name) const override;
  std::string toString() const override;
  void clear() override;
  void setRising(double r);
  void setFalling(double f);
  void setReferencePosition(double rp);
 private:
  double referencePosition, rising, falling;
};
#endif // INCLUDE_TINYURDF_CORE_JOINT_CALIBRATION_H_