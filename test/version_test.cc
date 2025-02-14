#include <gtest/gtest.h>
#include "internal/version.h"

TEST(VersionTest, ConstructorAndGetters) {

    const char* version_string = "1.2"; 

    Version version(version_string);  
    std::cout << version.toString();
    
    EXPECT_EQ(version.getMajor(), 1);
    EXPECT_EQ(version.getMinor(), 2);
}

TEST(VersionTest, EqualFunction) {

    const char* version_string1 = "2.5";
    const char* version_string2 = "2.5";
    const char* version_string3 = "2.6";

    Version version(version_string1); 
    Version version2(version_string2);
    Version version3(version_string3);

    EXPECT_TRUE(version.equal(2, 5));  
    EXPECT_TRUE(version2.equal(2, 5)); 
    EXPECT_FALSE(version3.equal(2, 5));
}

TEST(VersionTest, copyConstructor) {

    const char* version_string = "3.4";

    Version version(version_string);  

    Version copied_version(version);  

    EXPECT_EQ(copied_version.getMajor(), 3);
    EXPECT_EQ(copied_version.getMinor(), 4);
}

TEST(VersionTest, Destructor) {

    const char* version_string = "1.1";
    Version version(version_string);  
}

TEST(VersionTest, invalidVersionString) {

    const char* invalid_version_string = "1"; 
    Version version(invalid_version_string);  
    EXPECT_EQ(version.getMajor(),1); 
    EXPECT_EQ(version.getMinor(),0);  
};