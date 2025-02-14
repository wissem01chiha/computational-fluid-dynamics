#include <gtest/gtest.h>
#include "core/model.h"

TEST(ModelTest, TestGetName) {

    Model m;
    m.setName("TestModel");
    EXPECT_STREQ(m.getName().c_str(), "TestModel");
}

