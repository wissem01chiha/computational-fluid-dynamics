#ifndef INCLUDE_TINYURDF_GEOMETRY_MESH_PARSER_H_
#define INCLUDE_TINYURDF_GEOMETRY_MESH_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <memory>
#include <string>
#include "geometry_base.h"
#include "parser_base.h"
#include "utils.h"
#include "mesh.h"

/**
 * @brief Parser for Mesh geometry, inherits from ParserBase<Mesh>
 * and provides the functionality to parse the mesh geometry from XML.
 */
class MeshParser : public ParserBase<Mesh> {
public:
  MeshParser();
  void parse(const tinyxml2::XMLElement* xml) override;
  bool isA(const char* name) override;
  const char* getTypename() override;
  void print(std::ostream& os) override;
  bool empty() const override;
  void clear() override;
  std::shared_ptr<Mesh> get() override;
  ~MeshParser() override;
 private:
  std::shared_ptr<Mesh> p_;
};

#endif  // INCLUDE_TINYURDF_GEOMETRY_MESH_PARSER_H_
