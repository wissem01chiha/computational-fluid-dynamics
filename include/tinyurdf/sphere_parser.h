#ifndef INCLUDE_TINYURDF_SPHERE_PARSER_H_
#define INCLUDE_TINYURDF_SPHERE_PARSER_H_

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
  SphereParser();
  void parse(const tinyxml2::XMLElement* xml) override;
  bool isA(const char* name) override;
  const char* getTypename() override;
  void print(std::ostream& os) override;
  bool empty() const override;
  void clear() override;
  std::shared_ptr<Sphere> get() override;
  ~SphereParser() = default;
private:
  std::shared_ptr<Sphere> p_;
};
#endif  // INCLUDE_TINYURDF_SPHERE_PARSER_H_
