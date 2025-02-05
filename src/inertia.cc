#include "inertia.h"

Inertia::Inertia() {
    origin = std::make_shared<Pose>();
    mass = 0.0;
    ixx = ixy = ixz = iyy = iyz = izz = 0.0;
}

Inertia::Inertia(double mass, double ixx, double ixy, double ixz, double iyy, double iyz, double izz) 
    : mass(mass), ixx(ixx), ixy(ixy), ixz(ixz), iyy(iyy), iyz(iyz), izz(izz) {
}

bool Inertia::isA(const char* name) {
    return std::string(name) == "inertia";
}

bool Inertia::validate() const {
    if (mass <= 0) {
        LOG_F(WARNING, "Mass must be positive: %f", mass);
        return false;
    }
    if (ixx <= 0 || iyy <= 0 || izz <= 0) {
        LOG_F(WARNING, 
              "Principal moments of inertia must be positive: ixx=%f, iyy=%f, izz=%f",
              ixx, iyy, izz);
        return false;
    }
    if (std::abs(ixy) > std::sqrt(ixx * iyy) ||
        std::abs(ixz) > std::sqrt(ixx * izz) ||
        std::abs(iyz) > std::sqrt(iyy * izz)) {
        LOG_F(WARNING,
              "Products of inertia are invalid: ixy=%f, ixz=%f, iyz=%f",
              ixy, ixz, iyz);
        return false;
    }
    return true;
}

void Inertia::clear() {
    origin->clear();
    mass = 0.0;
    ixx = ixy = ixz = iyy = iyz = izz = 0.0;
}

void Inertia::print(std::ostream& os)  {
    os << "Inertia = [" 
       << "mass=" << mass 
       << ", ixx=" << ixx << ", ixy=" << ixy << ", ixz=" << ixz 
       << ", iyy=" << iyy << ", iyz=" << iyz << ", izz=" << izz 
       << "]";
}

const char *Inertia::getTypename()
{
    return "inertia";
}

bool Inertia::empty() const
{
    return false;
}

void Inertia::setOrigin(double x, double y, double z)
{
    origin->setPosition(x,y,z);
}

void Inertia::getOrigin(double *xyz) const
{
    Vec3 v = origin->getPosition();
    xyz[0] = v[0]; xyz[1]=v[1]; xyz[2]=v[2];
}

void Inertia::setMass(const double m)
{
    if(m>0){mass=m;}
}

void Inertia::setIxx(double ixx_)
{
    ixx =ixx_;
}

void Inertia::setIxy(double ixy_)
{
    ixy =ixy_;
}

void Inertia::setIxz(double ixz_)
{
    ixz = ixz_;
}

void Inertia::setIyy(double iyy_)
{
    iyy = iyy_;
}

void Inertia::setIyz(double iyz_)
{
    iyz = iyz_;
}

void Inertia::setIzz(double izz_)
{
    izz = izz_;
}
