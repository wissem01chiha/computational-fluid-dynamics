#include <gtest/gtest.h>
#include "model_parser.h"

TEST(ModelParserTest, ParseTest) {
    
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError eResult = doc.LoadFile("C:/Users/chiha/OneDrive/Documents/tinyurdf/examples/urdf/simple_test.urdf");
    if (eResult != tinyxml2::XML_SUCCESS) {
        std::cerr << "Error loading XML file: " << doc.ErrorStr() << std::endl;
    }
    ModelParser mp;  
    mp.parse(doc.FirstChildElement("model"));
    mp.print(std::cout);
}
