#include <gtest/gtest.h>
#include "color.h"
#include <iostream>

TEST(ColorTest, DefaultConstructor) {
    Color color;  
    color.print(std::cout);
    
    EXPECT_EQ(color.getR(), 0.0);
    EXPECT_EQ(color.getG(), 0.0);
    EXPECT_EQ(color.getB(), 0.0);
    EXPECT_EQ(color.getA(), 1.0);
}

TEST(ColorTest, SafeConstructor) {
    Color color(0.58, 1.0, 0.7, 1.0);  

    EXPECT_EQ(color.getR(), 0.58);
    EXPECT_EQ(color.getG(), 1.0);
    EXPECT_EQ(color.getB(), 0.7);
    EXPECT_EQ(color.getA(), 1.0);
}

TEST(ColorTest, StringConstructor) {
    std::string color_str = "0.5 0.6 0.7 1.0";
    Color color(color_str); 

    EXPECT_EQ(color.getR(), 0.5);
    EXPECT_EQ(color.getG(), 0.6);
    EXPECT_EQ(color.getB(), 0.7);
    EXPECT_EQ(color.getA(), 1.0);
}

TEST(ColorTest, ClearFunction) {
    Color color("0.2 0.3 0.4 0.5");  

    color.clear();  

    EXPECT_EQ(color.getR(), 0.0);
    EXPECT_EQ(color.getG(), 0.0);
    EXPECT_EQ(color.getB(), 0.0);
    EXPECT_EQ(color.getA(), 1.0);
}

TEST(ColorTest, InvalidStringConstructor) {
    std::string invalid_color_str = "0.5 0.5 0.5";  
    Color color(invalid_color_str);

    EXPECT_NE(color.getR(), 0.5);
    EXPECT_NE(color.getG(), 0.5);
    EXPECT_NE(color.getB(), 0.5);
    EXPECT_EQ(color.getA(), 1.0);

}

TEST(ColorTest,ColorFromTypeTest ){

    Color color(Color::Type::Red);

    EXPECT_EQ(color.getR(), 1);
    EXPECT_EQ(color.getG(), 0);
    EXPECT_EQ(color.getB(), 0);
    EXPECT_EQ(color.getA(), 1);
}