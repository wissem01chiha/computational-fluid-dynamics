#include "mesh.h"

Mesh::Mesh() {
    this->clear();
}

Mesh::~Mesh() {
    this->clear();
}

bool Mesh::isA(const char* name) {
    return std::string(name) == "mesh";
}

void Mesh::clear() {
    color.clear();
    filename.clear();
    scale.setOnes();
}

void Mesh::setFilename(const std::string& path) {
    if (!std::filesystem::exists(path)) {
        LOG_F(ERROR, "Invalid file path: %s. File does not exist.",
         path.c_str());
        return;
    }
    filename = path;
}

std::string Mesh::getFilename()
{
    return filename;
}

void Mesh::setScale(double xs, double ys, double zs) {
    if (xs < 0 || xs > 1 || ys < 0 || ys > 1 || zs < 0 || zs > 1) {
        LOG_F(ERROR, "Invalid scale values: xs = %f, ys = %f, zs = %f.\
         Each value must be between 0 and 1.", xs, ys, zs);
        return;
    }
    scale[0] = xs;
    scale[1] = ys;
    scale[2] = zs;
}

Vec3 Mesh::getScale() 
{
    return scale;
}

void Mesh::setColor(Color c) {
    color = c;
}

void Mesh::setColor(double r, double g, double b, double a) {
    color = Color(r, g, b, a);
}

void Mesh::print(std::ostream& os) {
    os << "Mesh file: [" << filename.c_str() << "]\n";
    os << "Mesh scale XYZ : [" << scale[0] << ", " << scale[1] << ", " << scale[2] << "]\n";
    os << "Mesh color : [";
    color.print(os);
    os << "]";
}

void Mesh::setOrigin(double x, double y, double z) {
   
}

void Mesh::getOrigin(double* xyz) const {
    
}

bool Mesh::empty() const
{
    return false;
}

const char *Mesh::getTypename()
{
    return "mesh";
}
