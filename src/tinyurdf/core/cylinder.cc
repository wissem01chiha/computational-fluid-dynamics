#include "core/cylinder.h"

Cylinder::Cylinder() {
    this->clear();
}

Cylinder::Cylinder(double r, double l)
{
    radius =r; length =l;
}

bool Cylinder::isA(const char* name) const  {
    return std::string(name) == "cylinder";
}

std::string Cylinder::toString() const   {
    std::ostringstream os;
    os << "Cylinder dimensions: [" << length << ", " << radius << "]";
    return os.str();
}

void Cylinder::clear() {
    length = 0.0;
    radius = 0.0;
}

bool Cylinder::empty() const
{
    return false;
}

const char *Cylinder::getTypename() const 
{
    return "cylinder";
}

void Cylinder::setOrigin(double x, double y, double z) {
 
}

void Cylinder::getOrigin(double* xyz) const {
    
}

void Cylinder::setLength(double l)
{
    if(l>0){length =l;}
} 

void Cylinder::setRadius(double r)
{
    if(r>0){radius=r;}
}

double Cylinder::getLength() 
{
    return length;
}

double Cylinder::getRadius() 
{
    return radius;
}
