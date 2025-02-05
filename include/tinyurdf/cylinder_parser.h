#ifndef INCLUDE_TINYURDF_GEOMETRY_CYLINDER_PARSER_H_
#define INCLUDE_TINYURDF_GEOMETRY_CYLINDER_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <memory>
#include "parser_base.h"
#include "geometry_base.h"
#include "cylinder.h"
#include "utils.h"

/**
 * @brief Parser for Cylinder geometry, inherits from ParserBase<Cylinder>
 * and provides the functionality to parse the cylinder geometry from XML.
 */
class CylinderParser : public ParserBase<Cylinder> {
public:
  CylinderParser() {
    p_ = std::make_shared<Cylinder>();
  }

  void parse(const tinyxml2::XMLElement* xml) override {
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

  bool isA(const char* name) override {
    return p_->isA(name);
  }

  const char* getTypename() override {
    return p_->getTypename();
  }

  void print(std::ostream& os) override {
    os << "Parsed Cylinder = [";
    p_->print(os);
    os << "]";
  }

  bool empty() const override {
    return p_ == nullptr;
  }

  void clear() override {
    p_->clear();
  }

  std::shared_ptr<Cylinder> get() override {
    return p_;
  }

  ~CylinderParser() = default;

private:
  std::shared_ptr<Cylinder> p_;
};
#endif  // INCLUDE_TINYURDF_GEOMETRY_CYLINDER_PARSER_H_
