
// Copyright 2025 Wissem CHIHA

#include <iostream>
#include <memory>
#include <cxxopts/cxxopts.hpp>
#include "urdf_parser.h"

int main(int argc, char* argv[]) {

    cxxopts::Options options("parse", "Parse and display URDF models");
    options.add_options()
        ("f,file", "Path to the URDF file", cxxopts::value<std::string>()->default_value(""))
        ("h,help", "Print usage");

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }
    std::string file_path = result["file"].as<std::string>();

    try {
        URDFParser parser;
        parser.parse(file_path.c_str());
        std::shared_ptr<Model> model_ = parser.get();
        model_->print(std::cout);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
