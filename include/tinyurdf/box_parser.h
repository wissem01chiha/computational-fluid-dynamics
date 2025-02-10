#ifndef INCLUDE_TINYURDF_BOX_PARSER_H_
#define INCLUDE_TINYURDF_BOX_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include "geometry_base.h"
#include "box.h"
#include "parser_base.h"
#include "utils.h"
#include <memory>

/**
 * @brief Parser for Box geometry, inherits from ParserBase<Box>
 * and provides the functionality to parse the box geometry from XML.
 */
class BoxParser : public ParserBase<Box> {
public:
  BoxParser();
  void parse(const tinyxml2::XMLElement* xml) override;
  bool isA(const char* name) override;
  const char* getTypename() override;
  void print(std::ostream& os) override;
  bool empty() const override;
  void clear() override;
  std::shared_ptr<Box> get() override;
  ~BoxParser() override;
private:
  std::shared_ptr<Box> p_;
};
#endif  // INCLUDE_TINYURDF_BOX_PARSER_H_
