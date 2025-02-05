#ifndef INCLUDE_TINYURDF_COLLISION_PARSER_H_
#define INCLUDE_TINYURDF_COLLISION_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <memory>

#include "parser_base.h"
#include "collision.h"
#include "geometry_parser.h"
#include "pose_parser.h"
#include "utils.h"

class CollisionParser : public ParserBase<Collision>{
public:
    CollisionParser();
    void print(std::ostream& os) override;
    bool empty() const override;
    void clear() override;
    const char* getTypename() override;
    bool isA(const char* name) override;
    void parse(const tinyxml2::XMLElement* xml) override;
    std::shared_ptr<Collision> get() override; 
    ~CollisionParser();
private:
    std::shared_ptr<Collision> p_;
};
#endif // INCLUDE_TINYURDF_COLLISION_PARSER_H_