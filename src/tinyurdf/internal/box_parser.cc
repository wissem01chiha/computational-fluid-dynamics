#include "internal/box_parser.h"

BoxParser::BoxParser() {
  p_ = std::make_shared<Box>();
}

void BoxParser::parse(const tinyxml2::XMLElement* xml) {
  ParserBase<Box>::parse(xml);

  const char* size_str = xml->Attribute("size");
  if (size_str) {
    double v[3];
    str2array(size_str, v);
    p_ = std::make_shared<Box>(v[0], v[1], v[2]);
  }
}

bool BoxParser::isA(const char* name) const {
  return p_->isA(name);
}

const char* BoxParser::getTypename() const {
  return p_->getTypename();
}

std::string BoxParser::toString() const  {

  std::ostringstream os;
  os << "Parsed Box = [";
  os << p_->toString();
  os << "]";
  return os.str();
}

bool BoxParser::empty() const {
  return p_ == nullptr;
}

void BoxParser::clear() {
  p_->clear();
}

std::shared_ptr<Box> BoxParser::get() {
  return p_;
}

BoxParser::~BoxParser() = default;
