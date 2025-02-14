#include "core/joint.h"

Joint::Joint(){ 
    dynamics = std::make_shared<JointDynamics>();
    limits  = std::make_shared<JointLimits>();
    safety  = std::make_shared<JointSafety>();
    calibration = std::make_shared<JointCalibration>();
    mimic = std::make_shared<JointMimic>();
    type = Type::UNKNOWN;
    axis.setZero();
}

Joint::Joint(const Joint &rhs)
{
    this->type = rhs.type;
    this->axis = rhs.axis;
    this->name = rhs.name;
    this->child = rhs.child;
    this->parent = rhs.parent;
    this->transform = rhs.transform;
    if (rhs.dynamics) { dynamics = std::make_shared<JointDynamics>(*rhs.dynamics);  }
    if (rhs.limits) { limits = std::make_shared<JointLimits>(*rhs.limits); }
    if (rhs.safety) { safety = std::make_shared<JointSafety>(*rhs.safety); }
    if (rhs.calibration) { calibration = std::make_shared<JointCalibration>(*rhs.calibration);}
    if (rhs.mimic) { mimic = std::make_shared<JointMimic>(*rhs.mimic); }
}

Joint::Joint(Joint &&rhs) noexcept
{
}

void Joint::clear()
{
    this->axis.setZero();
    this->dynamics.reset();
    this->limits.reset();
    this->safety.reset();
    this->calibration.reset();
    this->type = Type::UNKNOWN;
}

bool Joint::isA(const char *name) const
{
    return std::string(name) == "joint";
}

std::string Joint::toString() const 
{
    std::ostringstream os;
    os << "Joint : " << name.c_str() 
    << " [Type: " << static_cast<int>(type)  
    << ", Axis: (" << axis[0] << ", " << axis[1] << ", " << axis[2] << ")"
    << ", Parent Links: [";

    for (size_t i = 0; i < parent.size(); ++i) {
        os << parent[i];
        if (i < parent.size() - 1) os << ", ";
    }

    os << "], Child Links: [";

    for (size_t i = 0; i < child.size(); ++i) {
        os << child[i];
        if (i < child.size() - 1) os << ", ";
    }
    os << "], ";

    if (dynamics)  os << dynamics->toString();
    os << ", ";
    if (calibration)  os << calibration->toString();
    os << ", ";
    if (safety) os << safety->toString();
    os << ", ";
    if (mimic) os << mimic->toString();
    os << ", Transformations: [";
    for (size_t i = 0; i < transform.size(); ++i) {
        os << transform[i]->toString();
        if (i < transform.size() - 1) os << ", ";
    }
    os << "]\n";
    return os.str();
}

bool Joint::empty() const
{
    return false;
}

const char *Joint::getTypename() const 
{
    return "joint";
}

void Joint::setDynamics(const std::shared_ptr<JointDynamics> d)
{
    if(d){dynamics = d;}
}

void Joint::setLimits(const std::shared_ptr<JointLimits> l)
{
    if(l){limits =l;}
}

void Joint::setSafety(const std::shared_ptr<JointSafety> s)
{
    if(s){safety =s;}
}

void Joint::setCalibration(const std::shared_ptr<JointCalibration> c)
{
    if(c){calibration =c;}
}

void Joint::setMimic(const std::shared_ptr<JointMimic> m)
{
    if(m){mimic =m;}
}

void Joint::setName(const std::string &name_)
{
    if(!name_.empty()){
        this->name= name_;
    }
}

void Joint::setType(const Type &t_)
{
    type = t_;
}

void Joint::setType(const char *c_)
{
    if(std::strcmp(c_, "revolute")==0){
      this->type = Type::REVOLUTE;
    }else if(std::strcmp(c_, "fixed")==0){
        this->type = Type::FIXED;
    }else if(std::strcmp(c_, "planner")==0){
        this->type = Type::PLANAR;
    }else if(std::strcmp(c_, "floating")==0){
        this->type = Type::FLOATING;
    }else if(std::strcmp(c_, "continus")==0){
        this->type = Type::CONTINUOUS;
    }else if(std::strcmp(c_, "prismatric")==0){
        this->type = Type::PRISMATIC;
    }else if(std::strcmp(c_, "universal")==0){
        this->type = Type::UNIVERSAL;
    }else
    {this->type = Type::UNKNOWN;}
}

void Joint::setAxis(double x, double y, double z)
{
    this->axis[0] = x; this->axis[1]=y; this->axis[2]=z;
}

std::string Joint::getName() const
{
    return this->name;
}

void Joint::pushBackChild(const std::string lk)
{
    if(!lk.empty()){this->child.push_back(lk);}
}

void Joint::pushBackParent(const std::string lk)
{
    if(!lk.empty()){this->parent.push_back(lk);}
}

void Joint::pushBackTransform(const std::shared_ptr<Pose> tr)
{
    if(tr){ this->transform.push_back(tr);}
}
bool Joint::isChild(const char *name) const
{
    auto it = std::find(this->child.begin(), this->child.end(), std::string(name));
    return it!= this->child.end();
}
bool Joint::isParent(const char *name) const
{
    auto it = std::find(this->parent.begin(), this->parent.end(), std::string(name));
    return it!= this->parent.end();
}
std::vector<std::shared_ptr<Pose>> Joint::getTransform() const
{
    return this->transform;
}
Vec3 Joint::getAxis() const
{
    return axis;
};