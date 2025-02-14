#include "internal/sphere_parser.h"

SphereParser::SphereParser() {
  p_ = std::make_shared<Sphere>();
}

void SphereParser::parse(const tinyxml2::XMLElement* xml) {
  ParserBase<Sphere>::parse(xml);

  const char* radius_str = xml->Attribute("radius");
  if (radius_str) {
    double r;
    str2double(radius_str, r);
    p_ = std::make_shared<Sphere>();
    p_->setRadius(r);
  }
}

bool SphereParser::isA(const char* name) const {
  return p_->isA(name);
}

const char* SphereParser::getTypename()  const {
  return p_->getTypename();
}

std::string SphereParser::toString() const {

  std::ostringstream os;
  os << "Parsed Sphere = [";
  os << p_->toString();
  os << "]";
  return os.str();
  
}

bool SphereParser::empty() const {
  return p_ == nullptr;
}

void SphereParser::clear() {
  p_->clear();
}

std::shared_ptr<Sphere> SphereParser::get() {
  return p_;
}
