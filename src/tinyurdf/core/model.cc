#include "core/model.h"

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

bool Model::isA(const char *name) const
{
  return std::string(name)=="model";
}

std::string Model::toString() const 
{
  std::ostringstream os;
  os << "Model :[" << name.c_str();
  os << ", links: [";
  for(auto link :links){
    if(link){ os << link->toString();}
  }
  os << ", ";
  for(auto joint :joints){
    if(joint){os << joint->toString();}
  }
  os << "]\n";
  return os.str();
}

const char *Model::getTypename() const
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

std::vector<std::shared_ptr<Material>> Model::getMaterials() const
{
  
  std::vector<std::shared_ptr<Material>> mts;
  #ifdef USE_OPENMP
  #pragma omp parallel
  {
    std::vector<std::shared_ptr<Material>> local_mts;
      
    #pragma omp for nowait
    for (size_t i = 0; i < this->links.size(); ++i) {
        local_mts.push_back(this->links[i]->getMaterial());
    }
    
    #pragma omp critical
    {
      mts.insert(mts.end(), local_mts.begin(), local_mts.end());
    }
  }
  #else
    for (const auto& lk : this->links) {
        mts.push_back(lk->getMaterial());
    }
  #endif
  return mts;
}

std::vector<std::string> Model::getMaterialsName() const
{
  std::vector<std::shared_ptr<Material>> mts = this->getMaterials();
  std::vector<std::string> mts_str;
  #ifdef USE_OPENMP

  #else
    for(const auto mt: mts){
      mts_str.push_back(mt->getName());
    }
  #endif 
  return mts_str;
}

Model::~Model(){}
