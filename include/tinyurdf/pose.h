#ifndef INCLUDE_TINYURDF_POSE_POSE_H_
#define INCLUDE_TINYURDF_POSE_POSE_H_

// Copyright 2025 Wissem CHIHA

#include <iostream>
#include "utils.h"
#include "property_base.h"

/**
 * @brief Represents a pose, consisting of position and rotation.
 */
class Pose : public PropertyBase {
 public:
  Pose();
  Pose(const Pose& rhs);
  Pose& operator=(const Pose& rhs);
  Pose& operator=(Pose&& rhs) noexcept;
  bool isA(const char* name) override;
  void print(std::ostream& os) override;
  Vec3 getPosition();
  Rot3 getRotation();
  void setPosition(double x, double y, double z);
  void setRotation(double x, double y, double z, double w);
  void setRotation(double r, double p, double y);
  void clear() override;
  ~Pose();
 private:
  Vec3 position;
  Rot3 rotation;
};

#endif  // INCLUDE_TINYURDF_POSE_POSE_H_
