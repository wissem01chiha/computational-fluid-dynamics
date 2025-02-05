#include "camera.h"

Camera::Camera()
{
}

Camera::Camera(const Camera &rhs)
{
}

void Camera::reset()
{
    type= Type::B8G8R8;
}

void Camera::getOrigin(double *xyz) const
{
    const auto vec = origin->getPosition();
    for(size_t i=0;i<3; i++){
        xyz[i] =vec[i];
    } 
}

void Camera::setType(Type t_)
{
}

void Camera::setType(const char *c)
{
}

void Camera::setUpdateRate(double ur)
{
    if(ur>0){
        update_rate = ur;
    }
}

void Camera::getUpdateRate(double &ur) const
{   
    if(ur>0){ur = update_rate;}
}

void Camera::setOrigin(std::shared_ptr<Pose> o)
{
    if(o){origin =o;}
}

const char *Camera::getTypename()
{
    return "camera";
}

void Camera::getRange(Image<double,4> &r)
{
}

void Camera::setRange(Image<double,4> &r)
{
}

void Camera::get(Image<double,4> &o) const
{
}

void Camera::print(std::ostream &os) 
{
    os << "Camera : " 
    << " [Type: " << static_cast<int>(type);
    os << ", ";
    origin->print(os);
    os << ", hfov = " << hfov << ", far = " << far << ", near = "<< near 
    << ", update_ rate =" << update_rate << "]\n";
}
