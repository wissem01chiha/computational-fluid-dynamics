#ifndef TINYURDF_LINK_PARSER_H_
#define TINYURDF_LINK_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <memory>
#include <string>

#include <tinyxml2/tinyxml2.h>
#include <loguru/loguru.hpp>

#include "link.h"
#include "parser_base.h"
#include "material_parser.h"
#include "geometry_parser.h"
#include "inertia_parser.h"
#include "visual_parser.h"
#include "collision_parser.h"

/**
 * @brief represents a general description of a link element in a 
 * graph-based structure mechanism. this structure allows modeling 
 * more complex connections between child and parent links via 
 * joints, representing a graph of linked elements example graph-based
 * structure.
 * @code{.xml}
 * <link name="my_link">
 *   <inertial>
 *     <origin xyz="0 0 0.5" rpy="0 0 0"/>
 *     <mass value="1"/>
 *     <inertia ixx="100"  ixy="0"  ixz="0" iyy="100" iyz="0" izz="100" />
 *   </inertial>
 *   <visual>
 *     <origin xyz="0 0 0" rpy="0 0 0" />
 *     <geometry type= "box" size = "1 1 1" />  
 *     <geometry type= "mesh" filename ="mesh1.stl" scale = "1 1 1" />  
 *     <material name="Cyan">
 *       <color rgba="0 1.0 1.0 1.0"/>
 *       <texture  filename = "file1.STL" />
 *       <density value = "1.0" />
 *     </material>
 *   </visual>
 *   <collision>
 *     <origin xyz="0 0 0" rpy = "0 0 0"/>
 *     <geometry type = "cylinder" radius="1" length="0.5" />
 *   </collision>
 * </link>
 * @endcode 
 * @note for somhow issue the get method of the link parser do not get a 
 * refrenace to the parsed object rather it gives a pointer to the specifc 
 * parsed instanciated during ruintime , we use the same inhertancce pardigm 
 * like geometryParser
 * @todo find a way to get the parsed obejct in a sperate method or overolding it
 */
class LinkParser : public ParserBase<Link> {
public:
  LinkParser();
  void parse(const tinyxml2::XMLElement* xml) override;
  bool isA(const char* name) override;
  bool empty() const override;
  void clear() override;
  void print(std::ostream& os) override;
  const char* getTypename() override;
  std::shared_ptr<Link> get() override;
  ~LinkParser()= default;
private:
  std::shared_ptr<Link> p_;
};
#endif // TINYURDF_LINKPARSER_H