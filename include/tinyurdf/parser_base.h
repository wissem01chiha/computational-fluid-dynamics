#ifndef INCLUDE_TINYURDF_CORE_PARSER_BASE_H_
#define INCLUDE_TINYURDF_CORE_PARSER_BASE_H_

// Copyright 2025 wissem CHIHA

#include <loguru/loguru.hpp>
#include <tinyxml2/tinyxml2.h>

#include <string>
#include <memory>

#include "object_base.h"
#include "property_base.h"

template <class T>
class ParserBase : public ObjectBase {
 public:
  const char* getNameOf(const tinyxml2::XMLElement* xml) {
    const char* name = xml->Attribute("name");
    if (!name) {
      return "";
    } else {
      return name;
    }
  }

  virtual void parse(const tinyxml2::XMLElement* xml) {
    if (!xml) {
      LOG_F(ERROR, "Parser::parse() passed nullptr");
      return;
    }
  }

  template <typename... Args>
  void parse(const tinyxml2::XMLElement* xml) {
    if (!xml) return;
    this->parse(xml);
    if constexpr (sizeof...(Args) > 0) {
      parse<Args...>(xml);
    }
  }

  template <typename Base, typename... Iter>
  void parse(const tinyxml2::XMLElement* xml) {
    if (!xml) return;
    ParserBase<Base> parser;
    parser.parse(xml);

    if constexpr (sizeof...(Iter) > 0) {
      parse<Iter...>(xml);
    }
  }

  virtual std::shared_ptr<T> get() { return Tptr; }

 protected:
  ParserBase() {}
  virtual ~ParserBase() {}

  std::shared_ptr<T> Tptr;
};

#endif  // INCLUDE_TINYURDF_CORE_PARSER_BASE_H_
