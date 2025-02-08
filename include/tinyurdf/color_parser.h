#ifndef INCLUDE_TINYURDF_COLORPARSER_H_
#define INCLUDE_TINYURDF_COLORPARSER_H_

// Copyright 2025 Wissem CHIHA

#include "parser_base.h"
#include "color.h"
#include "utils.h"

/// \brief base parser for color description element
/// \note this is an elementary base parser 
/// \example <color rgba="1.0 0.01 0.0 1.0"/>
/// \note there is no other acceptable format for color definition!
class ColorParser : public ParserBase<Color> {
public:
    ColorParser();
    void print(std::ostream& os) override;
    bool empty() const override;
    void clear() override;
    const char* getTypename() override;
    bool isA(const char* name) override;
    void parse(const tinyxml2::XMLElement* xml) override;
    std::shared_ptr<Color> get() override;
private:
    std::shared_ptr<Color> p_;
};

#endif // INCLUDE_TINYURDF_COLORPARSER_H_
