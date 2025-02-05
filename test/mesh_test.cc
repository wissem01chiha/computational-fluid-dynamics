#include <gtest/gtest.h>
#include "mesh.h" 
#include <iostream>

class MeshTest : public ::testing::Test {
protected:
    Mesh mesh;
};

TEST_F(MeshTest, print) {

    mesh.setColor(1.0, 0.5, 0.25, 1.0);
    mesh.setFilename("../test/valid_path.txt");
    mesh.setScale(0.5, 0.5, 0.5);

    mesh.print(std::cout);
}