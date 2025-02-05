// Copyright 2025 Wissem CHIHA

#include <iostream>
#include <string>
#include <cxxopts/cxxopts.hpp>
#include "urdf_parser.h"
#include "urdf_renderer.h"

int main(int argc, char* argv[]) {
    
    cxxopts::Options options("render", "Render URDF models with customization options");
    
    options.add_options()
        ("f,file", "URDF file path", cxxopts::value<std::string>())
        ("r,red", "Red component of background color", cxxopts::value<double>()->default_value("0.9"))
        ("g,green", "Green component of background color", cxxopts::value<double>()->default_value("0.9"))
        ("b,blue", "Blue component of background color", cxxopts::value<double>()->default_value("0.9"))
        ("l,labels", "Visibility of labels", cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Print usage");

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    std::string file_path = result["file"].as<std::string>();
    double red = result["red"].as<double>();
    double green = result["green"].as<double>();
    double blue = result["blue"].as<double>();
    bool show_labels = result["labels"].as<bool>();

    URDFParser parser;
    parser.parse(file_path.c_str());

    parser.print(std::cout);

    URDFRenderer renderer;
    renderer.setModel(*(parser.get()));
    renderer.setBackrgournd(red, green, blue, 1.0);  
    renderer.setLabelsVisibility(show_labels);
    renderer.show();

    return 0;
}