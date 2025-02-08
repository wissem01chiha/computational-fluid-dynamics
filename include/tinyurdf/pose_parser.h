#ifndef INCLUDE_TINYURDF_POSE_POSE_PARSER_H_
#define INCLUDE_TINYURDF_POSE_POSE_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <memory>
#include "pose.h"
#include "parser_base.h"
#include "utils.h"

/**
 * \brief Elementary parser for minimal pose description.
 * \note This is an elementary base parser.
 * \code{.xml} <origin xyz="0 1 0" rpy="0 0 0"/> \endcode
 * \note Another class, for example, named `NamedPoseParser`,
 *       extends the functionalities to support:
 * \code{.xml} <origin xyz="0 1 0" rpy="0 0 0" reference="bla bla.."/> \endcode
 *       where `reference` can be a link, joint, ground, etc.
 */ 
class PoseParser : public ParserBase<Pose> {
public:
   PoseParser();
   void print(std::ostream& os) override;
   bool empty() const override;
   void clear() override;
   const char* getTypename() override;
   bool isA(const char* name) override;
   void parse(const tinyxml2::XMLElement* xml) override;
   std::shared_ptr<Pose> get() override;
private:
   std::shared_ptr<Pose> p_;
};
#endif  // INCLUDE_TINYURDF_POSE_POSE_PARSER_H_
