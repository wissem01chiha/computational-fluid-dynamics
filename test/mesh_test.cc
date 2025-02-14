#include <gtest/gtest.h>
#include "core/mesh.h" 

class MeshTest : public ::testing::Test {
protected:
    Mesh mesh;
};

TEST_F(MeshTest, print) {

    mesh.setColor(1.0, 0.5, 0.25, 1.0);
    mesh.setFilename("../test/valid_path.txt");
    mesh.setScale(0.5, 0.5, 0.5);

    std::cout << mesh.toString();
}