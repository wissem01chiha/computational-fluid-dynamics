#include <gtest/gtest.h>
#include "vtk_link_renderer.h"
#include "link_parser.h"

TEST(vtkLinkRenderer, RenderFromStructTest)
{
    Link link;
    link.setName("Link_for_test");
    auto visual = std::make_shared<Visual>();
    auto pose = std::make_shared<Pose>();
    pose->setPosition(0, 0, 0);
    pose->setRotation(2.5, 0, -1.5);
    visual->setOrigin(pose);
    auto box = std::make_shared<Box>();
    box->setOrigin(10,20,30);
    visual->setGeometry(box);
    link.setVisual(visual);

    VtkLinkRenderer renderer;
    renderer.setLink(link);
    EXPECT_FALSE(renderer.empty());

    renderer.setBackrgournd(0.6, 0.8, 0.8, 1.0);
    renderer.show();
}

TEST(vtkLinkRenderer, RendrerFromFile){

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError eResult = doc.LoadFile("C:/Users/chiha/OneDrive/Documents/tinyurdf/examples/urdf/link.urdf");
    if (eResult != tinyxml2::XML_SUCCESS) {
        std::cerr << "Error loading XML file: " << doc.ErrorStr() << std::endl;
    }

    LinkParser parser;
    const tinyxml2::XMLElement *xml = doc.FirstChildElement("model");
    parser.parse(xml->FirstChildElement("link"));
    parser.print(std::cout);
    const auto linkdata = parser.get();
    VtkLinkRenderer renderer;
    renderer.setLink(*linkdata);
    renderer.setBackrgournd(0.6, 0.8, 0.8, 1.0);
    renderer.show();
    EXPECT_FALSE(renderer.empty());
}