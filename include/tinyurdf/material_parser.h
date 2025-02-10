#ifndef TINYURDF_MATERIAL_PARSER_H_
#define TINYURDF_MATERIAL_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include "parser_base.h"
#include "material.h"
#include "color_parser.h"
#include "property_parser.h"

/// @brief Parses the link material.
class MaterialParser : public ParserBase<Material> {
public:
    MaterialParser();
    void print(std::ostream& os)  override;
    bool empty() const override;
    void clear() override;
    const char* getTypename() override;
    bool isA(const char* name) override;
    void parse(const tinyxml2::XMLElement* xml) override;
    std::shared_ptr<Material> get() override;
    ~MaterialParser() override;
private:
    std::shared_ptr<Material> p_;
};
#endif // TINYURDF_MATERIALPARSER_H
