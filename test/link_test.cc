#include <gtest/gtest.h>
#include "core/link.h"
#include "core/box.h"

TEST(LinkTest, TestGlobal) {

    Link link;
    link.setName("Link_for_test");
    auto visual = std::make_shared<Visual>();
    auto pose = std::make_shared<Pose>();
    pose->setPosition(0, 0, 0);
    visual->setOrigin(pose);
    auto box = std::make_shared<Box>();
    box->setOrigin(10,20,30);
    visual->setGeometry(box);
    link.setVisual(visual);

    EXPECT_EQ(link.getName(), "Link_for_test");
    EXPECT_TRUE(link.getVisual() != nullptr);
    EXPECT_TRUE(link.getMaterial() != nullptr);
    EXPECT_TRUE(link.getCollision() != nullptr);

    auto box_ = link.getVisual()->getGeometry();
    EXPECT_TRUE(box_ != nullptr);
    EXPECT_TRUE(box_->isA("box")); 
    double origin[3];
    box_->getOrigin(origin);
    EXPECT_EQ(origin[0], 20);   
    EXPECT_EQ(origin[1], 40);
    EXPECT_EQ(origin[2], 60);

};
