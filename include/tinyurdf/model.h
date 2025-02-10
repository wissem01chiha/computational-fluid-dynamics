#ifndef TINYURDF_MODEL_H_
#define TINYURDF_MODEL_H_

// Copyright 2025 Wissem CHIHA

#include <string>

#include <loguru/loguru.hpp>

#include "object_base.h"
#include "property_base.h"
#include "utils.h"
#include "joint.h"
#include "link.h"

/**
 * @brief base class for representing a multi-body system
 * @note The model is a container for links, joints, and sensors.
 * checking the multi-body system for consistency and completeness.
 * is not fully implemented yet, only parents and children links 
 * are checked, with the graph structure of the model.
 */
class Model : public ObjectBase{
public:
  Model();
  Model(const Model& rhs);
  void clear() override;
  void setName(const std::string& n);
  std::string getName() const;
  bool isA(const char* name) override;
  void print(std::ostream& os) override;
  const char* getTypename() override;
  bool empty() const override;
  void setLink(std::shared_ptr<Link> link);
  void setLink(std::vector<std::shared_ptr<Link>> link);
  void setJoint(std::vector<std::shared_ptr<Joint>> joint);
  void setJoint(std::shared_ptr<Joint> joint);
  void setJoint(std::shared_ptr<Joint> joint, const std::string& parent, const std::string& child);
  std::vector<std::shared_ptr<Joint>> getJoints() const;
  std::vector<std::shared_ptr<Link>> getLinks() const;
  ~Model();
private:
  std::string name;
  std::vector<std::shared_ptr<Joint>> joints;
  std::vector<std::shared_ptr<Link>> links;
};
#endif // TINYURDF_MODEL_H_