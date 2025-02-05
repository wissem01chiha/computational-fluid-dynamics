#include <gtest/gtest.h>
#include "joint_parser.h"

TEST(JointParserTest, ConstrutorTest){

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError eResult = doc.LoadFile("../examples/urdf/joint2.urdf");
    if (eResult != tinyxml2::XML_SUCCESS) {
        std::cerr << "Error loading XML file: " << doc.ErrorStr() << std::endl;
    }
    
    JointParser parser;
    parser.parse(doc.FirstChildElement("joint"));
    parser.print(std::cout);
    auto parsedData = parser.get();
    ASSERT_EQ(parsedData->isA("joint"), true);
    ASSERT_EQ(std::string(parsedData->getName()), "front_rail_joint");
    auto t = parsedData->getTransform();
    ASSERT_EQ(t.empty(), false);

};
