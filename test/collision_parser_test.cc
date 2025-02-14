#include <gtest/gtest.h>
#include "internal/collision_parser.h"

TEST(CollisionParserTest, ParseTest) {

  const char* xmlContent = R"(
    <collision>
        <origin xyz="1 2 8" rpy = "1 0 0"/>
        <geometry>
           <sphere radius = "8" />
        </geometry>  
   </collision>
    )";

  tinyxml2::XMLDocument doc;
  ASSERT_EQ(doc.Parse(xmlContent), tinyxml2::XML_SUCCESS);

  CollisionParser parser;
  parser.parse(doc.FirstChildElement("collision"));
  std::cout << parser.toString();

  auto parsedData = parser.get();
  ASSERT_NE(parsedData, nullptr);
}