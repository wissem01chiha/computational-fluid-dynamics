#include <gtest/gtest.h>
#include "link_parser.h"

TEST(LinkParserTest, ParserTest){

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError eResult = doc.LoadFile("../examples/urdf/simple_test.urdf");
    if (eResult != tinyxml2::XML_SUCCESS) {
        std::cerr << "Error loading XML file: " << doc.ErrorStr() << std::endl;
    }

    LinkParser parser;
    const tinyxml2::XMLElement *xml = doc.FirstChildElement("model");
    parser.parse(xml->FirstChildElement("link"));
    parser.print(std::cout);
    const auto linkdata = parser.get();
    auto link_collison = linkdata->getCollision();
    link_collison->print(std::cout);
    
    ASSERT_NE(linkdata, nullptr); 
};
 