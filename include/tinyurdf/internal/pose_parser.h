#ifndef INCLUDE_TINYURDF_INTERNAL_POSE_PARSER_H_
#define INCLUDE_TINYURDF_INTERNAL_POSE_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include "core/pose.h"
#include "common/parser_base.h"
#include "utility/utils.h"

/**
 * \brief Elementary parser for minimal pose description.
 * \note This is an elementary base parser.
 * \code{.xml} <origin xyz="0 1 0" rpy="0 0 0"/> \endcode
 * \note Another class, for example, named `NamedPoseParser`,
 *       extends the functionalities to support:
 * \code{.xml} <origin xyz="0 1 0" rpy="0 0 0" reference="bla bla.."/> \endcode
 *       where `reference` can be a link, joint, ground, etc.
 */ 
class PoseParser final : public ParserBase<Pose> {
public:
   PoseParser();
   std::string toString() const override;
   bool empty() const override;
   void clear() override;
   const char* getTypename() const override;
   bool isA(const char* name) const override;
   void parse(const tinyxml2::XMLElement* xml) override;
   std::shared_ptr<Pose> get() override;
private:
   std::shared_ptr<Pose> p_;
};
#endif  // INCLUDE_TINYURDF_INTERNAL_POSE_POSE_PARSER_H_
