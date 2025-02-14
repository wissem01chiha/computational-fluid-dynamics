#include <gtest/gtest.h>
#include "internal/pose_parser.h"

TEST(PoseTest, parseTest) {
    
    const char* xmlString = R"(
        <origin xyz="1.0 2.0 3.0" rpy="0.1 0.2 0.3" />
    )";
    
    tinyxml2::XMLDocument doc;
    ASSERT_EQ(doc.Parse(xmlString), tinyxml2::XML_SUCCESS);
    tinyxml2::XMLElement* element = doc.FirstChildElement("origin");

    PoseParser parser;
    parser.parse(element);
    const auto pose = parser.get();
    std::cout << parser.toString();
    
    Vec3 expectedPosition(1.0, 2.0, 3.0);
    double roll = 0.1, pitch = 0.2, yaw = 0.3;

    Eigen::AngleAxis<double> rollAngle(roll, Eigen::Vector3d::UnitX());
    Eigen::AngleAxis<double> pitchAngle(pitch, Eigen::Vector3d::UnitY());
    Eigen::AngleAxis<double> yawAngle(yaw, Eigen::Vector3d::UnitZ());

    Rot3 expectedRotation = yawAngle * pitchAngle * rollAngle;

    EXPECT_EQ(pose->getPosition()[0], expectedPosition[0]);
    EXPECT_EQ(pose->getPosition()[1], expectedPosition[1]);
    EXPECT_EQ(pose->getPosition()[2], expectedPosition[2]);

    EXPECT_EQ(pose->getRotation().coeffs()[0], expectedRotation.coeffs()[0]);
    EXPECT_EQ(pose->getRotation().coeffs()[1], expectedRotation.coeffs()[1]);
    EXPECT_EQ(pose->getRotation().coeffs()[2], expectedRotation.coeffs()[2]);
    EXPECT_EQ(pose->getRotation().coeffs()[3], expectedRotation.coeffs()[3]);
}

TEST(PoseTest, nullptrParseTest){

    PoseParser parser;
    parser.parse(nullptr);
    const auto pose = parser.get();

    EXPECT_EQ(pose->getPosition()[0], 0);
    EXPECT_EQ(pose->getPosition()[1], 0);
    EXPECT_EQ(pose->getPosition()[2], 0);

    EXPECT_EQ(pose->getRotation().coeffs()[0], 0);
    EXPECT_EQ(pose->getRotation().coeffs()[1], 0);
    EXPECT_EQ(pose->getRotation().coeffs()[2], 0);
    EXPECT_EQ(pose->getRotation().coeffs()[3], 1);
}

