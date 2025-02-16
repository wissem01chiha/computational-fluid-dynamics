/**
 * @file urdf_parse.cc
 * @brief Command-line tool for parsing and displaying URDF models.
 * This tool uses the TinyURDF library to parse a given URDF file and optionally
 * log its string representation if the `--log` flag is set.
 * @usage:
 *   urdf_parse --file path/to/model.urdf [--log]
 */
 #include <iostream>
 #include <cxxopts/cxxopts.hpp>
 #include "internal/urdf_parser.h"
 
 int main(int argc, char* argv[]) {

    cxxopts::Options options("urdf_parse", "Parsing URDF model files");
    options.add_options()
        ("f,file", "Path to the URDF file", cxxopts::value<std::string>()->default_value(""))
        ("l,log", "Enable logging of the parsed URDF model", cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Print usage");
 
    auto result = options.parse(argc, argv);
    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }
 
    std::string file_path = result["file"].as<std::string>();
    if (file_path.empty()) {
        LOG_F(ERROR, "Error: No URDF file specified. Use --file <path>.");
        return 1;
    }

    bool log_enabled = result["log"].as<bool>();
    try {
        URDFParser parser;
        parser.parse(file_path.c_str());
        std::shared_ptr<Model> model_ = parser.get();
        if (log_enabled) {
            std::cout << model_->toString() << std::endl;
        }
        LOG_F(INFO, "URDF model successfully parsed from: %s" , file_path.c_str() );
    } catch (const std::exception& e) {
        LOG_F(ERROR,  "Error: %s" , e.what() );
        return 1;
    }
    return 0;
}
 