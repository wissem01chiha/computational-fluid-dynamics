#include <gtest/gtest.h>
#include "internal/visual_parser.h"

TEST(VisualParserTest, ParseTest) {

  const char* xmlContent = R"(
    <visual>
        <origin xyz="7 5.2 0" rpy="0 2.5 1" />
        <geometry>
           <box size = "12 8 1" />
        </geometry>  
        <material name="Cyan">
          <color rgba="0 1.0 1.0 1.0"/>
          <texture  filename = "C:/Users/chiha/OneDrive/Documents/tinyurdf/test/valid_path.txt" />
          <density value = "1.0" />
        </material>
    </visual>
    )";

  tinyxml2::XMLDocument doc;
  ASSERT_EQ(doc.Parse(xmlContent), tinyxml2::XML_SUCCESS);

  VisualParser parser;
  parser.parse(doc.FirstChildElement("visual"));
  std::cout << parser.toString();

  auto parsedData = parser.get();
  ASSERT_NE(parsedData, nullptr);
}