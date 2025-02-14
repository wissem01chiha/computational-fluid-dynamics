#include <gtest/gtest.h>
#include "internal/material_parser.h"

TEST(MaterialParserTest, ParseTest) {

    const char* xmlContent = R"(
        <material name="Cyan">
            <texture filename="C:/Users/chiha/OneDrive/Documents/tinyurdf/test/valid_path.txt" />
            <color rgba="5 1.0 1.0 1.0" />
            <density value="18" />
        </material>
    )";

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError error = doc.Parse(xmlContent);
    ASSERT_EQ(error, tinyxml2::XML_SUCCESS);

    MaterialParser parser;
    parser.parse(doc.FirstChildElement("material"));

    auto material = parser.get();
    std::cout << parser.toString();
    ASSERT_NE(material, nullptr);
}
