#include "model.h"

Model::Model()
{
  name= std::string("");
}

Model::Model(const Model &rhs)
{
  name= rhs.name;
  joints= rhs.joints;
  links= rhs.links;
}

void Model::clear()
{
  name= std::string("");
  joints.clear();
  links.clear();
}

void Model::setName(const std::string &name)
{
  if(!name.empty()){this->name= name;};
}

std::string Model::getName() const
{
  return name;
}

bool Model::isA(const char *name)
{
  return std::string(name)=="model";
}

void Model::print(std::ostream &os) 
{
  os << "Model :[" << name.c_str();
  os << ", links: [";
  for(auto link :links){
    if(link){link->print(os);}
  }
  os << ", ";
  for(auto joint :joints){
    if(joint){joint->print(os);}
  }
  os << "]\n";
}

const char *Model::getTypename()
{
  return "model";
}

bool Model::empty() const
{
  return links.empty() && joints.empty();
}

void Model::setLink(std::shared_ptr<Link> link)
{
  if(link){links.push_back(link);}
}

void Model::setLink(std::vector<std::shared_ptr<Link>> link)
{
  if(!link.empty()){links= link;}
}

void Model::setJoint(std::vector<std::shared_ptr<Joint>> joint)
{
  if(!joint.empty()){joints= joint;}
}

void Model::setJoint(std::shared_ptr<Joint> joint)
{
  if(joint){joints.push_back(joint);}
}

void Model::setJoint(std::shared_ptr<Joint> joint, const std::string &parent, const std::string &child)
{
  if(joint){
    joint->pushBackParent(parent);
    joint->pushBackParent(child);
    joints.push_back(joint);
  }
}

std::vector<std::shared_ptr<Joint>> Model::getJoints() const
{
  return this->joints;
}

std::vector<std::shared_ptr<Link>> Model::getLinks() const
{
  return this->links;
}

Model::~Model()
{
}
