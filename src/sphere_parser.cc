#include "sphere_parser.h"

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

bool SphereParser::isA(const char* name) {
  return p_->isA(name);
}

const char* SphereParser::getTypename() {
  return p_->getTypename();
}

void SphereParser::print(std::ostream& os) {
  os << "Parsed Sphere = [";
  p_->print(os);
  os << "]";
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
