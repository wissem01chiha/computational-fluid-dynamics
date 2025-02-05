#include "box.h"

Box::Box()
{
}

Box::Box(double *xyz)
{
    dim[0] = xyz[0];
    dim[1] = xyz[1];
    dim[2] = xyz[2];
}

Box::Box(double x, double y, double z) {
    dim[0] = x;
    dim[1] = y;
    dim[2] = z;
}

bool Box::isA(const char* name) {
    return std::string(name) == "box";
}

const char *Box::getTypename()
{
    return "box";
}

bool Box::empty() const
{
    return false;
}

void Box::print(std::ostream& os)  {
    os << "Box dimensions: [" << dim[0] << ", " << dim[1] << ", " << dim[2] << "]";
}

void Box::setOrigin(double x, double y, double z) {
    dim[0] = 2 * x;
    dim[1] = 2 * y;
    dim[2] = 2 * z;
}

void Box::getOrigin(double* xyz) const {
    for (size_t i = 0; i < 3; i++) {
        xyz[i] = dim[i];
    }
}

void Box::clear() {
    this->dim.setZero();
}

Vec3 Box::getDim() const
{
    return dim;
}

Box::~Box() {
    this->clear();
}