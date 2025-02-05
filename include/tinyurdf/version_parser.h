#ifndef INCLUDE_TINYURDF_VERSION_PARSER_H_
#define INCLUDE_TINYURDF_VERSION_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <memory>

#include <tinyxml2/tinyxml2.h>
#include "version.h"

/// @brief parses the version.
class VersionParser  {
public:
    VersionParser();
    void parse(const tinyxml2::XMLDocument doc);
    std::shared_ptr<Version> get() const { return p_; }
    ~VersionParser();
private:
    std::shared_ptr<Version> p_;
};
#endif // TINYURDF_VERSIONPARSER_H_