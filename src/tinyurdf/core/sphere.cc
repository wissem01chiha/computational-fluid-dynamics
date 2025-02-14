#include "core/sphere.h"

Sphere::Sphere() {
    this->radius = 1.0;
}

Sphere::Sphere(double r)
{
    this->setRadius(r);
}

bool Sphere::isA(const char* name) const {
    return std::string(name) == "sphere";
} 

std::string Sphere::toString() const {
    std::ostringstream os;
    os << "Sphere radius = " << this->radius << "]";
    return os.str();
}

void Sphere::clear() {
    this->radius = 0.0;
}

const char *Sphere::getTypename() const
{
    return "sphere";
}

double Sphere::getRadius() const {
    return radius;
}

void Sphere::setRadius(double r) {
    if (r <= 0) {
        LOG_F(ERROR, 
        "Attempt to set sphere radius to a non-positive value: %f", r);
        return;
    }
    radius = r;
}

void Sphere::setOrigin(double x, double y, double z) {
   
}

void Sphere::getOrigin(double* xyz) const {
    
}

double Sphere::getRadius()
{
    return radius;
}

bool Sphere::empty() const
{
    return false;
}
