#include <gtest/gtest.h>
#include "internal/link_parser.h"

TEST(LinkParserTest, ParserTest){

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError eResult = doc.LoadFile("../examples/urdf/simple_test.urdf");
    if (eResult != tinyxml2::XML_SUCCESS) {
        std::cerr << "Error loading XML file: " << doc.ErrorStr() << std::endl;
    }

    LinkParser parser;
    const tinyxml2::XMLElement *xml = doc.FirstChildElement("model");
    parser.parse(xml->FirstChildElement("link"));
    std::cout << parser.toString();
    const auto linkdata = parser.get();
    auto link_collison = linkdata->getCollision();
    std::cout << link_collison->toString();
    
    ASSERT_NE(linkdata, nullptr); 
};
 