#include <gtest/gtest.h>
#include "utils.h"

TEST(Str2arrayTest, ValidInputSinglePrecision){

    const char* str = "1.0 2.0 3.0"; 
    double vec[3];
    str2array(str, vec);
    EXPECT_DOUBLE_EQ(vec[0], 1.0);  
    EXPECT_DOUBLE_EQ(vec[1], 2.0);   
    EXPECT_DOUBLE_EQ(vec[2], 3.0);   
};

TEST(SplitTest, SimpleSplit) {

    std::string input = "1.2";
    std::vector<std::string> result;
    
    split(input, result, ".");

    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0], "1");
    EXPECT_EQ(result[1], "2");
};