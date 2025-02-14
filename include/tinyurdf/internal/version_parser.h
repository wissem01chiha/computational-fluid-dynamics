#ifndef INCLUDE_TINYURDF_INTERNAL_VERSION_PARSER_H_
#define INCLUDE_TINYURDF_INTERNAL_VERSION_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <tinyxml2/tinyxml2.h>
#include "internal/version.h"

/**
 * @brief Base parser for the XML version tag
 * @note This class does not inherit from parserBase
 *       as it provides its own parsing mechanism, 
 *       but we maintain a consistent layout to adhere to the base parser class.
 */
class VersionParser final {
public:
    VersionParser();
    void parse(const tinyxml2::XMLDocument doc);
    const char* getTypename() const;
    std::shared_ptr<Version> get() const { return p_; }
    ~VersionParser();
private:
    std::shared_ptr<Version> p_;
};
#endif // TINYURDF_VERSION_PARSER_H_