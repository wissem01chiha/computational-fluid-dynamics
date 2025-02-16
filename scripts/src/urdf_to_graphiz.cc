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
#include "core/model.h"
#include <iostream>

void addChildLinkNames(std::shared_ptr<Link> link, std::string& str)
{
  std::ostringstream os;
  os << "\"" << link->getName() << "\" [label=\"" << link->getName() << "\"];" << std::endl;
  //for (std::vector<std::shared_ptr<Link>>::const_iterator child = link->child_links.begin(); child != link->child_links.end(); child++)
  //addChildLinkNames(*child, os);
}

// void addChildJointNames(std::shared_ptr<Link> link, ofstream& os)
// {
//   double r, p, y;
//   for (std::vector<std::shared_ptr<Link> >::const_iterator child = link->child_links.begin(); child != link->child_links.end(); child++){
//     (*child)->parent_joint->parent_to_joint_origin_transform.rotation.getRPY(r,p,y);
//     os << "\"" << link->name << "\" -> \"" << (*child)->parent_joint->name 
//        << "\" [label=\"xyz: "
//        << (*child)->parent_joint->parent_to_joint_origin_transform.position.x << " " 
//        << (*child)->parent_joint->parent_to_joint_origin_transform.position.y << " " 
//        << (*child)->parent_joint->parent_to_joint_origin_transform.position.z << " " 
//         << "\\nrpy: " << r << " " << p << " " << y << "\"]" << endl;
//     os << "\"" << (*child)->parent_joint->name << "\" -> \"" << (*child)->name << "\"" << endl;
//      addChildJointNames(*child, os);
//    }
//  }


// void printTree(std::shared_ptr<Link> link, std::string file)
// {
//   std::ofstream os;
//    os.open(file.c_str());
//    os << "digraph G {" << std::endl;
 
//   os << "node [shape=box];" << std::endl;
//   addChildLinkNames(link, os);

//    os << "node [shape=ellipse, color=blue, fontcolor=blue];" << std::endl;
//   addChildJointNames(link, os);
 
//    os << "}" << std::endl;
//    os.close();
//  }
 
 
 
int main(int argc, char** argv)
{
  if (argc != 2){
    LOG_F(ERROR, "Usage: urdf_to_graphiz input.urdf" );
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
  std::cout << "Created file " << "test" << ".pdf" << std::endl;
  return 0;
 }