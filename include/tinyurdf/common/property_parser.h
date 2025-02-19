#ifndef INCLUDE_TINYURDF_COMMON_PROPERTY_PARSER_H_
#define INCLUDE_TINYURDF_COMMON_PROPERTY_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <string>
#include <unordered_map>
#include <loguru/loguru.hpp>
#include "common/parser_base.h"
#include "utility/utils.h"

/**
 * @brief A basic parser for general property value definitions in XML.
 * Parses a single XML element where a property is defined by a list of values. 
 * These values can be numeric or strings. It fills a vector with these values 
 * and returns a pointer to it. The parser can handle any number of values.
 * @tparam T data type can be char*, string , double, ...
 * @return An unordered map where keys are the attribute names 
 * (stored as std::string for safety by default) and values are of type T 
 * (which can be std::string, const char*, or double—only these types are acceptable).
 * @code{.xml}
 *  <density value="1.0" />
 *  ...
 *  <controller kP="10" kI="15" Kd="-2.0" ... />
 * @endcode
 * @tparam T Accepts either std::string or double.
 * @warning This parser does not support mixed property type parsing at once. 
 * It can handle an XML element with either all string or all double values. 
 * Mixed parsing of attributes will be addressed in future versions.
 * @note A conversion error from str2double will occur when parsing mixed 
 * attribute properties with a propertyParser<double> instance. 
 * This issue is currently ignored.
 * @todo Fix the bug related to mixed attribute property parsing.
 */
template <typename T>
class PropertyParser : public ParserBase<std::unordered_map<std::string, T>> {
public:
    PropertyParser();
    ~PropertyParser();
    std::string toString() const override;
    bool empty() const override;
    void clear() override;
    const char* getTypename() const override;
    bool isA(const char* name) const override;
    void parse(const tinyxml2::XMLElement* xml);
    std::shared_ptr<std::unordered_map<std::string, T>> get() override;

private:
    std::shared_ptr<std::unordered_map<std::string, T>> p_;
};
#endif // INCLUDE_TINYURDF_COMMON_PROPERTY_PARSER_H_