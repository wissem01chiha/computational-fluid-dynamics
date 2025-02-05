#ifndef INCLUDE_TINYURDF_POSE_POSE_PARSER_H_
#define INCLUDE_TINYURDF_POSE_POSE_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <memory>
#include "pose.h"
#include "parser_base.h"
#include "utils.h"

/**
 * \brief Elementary parser for minimal pose description.
 *
 * \note This is an elementary base parser.
 * \code{.xml} <origin xyz="0 1 0" rpy="0 0 0"/> \endcode
 * \note Another class, for example, named `NamedPoseParser`,
 *       extends the functionalities to support:
 * \code{.xml} <origin xyz="0 1 0" rpy="0 0 0" reference="bla bla.."/> \endcode
 *       where `reference` can be a link, joint, ground, etc.
 */
class PoseParser : public ParserBase<Pose> {
 public:
  PoseParser() {
    this->p_ = std::make_shared<Pose>();
  }

  void print(std::ostream& os) override {
    os << "Parsed Pose = [";
    p_->print(os);
    os << "]";
  }

  bool empty() const override {
    return false;
  }

  void clear() override {
    p_->clear();
  }

  const char* getTypename() override {
    return "pose";
  }

  bool isA(const char* name) override {
    return isA(name);
  }

  void parse(const tinyxml2::XMLElement* xml) override {
    ParserBase<Pose>::parse(xml);

    const char* xyz_str = xml->Attribute("xyz");
    const char* rpy_str = xml->Attribute("rpy");

    if (xyz_str) {
      double v[3];
      str2array(xyz_str, v);
      p_->setPosition(v[0], v[1], v[2]);
    }

    if (rpy_str) {
      double r[3];
      str2array(rpy_str, r);
      p_->setRotation(r[0], r[1], r[2]);
    }
  }

  std::shared_ptr<Pose> get() override {
    return p_;
  }

 private:
  std::shared_ptr<Pose> p_;
};

#endif  // INCLUDE_TINYURDF_POSE_POSE_PARSER_H_
