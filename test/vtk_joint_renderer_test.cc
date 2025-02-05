#include<gtest/gtest.h>
#include "vtk_joint_renderer.h"

TEST(VtkJointRenderer, TestShow)
{
    VtkJointRenderer renderer;
    Joint joint;
    joint.setName("joint_for_test");
    joint.setType("revolute");
    joint.setAxis(1.0, 1.0, 0.0);
    Pose pose;
    Pose pose2;
    pose.setPosition(1.0, 0.0, 0.0);
    pose2.setPosition(1.0, 1.0, 0.0);
    pose2.setRotation(0.4, 0.0, 0.0);
    std::shared_ptr<Pose> pose_ptr = std::make_shared<Pose>(pose);
    std::shared_ptr<Pose> pose_ptr2 = std::make_shared<Pose>(pose2);

    joint.pushBackTransform(pose_ptr);
    joint.pushBackTransform(pose_ptr2);
    renderer.setJoint(joint);
    renderer.print(std::cout);
    renderer.setWindowSize(800, 600);
    renderer.setBackrgournd(0.6, 0.8, 0.8, 1.0);
    renderer.show();
    EXPECT_TRUE(renderer.empty());
}
