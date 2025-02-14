#ifndef INCLUDE_TINYURDF_INTERNAL_GEOMETRY_PARSER_H_
#define INCLUDE_TINYURDF_INTERNAL_GEOMETRY_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <memory>
#include <cstring>
#include "common/geometry_base.h"
#include "common/parser_base.h"
#include "internal/box_parser.h"
#include "internal/sphere_parser.h"
#include "internal/mesh_parser.h"
#include "internal/cylinder_parser.h"
#include "utility/utils.h"

/**
 * @brief Base parser for geometry shapes, parameterized with a geometry base
 * abstract object. It checks the geometry type and makes the pointer point to a valid
 * geometry structure (e.g., box, sphere, mesh, ...).
 * @code{.xml}
 *  <geometry>        
 *       <mesh filename="file.stl" scale="0.001 0.001 0.001"/> 
 *       <box size="0.531 0.27 0.24"/>
 *       <cylinder length="0.1" radius="0.05"/>
 *       <sphere radius="1.0"/>   
 *   </geometry>
 * @endcode
 * @todo In further versions, we will support simplified geometry definition 
 * in XML as one XML element, given by the following example:
 * @code{.xml}
 *      <geometry type="cylinder" radius="1" length="0.5" />
 * @endcode
 */
class GeometryParser final : public ParserBase<GeometryBase> {
public:
  GeometryParser();
  void parse(const tinyxml2::XMLElement* xml) override;
  const char* getTypename() const override;
  bool empty() const override;
  void clear() override;
  bool isA(const char* name) const override;
  std::string toString() const override;
  std::shared_ptr<GeometryBase> get() override;
  ~GeometryParser();
private:
  std::shared_ptr<GeometryBase> p_;
};
#endif  // INCLUDE_TINYURDF_INTERNAL_GEOMETRY_PARSER_H_
