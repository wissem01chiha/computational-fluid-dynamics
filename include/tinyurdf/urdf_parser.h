#ifndef INCLUDE_TINYURDF_URDF_PARSER_H_
#define INCLUDE_TINYURDF_URDF_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <string>
#include <memory>
#include <iostream>

#include <tinyxml2/tinyxml2.h>

#include "model.h"
#include "version.h"
#include "version_parser.h"
#include "parser_base.h"
#include "model_parser.h"

/**
 * @brief main user high level interface for parsing URDF files
 * @note this interface will be propted to other languages
 * or scripts
 */
class URDFParser : public ParserBase<Model>{   
public:
    URDFParser();
    void parse(const std::string& filename);
    void parse(const char* filename);
    void parse(const tinyxml2::XMLElement* xml) override;
    std::shared_ptr<Model> get() override;
    void print(std::ostream& os) override;
    bool isA(const char* name) override;
    bool empty() const override;
    void clear() override;
    const char* getTypename() override;
    ~URDFParser();
private:
    std::shared_ptr<Model> model_;
};
#endif  // TINYURDF_URDF_PARSER_H_