#ifndef TINYURDF_JOINT_PARSER_H_
#define TINYURDF_JOINT_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <memory>
#include <string>

#include <tinyxml2/tinyxml2.h>
#include <loguru/loguru.hpp>

#include "pose.h"
#include "joint.h"
#include "utils.h"
#include "parser_base.h"
#include "pose_parser.h"
#include "property_parser.h"

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
class JointParser : public ParserBase<Joint>{
public:
  JointParser();
  void parse(const tinyxml2::XMLElement* xml) override;
  const char* getTypename() override;
  std::shared_ptr<Joint> get() override;
  void clear() override;
  bool empty() const override;
  void print(std::ostream& os) override;
  bool isA(const char* name) override;
  ~JointParser();
private:
    std::shared_ptr<Joint> p_;
  };
#endif // TINYURDF_JOINTPARSER_H