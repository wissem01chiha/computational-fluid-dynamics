#include <gtest/gtest.h>
#include "common/property_parser.h"

TEST(PropertyParserTest, ParseDoubleAttributes) {

    const char* xmlContent = R"(
        <controller kPpp="10.5" kI="15.0" kD="-0.1" />
    )";

    tinyxml2::XMLDocument doc;
    ASSERT_EQ(doc.Parse(xmlContent), tinyxml2::XML_SUCCESS);

    PropertyParser<double> parser;
    parser.parse(doc.FirstChildElement("controller"));
    std::cout << parser.toString();

    auto parsedData = parser.get();
    ASSERT_EQ(parsedData->size(), 3);
    EXPECT_DOUBLE_EQ((*parsedData)["kPpp"], 10.5);
    EXPECT_DOUBLE_EQ((*parsedData)["kI"], 15.0);
    EXPECT_DOUBLE_EQ((*parsedData)["kD"], -0.1);
}

TEST(PropertyParserTest, ParseStringAttributes) {

    const char* xmlContent = R"(
        <controller name="example" description="test controller" />
    )";

    tinyxml2::XMLDocument doc;
    ASSERT_EQ(doc.Parse(xmlContent), tinyxml2::XML_SUCCESS);

    PropertyParser<std::string> parser;
    parser.parse(doc.FirstChildElement("controller"));
    std::cout << parser.toString();
    
    auto parsedData = parser.get();
    ASSERT_EQ(parsedData->size(), 2);
    EXPECT_EQ((*parsedData)["name"], "example");
}