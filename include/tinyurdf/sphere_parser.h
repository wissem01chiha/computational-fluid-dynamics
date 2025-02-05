#ifndef INCLUDE_TINYURDF_GEOMETRY_SPHERE_PARSER_H_
#define INCLUDE_TINYURDF_GEOMETRY_SPHERE_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include "parser_base.h"
#include "sphere.h"
#include "utils.h"

/**
 * @brief Parser for Sphere geometry, inherits from ParserBase<Sphere>
 * and provides the functionality to parse the sphere geometry from XML.
 */
class SphereParser : public ParserBase<Sphere> {
 public:
  SphereParser() {
    p_ = std::make_shared<Sphere>();
  }

  void parse(const tinyxml2::XMLElement* xml) override {
    ParserBase<Sphere>::parse(xml);

    const char* radius_str = xml->Attribute("radius");
    if (radius_str) {
      double r;
      str2double(radius_str, r);
      p_ = std::make_shared<Sphere>();
      p_->setRadius(r);
    }
  }

  bool isA(const char* name) override {
    return p_->isA(name);
  }

  const char* getTypename() override {
    return p_->getTypename();
  }

  void print(std::ostream& os) override {
    os << "Parsed Sphere = [";
    p_->print(os);
    os << "]";
  }

  bool empty() const override {
    return p_ == nullptr;
  }

  void clear() override {
    p_->clear();
  }

  std::shared_ptr<Sphere> get() override {
    return p_;
  }

  ~SphereParser() = default;

 private:
  std::shared_ptr<Sphere> p_;
};
#endif  // INCLUDE_TINYURDF_GEOMETRY_SPHERE_PARSER_H_
