#ifndef TINYURDF_MODELPARSER_H
#define TINYURDF_MODELPARSER_H

// Copyright 2025 Wissem CHIHA

#include <loguru/loguru.hpp>
#include <tinyxml2/tinyxml2.h>

#include "parser_base.h"
#include "joint_parser.h"
#include "link_parser.h"
#include "model.h"

class ModelParser : public ParserBase<Model>{
public:
  ModelParser();
  void parse(const tinyxml2::XMLElement* xml) override;
  std::shared_ptr<Model> get() override;
  void print(std::ostream& os) override;
  bool isA(const char* name) override;
  bool empty() const override;
  void clear() override;
  const char* getTypename() override;
private:
  std::shared_ptr<Model> p_;
};
#endif // TINYURDF_MODEL_PARSER_H