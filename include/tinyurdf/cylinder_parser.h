#ifndef INCLUDE_TINYURDF_CYLINDER_PARSER_H_
#define INCLUDE_TINYURDF_CYLINDER_PARSER_H_

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
  CylinderParser();
  void parse(const tinyxml2::XMLElement* xml) override;
  bool isA(const char* name) override;
  const char* getTypename() override;
  void print(std::ostream& os) override;
  bool empty() const override;
  void clear() override;
  std::shared_ptr<Cylinder> get() override;
  ~CylinderParser() = default;
private:
  std::shared_ptr<Cylinder> p_;
};
#endif  // INCLUDE_TINYURDF_CYLINDER_PARSER_H_
