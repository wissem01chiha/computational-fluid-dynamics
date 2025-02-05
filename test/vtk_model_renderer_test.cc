#include <gtest/gtest.h>
#include "model_parser.h"
#include "vtk_model_renderer.h"

TEST(VtkModelRendererTest, RenderTest) {

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError eResult = doc.LoadFile("C:/Users/chiha/OneDrive/Documents/tinyurdf/examples/urdf/simple_test.urdf");
    if (eResult != tinyxml2::XML_SUCCESS) {
        std::cerr << "Error loading XML file: " << doc.ErrorStr() << std::endl;
    }
    ModelParser mp;
    mp.parse(doc.FirstChildElement("robot"));
    auto model = mp.get();
    
    ASSERT_FALSE(model->empty());

    VtkModelRenderer renderer;
    renderer.setModel(*model);
    renderer.print(std::cout);
    renderer.setBackrgournd(0.6, 0.8, 0.8, 1.0);
    renderer.setLabelsVisibility(false);
    renderer.show();
    ASSERT_EQ(renderer.empty(), false);
    ASSERT_STREQ(renderer.getTypename(), "VtkModelRenderer");
}