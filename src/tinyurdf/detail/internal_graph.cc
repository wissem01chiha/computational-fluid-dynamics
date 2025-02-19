#include "detail/internal_graph.h"

#ifdef USE_OPENMP
  #include <omp.h>
#endif 

InternalGraph::InternalGraph() {}

InternalGraph::InternalGraph(Model m) {

  this->m_ = std::make_shared<Model>(m);
}

InternalGraph::InternalGraph(std::shared_ptr<Model> m) {

  if(m){
    this->m_ = m;
  }
}

std::vector<std::shared_ptr<Link>> InternalGraph::getRootLinks() {
  return std::vector<std::shared_ptr<Link>>();
}

std::vector<std::shared_ptr<Link>>
InternalGraph::getChildLinks(std::shared_ptr<Link> link) {

  std::vector<std::shared_ptr<Link>> clks;
  #ifdef USE_OPENMP

  #else
    for (const auto joint : m_->getJoints())
    {
      if (joint->isParent(link->getName().c_str()))
      {
        std::vector<std::string> joint_child_links_names = joint->getChild();
        for (const auto link_name : joint_child_links_names )
        {
          for(const auto model_link : m_->getLinks()){

            if(model_link->getName() == link_name){
              clks.push_back(model_link);
            }
          }
        }
      }
    }
  #endif 
  return clks;
}

std::vector<std::shared_ptr<Link>>
InternalGraph::getParentLinks(std::shared_ptr<Link> link) {

  std::vector<std::shared_ptr<Link>> plks;
  #ifdef USE_OPENMP

  #else
    for (const auto joint : m_->getJoints())
    {
      if (joint->isChild(link->getName().c_str()))
      {
        std::vector<std::string> joint_child_links_names = joint->getChild();
        for (const auto link_name : joint_child_links_names )
        {
          for(const auto model_link : m_->getLinks()){

            if(model_link->getName() == link_name){
              plks.push_back(model_link);
            }
          }
        }
      }
    }
  #endif 
  return plks;
}

std::vector<std::string>
InternalGraph::getChildLinkNames(std::shared_ptr<Link> link) {

  std::vector<std::string> clkn;
  //for (std::vector<std::shared_ptr<Link>>::const_iterator child = link->child_links.begin(); child != link->child_links.end(); child++)
  //addChildLinkNames(*child, os);
  return clkn;
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

void printGraph(std::shared_ptr<Link> link, std::string file_path)
{
//   std::ofstream os;
//    os.open(file.c_str());
//    os << "digraph G {" << std::endl;
 
//   os << "node [shape=box];" << std::endl;
//   addChildLinkNames(link, os);

//    os << "node [shape=ellipse, color=blue, fontcolor=blue];" << std::endl;
//   addChildJointNames(link, os);
 
//    os << "}" << std::endl;
//    os.close();
}
 