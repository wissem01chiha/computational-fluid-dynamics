#ifndef INCLUDE_TINYURDF_INTERNAL_CYLINDER_PARSER_H_
#define INCLUDE_TINYURDF_INTERNAL_CYLINDER_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include "common/parser_base.h"
#include "common/geometry_base.h"
#include "core/cylinder.h"
#include "utility/utils.h"

/**
 * @brief Parser for Cylinder geometry, inherits from ParserBase<Cylinder>
 * and provides the functionality to parse the cylinder geometry from XML.
 */
class CylinderParser final : public ParserBase<Cylinder> {
public:
  CylinderParser();
  void parse(const tinyxml2::XMLElement* xml) override;
  bool isA(const char* name) const override;
  const char* getTypename() const override;
  std::string toString() const override;
  bool empty() const override;
  void clear() override;
  std::shared_ptr<Cylinder> get() override;
  ~CylinderParser() = default;
private:
  std::shared_ptr<Cylinder> p_;
};
#endif  // INCLUDE_TINYURDF_INTERNAL_CYLINDER_PARSER_H_
