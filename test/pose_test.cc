#include <gtest/gtest.h>
#include "pose.h"

#define M_PI  3.14159265358979323846

class PoseTest : public ::testing::Test {
};

TEST_F(PoseTest, DefaultConstructor) {
    Pose pose;
    Vec3 position = pose.getPosition();
    Rot3 rotation = pose.getRotation();

    EXPECT_EQ(position[0], 0.0);
    EXPECT_EQ(position[1], 0.0);
    EXPECT_EQ(position[2], 0.0);
    EXPECT_EQ(rotation.coeffs()[0], 0.0);
    EXPECT_EQ(rotation.coeffs()[1], 0.0);
    EXPECT_EQ(rotation.coeffs()[2], 0.0);
    EXPECT_EQ(rotation.coeffs()[3], 1.0); 
}

TEST_F(PoseTest, SetAndGetPosition) {
    Pose pose;
    pose.setPosition(1.0, 2.0, 3.0);

    Vec3 position = pose.getPosition();
    EXPECT_EQ(position[0], 1.0);
    EXPECT_EQ(position[1], 2.0);
    EXPECT_EQ(position[2], 3.0);
}

TEST_F(PoseTest, SetAndGetRotationQuaternion) {
    Pose pose;
    pose.setRotation(0.0, 0.0, 0.0, 1.0);

    Rot3 rotation = pose.getRotation();
    EXPECT_EQ(rotation.coeffs()[0], 0.0);
    EXPECT_EQ(rotation.coeffs()[1], 0.0);
    EXPECT_EQ(rotation.coeffs()[2], 0.0);
    EXPECT_EQ(rotation.coeffs()[3], 1.0); 
}

TEST_F(PoseTest, SetAndGetRotationEuler) {
    Pose pose;
    pose.setRotation(0.0, M_PI / 2, 0.0); 

    Rot3 rotation = pose.getRotation();
    EXPECT_NEAR(rotation.coeffs()[0], 0.0, 1e-6);
    EXPECT_NEAR(rotation.coeffs()[1], std::sin(M_PI / 4), 1e-6);
    EXPECT_NEAR(rotation.coeffs()[2], 0.0, 1e-6);
    EXPECT_NEAR(rotation.coeffs()[3], std::cos(M_PI / 4), 1e-6);
}

TEST_F(PoseTest, isA) {
    Pose pose;
    EXPECT_TRUE(pose.isA("pose"));
    EXPECT_FALSE(pose.isA("NonPose"));
}

TEST_F(PoseTest, copyAssignment) {
    Pose pose1;
    pose1.setPosition(1.0, 2.0, 3.0);
    pose1.setRotation(0.0, 0.0, 0.0, 1.0);

    Pose pose2;
    pose2 = pose1;

    EXPECT_EQ(pose2.getPosition()[0], 1.0);
    EXPECT_EQ(pose2.getPosition()[1], 2.0);
    EXPECT_EQ(pose2.getPosition()[2], 3.0);

    EXPECT_EQ(pose2.getRotation().coeffs()[3], 1.0);
}

TEST_F(PoseTest, clear) {
    Pose pose;
    pose.setPosition(1.0, 2.0, 3.0);
    pose.setRotation(0.0, 0.0, 0.0, 1.0);

    pose.clear();

    Vec3 position = pose.getPosition();
    Rot3 rotation = pose.getRotation();

    EXPECT_EQ(position[0], 0.0);
    EXPECT_EQ(position[1], 0.0);
    EXPECT_EQ(position[2], 0.0);

    EXPECT_EQ(rotation.coeffs()[0], 0.0);
    EXPECT_EQ(rotation.coeffs()[1], 0.0);
    EXPECT_EQ(rotation.coeffs()[2], 0.0);
    EXPECT_EQ(rotation.coeffs()[3], 1.0); 
}

