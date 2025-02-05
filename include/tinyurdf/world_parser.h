#ifndef TINYURDF_WORLD_PARSER_H_
#define TINYURDF_WORLD_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include "world.h"
#include "parser_base.h"

template<typename... PropertyBase>
class WorldParser : public ParserBase<World<PropertyBase...>>{
public:
    WorldParser();
    bool parse();
private:
    std::shared_ptr<World<PropertyBase...>> p_;
}; 
#endif  // TINYURDF_WORLD_PARSER_H_