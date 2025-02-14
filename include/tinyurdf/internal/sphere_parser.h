#ifndef INCLUDE_TINYURDF_INTERNAL_SPHERE_PARSER_H_
#define INCLUDE_TINYURDF_INTERNAL_SPHERE_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include "common/parser_base.h"
#include "core/sphere.h"
#include "utility/utils.h"

class SphereParser final : public ParserBase<Sphere> {
public:
  SphereParser();
  void parse(const tinyxml2::XMLElement* xml) override;
  bool isA(const char* name) const override;
  const char* getTypename() const override;
  std::string toString() const override;
  bool empty() const override;
  void clear() override;
  std::shared_ptr<Sphere> get() override;
  ~SphereParser() = default;
private:
  std::shared_ptr<Sphere> p_;
};
#endif  // INCLUDE_TINYURDF_INTERNAL_SPHERE_PARSER_H_
