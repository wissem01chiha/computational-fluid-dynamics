#include "visual.h"

Visual::Visual() {
    origin = std::make_shared<Pose>();
    geometry = nullptr;
    material = std::make_shared<Material>();
    material_name = std::string("");
}

Visual::~Visual() {
    this->clear();
}

void Visual::clear() {
    origin->clear();
    geometry.reset();
    material_name.clear();
    material.reset();
}

bool Visual::isA(const char* name) {
    return std::string(name) == "visual";
}

void Visual::setOrigin(std::shared_ptr<Pose> o) {

    if (o) {origin = o;}
}

void Visual::getOrigin(double* xyz) const {
    const auto vec = origin->getPosition();
    for (size_t i = 0; i < 3; i++) {
        xyz[i] = vec[i];
    }
}

std::shared_ptr<Pose> Visual::getPose() const
{
    return origin;
}

void Visual::print(std::ostream& os) {
    os << "Visual = [";
    if (material) {
        material->print(os);
    }
    os << ", " << "Origin = ";
    if (origin) {
        origin->print(os);
    }
    os << ", " << "Geometry = ";
    if (geometry) {
        geometry->print(os);
    }
    os << "]";
}


bool Visual::empty() const
{
    return false;
}

const char *Visual::getTypename()
{
    return "visual";
}

void Visual::setMaterial(std::shared_ptr<Material> mat)
{
    if(mat){material =mat;}
}

void Visual::setMaterialName(const std::string& name) {
    if (!name.empty()) {
        material_name = name;
    }
};

void Visual::setGeometry(std::shared_ptr<GeometryBase> geo){
    if (geo){this->geometry= geo;}
}

std::shared_ptr<GeometryBase> Visual::getGeometry() const
{
    return geometry;
}
