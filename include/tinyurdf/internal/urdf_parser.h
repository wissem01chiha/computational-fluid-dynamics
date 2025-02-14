#ifndef INCLUDE_TINYURDF_INTERNAL_URDF_PARSER_H_
#define INCLUDE_TINYURDF_INTERNAL_URDF_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include "core/model.h"
#include "internal/version.h"
#include "internal/version_parser.h"
#include "common/parser_base.h"
#include "internal/model_parser.h"

/**
 * @brief Main user high-level interface for parsing URDF files.
 * @note This interface will be exposed to other languages or 
 * external scripts.
 */
class URDFParser final : public ParserBase<Model>{   
 public:
  URDFParser();
  void parse(const std::string& filename);
  void parse(const char* filename);
  void parse(const tinyxml2::XMLElement* xml) override;
  std::shared_ptr<Model> get() override;
  std::string toString() const override;
  bool isA(const char* name) const override;
  bool empty() const override;
  void clear() override;
  const char* getTypename() const override;
  ~URDFParser();
 private:
  std::shared_ptr<Model> model_;
};
#endif  // INCLUDE_TINYURDF_INTERNAL_URDF_PARSER_H_