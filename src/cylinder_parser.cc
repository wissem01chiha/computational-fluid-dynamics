#include "cylinder_parser.h"

CylinderParser::CylinderParser() {
  p_ = std::make_shared<Cylinder>();
}

void CylinderParser::parse(const tinyxml2::XMLElement* xml) {
  ParserBase<Cylinder>::parse(xml);

  const char* radius_str = xml->Attribute("radius");
  const char* length_str = xml->Attribute("length");
  if (radius_str && length_str) {
    double r, l;
    str2double(radius_str, r);
    str2double(length_str, l);
    p_ = std::make_shared<Cylinder>();
    p_->setRadius(r);
    p_->setLength(l);
  }
}

bool CylinderParser::isA(const char* name) {
  return p_->isA(name);
}

const char* CylinderParser::getTypename() {
  return p_->getTypename();
}

void CylinderParser::print(std::ostream& os) {
  os << "Parsed Cylinder = [";
  p_->print(os);
  os << "]";
}

bool CylinderParser::empty() const {
  return p_ == nullptr;
}

void CylinderParser::clear() {
  p_->clear();
}

std::shared_ptr<Cylinder> CylinderParser::get() {
  return p_;
}