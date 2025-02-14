#ifndef INCLUDE_TINYURDF_INTERNAL_JOINT_PARSER_H_
#define INCLUDE_TINYURDF_INTERNAL_JOINT_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <tinyxml2/tinyxml2.h>
#include <loguru/loguru.hpp>
#include "core/pose.h"
#include "core/joint.h"
#include "utility/utils.h"
#include "common/parser_base.h"
#include "internal/pose_parser.h"
#include "common/property_parser.h"

/**
 * @brief generalized description of a joint:
 * @code{.xml}
 * <joint name="my_joint" type="floating">
 *     <origin xyz="0 0 1" rpy="0 0 3.1416"    parent = "parent_link_1"/>
 *     <origin xyz="0 1.5 0.8" rpy="2.5 0 3.0" parent = "parent_link_2"/>
 *     ...
 *     <origin xyz="0 1.5 0.8" rpy="2.5 0 3.0" parent = "parent_link_n"/>
 *
 *     <parent link = "parent_link_1" />
 *     <parent link = "parent_link_2" />
 *     ...
 *     <parent link = "parent_link_n" />
 * 
 *     <child link  = "child_link_1"/>
 *     <child link  = "child_link_2"/>
 *     ...
 *     <child link  = "child_link_n"/>
 * 
 *     <calibration rising="0.0" falling ="0.0"/>
 *     <dynamics damping="0.0" friction="0.0"/>
 *     <axis  xyz = "0 1 0"/>                                            
 *     <limit effort="30" velocity="1.0" lower="-2.2" upper="0.7"/>
 *     <safety_controller k_velocity="10" k_position="15" soft_lower_limit="-2.0" soft_upper_limit="0.5"/>
 * </joint>
 * @endcode
 * @note given an xml elment with multiple joint it parses only the first elment
 * an iteration using this parser is needed!
 */
class JointParser final : public ParserBase<Joint>{
public:
  JointParser();
  void parse(const tinyxml2::XMLElement* xml) override;
  const char* getTypename() const override;
  std::shared_ptr<Joint> get() override;
  void clear() override;
  bool empty() const override;
  std::string toString() const override;
  bool isA(const char* name) const override;
  ~JointParser();
private:
    std::shared_ptr<Joint> p_;
  };
#endif // INCLUDE_TINYURDF_INTERNAL_JOINTPARSER_H