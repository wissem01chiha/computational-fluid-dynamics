#ifndef INCLUDE_TINYURDF_CORE_MODEL_H_
#define INCLUDE_TINYURDF_CORE_MODEL_H_

// Copyright 2025 Wissem CHIHA

#include <vector>
#include <string>
#include <loguru/loguru.hpp>
#include "common/object_base.h"
#include "core/joint.h"
#include "core/link.h"

/**
 * @brief Base class for representing a multi-body system
 * @note The model is a container for links, joints, and sensors.
 * checking the multi-body system for consistency and completeness.
 * is not fully implemented yet, only parents and children links 
 * are checked, with the graph structure of the model.
 */
class Model final : public ObjectBase{
 public:
  Model();
  Model(const Model& rhs);
  void clear() override;
  void setName(const std::string& n);
  std::string getName() const;
  bool isA(const char* name) const override;
  std::string toString() const override;
  const char* getTypename() const override;
  bool empty() const override;
  void setLink(std::shared_ptr<Link> link);
  void setLink(std::vector<std::shared_ptr<Link>> link);
  void setJoint(std::vector<std::shared_ptr<Joint>> joint);
  void setJoint(std::shared_ptr<Joint> joint);
  void setJoint(std::shared_ptr<Joint> joint, const std::string& parent,
     const std::string& child);
  std::vector<std::shared_ptr<Joint>> getJoints() const;
  std::vector<std::shared_ptr<Link>> getLinks() const;
  std::vector<std::shared_ptr<Material>> getMaterials() const;
  std::vector<std::string> getMaterialsName() const;
  ~Model();

 private:
  std::string name;
  std::vector<std::shared_ptr<Joint>> joints;
  std::vector<std::shared_ptr<Link>> links;
};
#endif  // INCLUDE_TINYURDF_CORE_MODEL_H_
