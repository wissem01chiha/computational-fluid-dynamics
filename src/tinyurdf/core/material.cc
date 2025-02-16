#include "core/material.h"
#include <filesystem>

Material::Material()
: name(""), texture_filename(""), density(1.0) {
    color = std::make_shared<Color>();
}

void Material::clear() {
    name.clear();
    texture_filename.clear();
    if (color) {
        color->clear();
    }
    density = 0.0;
}

void Material::setFilename(std::string& path) {
    if (!std::filesystem::exists(path)) {
        LOG_F(ERROR, "Invalid file path: %s. File does not exist.", path.c_str());
        return;
    }
    texture_filename = path;
}

void Material::setName(const std::string& name_) {
    if (!name_.empty()) {
        name = name_;
    }
}

std::string Material::getName() const { 
    return name; 
}

void Material::setDensity(double d) {
    if (d > 0) {
        density = d;
    }
}

void Material::setColor(double r, double g, double b, double a) {

    if (!color) {
        color = std::make_shared<Color>();
    }
    color->set(r, g, b, a);
}

bool Material::isA(const char* name)  const {
    return std::string(name) == "material";
}

std::string Material::toString() const {

    std::ostringstream os;
    os << "Material : [ name=" << name
       << ", color=";
    if (color) {
        os << color->toString();
    } else {
        os << "None";
    }
    os << ", texture file=" << texture_filename
       << ", density=" << density << " ]";
    return os.str();
}