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
template<typename T>
class PropertyParser : public ParserBase<std::unordered_map<std::string,T>>
{  
 public:
    PropertyParser(){
        p_ = std::make_shared<std::unordered_map<std::string,T>>();
    };

    std::string toString() const override {
        std::ostringstream oss;
        oss << "Parsed Property-Values = [";
        bool first = true;
        for (const auto& pair : *p_) {
            if (!first) oss << ", ";
            oss << pair.first << "=" << pair.second;
            first = false;
        }
        oss << "]";
        return oss.str();
    }

    bool empty() const override { 
        return p_->empty();
    }

    void clear() override {
        p_->clear();
    }

    const char* getTypename() const override {
        return "property_value_parser";
    }

    bool isA(const char* name) const override {
        return std::string(name) == "property_value_parser";
    }

    void parse(const tinyxml2::XMLElement* xml) 
    {
        ParserBase<std::unordered_map<std::string, T>>::parse(xml);
        const tinyxml2::XMLAttribute* attr = xml->FirstAttribute();

        while (attr) {
                if constexpr (std::is_same_v<T, double>) {
                    double val;
                    str2double(attr->Value(), val);
                    (*p_)[std::string(attr->Name())] = val;
                } else if constexpr (std::is_same_v<T, std::string>) {
                    (*p_)[std::string(attr->Name())] = std::string(attr->Value());
                } else {
                    LOG_F(ERROR, "failed to parse attribute: unsupported type for conversion");
                }
            attr = attr->Next();
        }
    }
    std::shared_ptr<std::unordered_map<std::string,T>> get() override {return p_;}; 
    ~PropertyParser(){};
 private:
    std::shared_ptr<std::unordered_map<std::string,T>> p_;
};
#endif // INCLUDE_TINYURDF_COMMON_PROPERTY_PARSER_H_