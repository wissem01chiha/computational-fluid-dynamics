#ifndef INCLUDE_TINYURDF_INTERNAL_COLLISION_PARSER_H_
#define INCLUDE_TINYURDF_INTERNAL_COLLISION_PARSER_H_

// Copyright 2024 Wissem CHIHA

#include "common/property_base.h"
#include "core/collision.h"
#include "internal/geometry_parser.h"
#include "internal/pose_parser.h"
#include "utility/utils.h"

class CollisionParser final : public ParserBase<Collision>{
public:
    CollisionParser();
    std::string toString() const override;
    bool empty() const override;
    void clear() override;
    const char* getTypename() const override;
    bool isA(const char* name) const override;
    void parse(const tinyxml2::XMLElement* xml) override;
    std::shared_ptr<Collision> get() override; 
    ~CollisionParser();
private:
    std::shared_ptr<Collision> p_;
};
#endif // INCLUDE_TINYURDF_INTERNAL_COLLISION_PARSER_H_