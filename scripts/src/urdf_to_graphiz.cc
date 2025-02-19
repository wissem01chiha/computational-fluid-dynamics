/**
 * @file urdf_to_graphiz.cc
 * This file is part of TINYURDF
 * it was orginally  refactored from : urdfom package 
 * a similar version is located at : 
 * https://docs.ros.org/en/diamondback/api/urdf/html/urdf__to__graphiz_8cpp_source.html
 * @usage:
 *  urdf_to_graphiz --file ./path/to/model/file [--log]
 */
#include <cxxopts/cxxopts.hpp>
#include "tinyurdf/internal/urdf_parser.h"
#include "tinyurdf/detail/internal_graph.h"

int main(int argc, char** argv)
{
  if (argc != 2){
    LOG_F(ERROR, "Usage: urdf_to_graphiz input_file.urdf" );
    return -1;
  }
 
  // TiXmlDocument robot_model_xml;
  //  robot_model_xml.LoadFile(argv[1]);
  //  TiXmlElement *robot_xml = robot_model_xml.FirstChildElement("robot");
  //  if (!robot_xml){
  //   std::cerr << "ERROR: Could not load the xml into TiXmlElement" << std::endl;
  //   return -1;
  //  }

  // Model robot;
  // if (!robot.initXml(robot_xml)){
  //    LOG_F(ERROR, "ERROR: Model Parsing the xml failed" );
  //    return -1;
  //  }
  //  std::string output = robot.toString();
 
  // printTree(robot.getRoot(), output+".gv");
  // std::cout << "Created file " << output << ".gv" << std::endl;
 
  // std::string command = "dot -Tpdf "+output+".gv  -o "+output+".pdf";
  // system(command.c_str());
  LOG_F(INFO, "Created file .pdf" );
  return 0;
 }