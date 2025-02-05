#include <gtest/gtest.h>
#include "joint.h"

TEST(JointTest, GlobalTest) {
    
    
    Joint joint;
    joint.print(std::cout);
    EXPECT_STREQ(joint.getTypename(), "joint");
    EXPECT_TRUE(joint.isA("joint"));

    joint.setName("new_joint_name");
    joint.print(std::cout);

    std::shared_ptr d = std::make_shared<JointDynamics>();
    d->setDamping(1000);
    joint.setDynamics(d);
    joint.print(std::cout);
};

TEST(JointTest, TransformTest){

    Joint joint;
    Pose pose;
    pose.setPosition(1.0, 2.0, 3.0);
    std::shared_ptr<Pose> pose_ptr = std::make_shared<Pose>(pose);
    joint.pushBackTransform(pose_ptr);
    joint.print(std::cout);
    std::vector<std::shared_ptr<Pose>> poses = joint.getTransform();
    EXPECT_EQ(poses.size(), 1);
    EXPECT_EQ(poses[0]->getPosition()[0], 1.0);
};