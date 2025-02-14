#include <gtest/gtest.h>
#include "internal/inertia_parser.h"

TEST(InertiaParserTest, parseTest) {
    
  const char* xmlString = R"(
      <inertial>
        <origin xyz="0 0 0.5" rpy="0 0 0"/>
        <mass value="1.2568"/>
        <inertia ixx="100"  ixy="0.28"  ixz="4.25" iyy="10" iyz="0" izz="100" />
      </inertial>
  )";
  
  tinyxml2::XMLDocument doc;
  ASSERT_EQ(doc.Parse(xmlString), tinyxml2::XML_SUCCESS);
  tinyxml2::XMLElement* element = doc.FirstChildElement("inertial");

  InertiaParser ip;
  ip.parse(element);
  std::cout << ip.toString();
}
