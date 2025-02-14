#include "core/color.h"

Color::Color()
{
    r = g = b = static_cast<double>(0.0);
    a = static_cast<double>(1.0);
}

Color &Color::operator=(const Color &rhs)
{
    if (this != &rhs) {
        PropertyBase::operator=(rhs);
        r = rhs.r;
        g = rhs.g;
        b = rhs.b;
        a = rhs.a;
    }
    return *this;
}

Color::Color(const double& r_,const double& g_,const double& b_,const double& a_)
{
    if (r_ < static_cast<double>(0.0) || r_ > static_cast<double>(1.0) ||
        g_ < static_cast<double>(0.0) || g_ > static_cast<double>(1.0) ||
        b_ < static_cast<double>(0.0) || b_ > static_cast<double>(1.0) ||
        a_ < static_cast<double>(0.0) || a_ > static_cast<double>(1.0))
    {
        LOG_F(ERROR, "RGBA values must be in the range [0.0, 1.0]. Received: r=%f, g=%f, b=%f, a=%f", 
            static_cast<double>(r_), static_cast<double>(g_), 
            static_cast<double>(b_), static_cast<double>(a_));
        throw std::invalid_argument("RGBA values out of range [0.0, 1.0]");
    }
    r = r_; g = g_; b = b_; a = a_;
}

void Color::clear()
{
    r = g = b = static_cast<double>(0.0);
    a = static_cast<double>(1.0);
}

std::string  Color::toString() const 
{
    std::ostringstream os;
    os << "Color RGBA : [" << r << ", " << g << ", " << b << ", " << a << "]";
    return os.str();
} 

Color::~Color()
{
}

double Color::getR() const
{
    return r;
}

double Color::getG() const
{
    return g;
}

double Color::getB() const
{
    return b;
}

double Color::getA() const
{
    return a;
}

void Color::set(double &r_, double &g_, double &b_, double &a_)
{
    r = r_; g = g_; b = b_; a = a_;  
}

Color::Color(const Type type_)
{
    switch (type_)
    {
    case Type::Red:
        r = 1.0; g = 0.0; b = 0.0; a = 1.0;  
        break;  
    case Type::Green:
        r = 0.0; g = 1.0; b = 0.0; a = 1.0;
        break;
    case Type::Blue:
        r = 0.0; g = 0.0; b = 1.0; a = 1.0;
        break;
    case Type::Black:
        r = 0.0; g = 0.0; b = 0.0; a = 1.0;
        break;
    case Type::White:
        r = 1.0; g = 1.0; b = 1.0; a = 1.0;
        break;
    case Type::Yellow:
        r = 1.0; g = 1.0; b = 0.0; a = 1.0;
        break;
    case Type::Cyan:
        r = 0.0; g = 1.0; b = 1.0; a = 1.0;
        break;
    case Type::Magenta:
        r = 1.0; g = 0.0; b = 1.0; a = 1.0;
        break;
    default:
        r = 0.0; g = 0.0; b = 0.0; a = 1.0;  
        break;
    }
}

Color::Color(const std::string &vector_str)
{
    this->clear();
    std::vector<std::string> pieces;
    std::vector<double>       rgba;
    std::istringstream stream(vector_str);
    std::string piece;
    while (stream >> piece) {
    
        rgba.push_back(std::atof(piece.c_str()));
    }
    if (rgba.size() != 4)
    {
        LOG_F(ERROR, "Color contains %i elements instead of 4 elements", (int)rgba.size());
        return;
    }
    this->r = rgba[0];
    this->g = rgba[1];
    this->b = rgba[2];
    this->a = rgba[3];
} 

bool Color::isA(const char *name) const 
{
    return std::string(name) == "color";
}