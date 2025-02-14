#ifndef INCLUDE_TINYURDF_INTERNAL_WORLD_PARSER_H_
#define INCLUDE_TINYURDF_INTERNAL_WORLD_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include "core/world.h"
#include "common/parser_base.h"

template<typename... PropertyBase>
class WorldParser final : public ParserBase<World<PropertyBase...>>{
public:
    WorldParser();
    std::string toString() const override;
    bool parse();
private:
    std::shared_ptr<World<PropertyBase...>> p_;
}; 
#endif  // INCLUDE_TINYURDF_INTERNAL_WORLD_PARSER_H_