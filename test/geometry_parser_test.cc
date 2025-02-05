#include <gtest/gtest.h>
#include "geometry_parser.h"

TEST(GeometryParserTest, ParseTest) {

  const char* xmlContent = R"(
    <geometry>        
      <mesh filename ="C:/Users/chiha/OneDrive/Documents/tinyurdf/test/valid_path.txt" color = "1.2 2 1 1"/> 
    </geometry>
    )";

  tinyxml2::XMLDocument doc;
  ASSERT_EQ(doc.Parse(xmlContent), tinyxml2::XML_SUCCESS);

  GeometryParser parser;
  parser.parse(doc.FirstChildElement("geometry"));
  parser.print(std::cout);

  auto parsedData = parser.get();
  ASSERT_NE(parsedData, nullptr);
  ASSERT_EQ(parsedData->isA("mesh"), true);
  ASSERT_EQ(parsedData->isA("cylinder"), false);
  ASSERT_EQ(parsedData->isA("box"), false);
  ASSERT_EQ(parsedData->isA("sphere"), false);
  ASSERT_EQ(std::string(parsedData->getTypename()), "mesh");
}

TEST(GeometryParserTest, ParseTestfromFile) {

  tinyxml2::XMLDocument doc;
  tinyxml2::XMLError eResult = doc.LoadFile("../exemples/.urdf/simple_test.urdf");
  if (eResult != tinyxml2::XML_SUCCESS) {
      std::cerr << "Error loading XML file: " << doc.ErrorStr() << std::endl;
  }
  const tinyxml2::XMLElement* m = doc.FirstChildElement("model");
  const tinyxml2::XMLElement* link = m->FirstChildElement("link");
  const tinyxml2::XMLElement* visual = link->FirstChildElement("visual");
  const tinyxml2::XMLElement* geometry = visual->FirstChildElement("geometry");

  GeometryParser parser;
  parser.parse(geometry);
  parser.print(std::cout);

  auto parsedData = parser.get();
  ASSERT_NE(parsedData, nullptr);
}