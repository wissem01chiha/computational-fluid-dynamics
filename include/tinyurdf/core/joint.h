#ifndef INCLUDE_TINYURDF_CORE_JOINT_H_
#define INCLUDE_TINYURDF_CORE_JOINT_H_

// Copyright 2025 Wissem CHIHA

#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <loguru/loguru.hpp>
#include "core/joint_calibration.h"
#include "core/joint_dynamics.h"
#include "core/joint_limits.h"
#include "core/joint_mimic.h"
#include "core/joint_safety.h"
#include "common/object_base.h"
#include "core/pose.h"
#include "utility/utils.h"

class Joint : public ObjectBase{
 public:
  enum class Type
  {
    UNKNOWN, REVOLUTE, CONTINUOUS, PRISMATIC, FLOATING, PLANAR, FIXED, 
    UNIVERSAL
  };
  Joint();
  Joint(const Joint& rhs);
  Joint(Joint&& rhs) noexcept;
  void clear() override;
  bool isA(const char* name) const override;
  std::string toString() const override;
  bool empty() const override;
  const char* getTypename() const override;
  void setDynamics(const std::shared_ptr<JointDynamics> d);
  void setLimits(const std::shared_ptr<JointLimits> l);
  void setSafety(const std::shared_ptr<JointSafety> s);
  void setCalibration(const std::shared_ptr<JointCalibration> c);
  void setMimic(const std::shared_ptr<JointMimic> m);
  void setName(const std::string& name_);
  void setType(const Type& t_);
  void setType(const char* c_);
  void setAxis(double x, double y, double z);
  std::string getName() const;
  void pushBackChild(const std::string lk);
  void pushBackParent(const std::string lk);
  void pushBackTransform(const std::shared_ptr<Pose> t);
  bool isChild(const char* name) const;
  bool isParent(const char* name) const;
  std::vector<std::shared_ptr<Pose>> getTransform() const;
  Vec3 getAxis() const;
private: 
  Type           type;
  std::string    name;
  Vec3           axis;
  std::vector<std::string> child;
  std::vector<std::string> parent;
  std::vector<std::shared_ptr<Pose>> transform;
  std::shared_ptr<JointDynamics> dynamics;
  std::shared_ptr<JointLimits> limits;
  std::shared_ptr<JointSafety> safety;
  std::shared_ptr<JointCalibration> calibration;
  std::shared_ptr<JointMimic> mimic;
};
#endif // INCLUDE_TINYURDF_CORE_JOINT_H