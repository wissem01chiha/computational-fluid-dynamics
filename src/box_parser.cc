#include "box_parser.h"

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

bool BoxParser::isA(const char* name) {
  return p_->isA(name);
}

const char* BoxParser::getTypename() {
  return p_->getTypename();
}

void BoxParser::print(std::ostream& os)  {
  os << "Parsed Box = [";
  p_->print(os);
  os << "]";
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
