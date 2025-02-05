#include "link.h"

Link::Link()
{
    this->name = std::string("Link");
    this->inertial = std::make_shared<Inertia>();
    this->visual = std::make_shared<Visual>();
    this->material = std::make_shared<Material>();
    this->collision = std::make_shared<Collision>();
}

bool Link::isA(const char *name)
{
    return std::string(name)== "Link";
}

void Link::clear()
{
    this->name.clear();
    this->inertial.reset();
    this->visual.reset();
    this->collision.reset();
}

void Link::print(std::ostream &os) 
{
    os << "Link : [" <<  name.c_str() << ", ";
    if(visual){
      visual->print(os);
    }
    os << ", ";
    if(inertial){
       inertial->print(os);
    }
    os << ", ";
    if(collision){
      collision->print(os);
    }
    os << "]";
}

bool Link::empty() const
{
    return false;
}

const char *Link::getTypename()
{
    return "link";
}

void Link::setName(const std::string &name)
{
    if(!name.empty()){this->name = name;}
}

std::string Link::getName() const
{
    return name;
}

void Link::setInertia(const std::shared_ptr<Inertia> i)
{
    if(i){inertial =i;}
}

std::shared_ptr<Inertia> Link::getInertia() const
{
    return inertial;
}

void Link::setVisual(const std::shared_ptr<Visual> v)
{
    if(v){visual = v;}
}

std::shared_ptr<Visual> Link::getVisual() const
{
    return visual;
}

void Link::setMaterial(const std::shared_ptr<Material> m)
{
    if(m){material = m;}
}

std::shared_ptr<Material> Link::getMaterial() const
{
    return material;
}

void Link::setCollision(const std::shared_ptr<Collision> c)
{
    if(c){ this->collision = c;}
}

void Link::setCollisionGeometry(const std::shared_ptr<GeometryBase> g)
{

    if(g){collision->setGeometry(g);}  
}

void Link::setVisualGeometry(const std::shared_ptr<GeometryBase> g)
{
    if(g){visual->setGeometry(g);}
}

std::shared_ptr<Collision> Link::getCollision() const
{
    return collision;
}

Link::~Link(){}

void Link::getOrigin(double *pos) const
{
    visual->getOrigin(pos);
}

void Link::setVisualOrigin(std::shared_ptr<Pose> o)
{
    visual->setOrigin(o);
}

void Link::setCollisionOrigin(std::shared_ptr<Pose> o) {

    collision->setOrigin(o);
};
