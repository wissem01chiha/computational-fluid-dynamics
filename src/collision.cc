#include "collision.h"

Collision::Collision() {

    geometry = nullptr;
    origin = std::make_shared<Pose>();
}

bool Collision::isA(const char* name) {
    return std::string(name) == "collsion";
}

void Collision::clear() {
     
    geometry.reset();
    origin.reset();
}

void Collision::print(std::ostream& os)  {
    os << "Collision = [" << "Geometry = ";
    if (geometry) {
        geometry->print(os);
    }
    os << ", " << "Origin = ";
    if (origin) {
        origin->print(os);
    }
    os << "]";
}

void Collision::setGeometry(std::shared_ptr<GeometryBase> geo) {

    if (geo) {geometry = geo;}
}

std::shared_ptr<GeometryBase> Collision::getGeometry() const
{
    return geometry;
}

void Collision::setOrigin(std::shared_ptr<Pose> o_) {

    if (o_) {origin = o_;}
}

void Collision::getOrigin(double* xyz) const {
    const auto vec = origin->getPosition();
    for (size_t i = 0; i < 3; i++) {
        xyz[i] = vec[i];
    }
}
