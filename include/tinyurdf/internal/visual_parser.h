#ifndef INCLUDE_TINYURDF_INTERNAL_VISUAL_PARSER_H_
#define INCLUDE_TINYURDF_INTERNAL_VISUAL_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include "core/visual.h"
#include "common/parser_base.h"
#include "common/geometry_base.h"
#include "internal/geometry_parser.h"
#include "internal/pose_parser.h"
#include "internal/material_parser.h"
#include "core/material.h"
#include "core/box.h"
#include "core/sphere.h"
#include "core/mesh.h"
#include "core/cylinder.h"
#include "utility/utils.h"

class VisualParser final : public ParserBase<Visual>{
public:
    VisualParser();
    std::string toString() const override;
    bool empty() const override;
    void clear() override;
    const char* getTypename() const override;
    bool isA(const char* name) const override;
    void parse(const tinyxml2::XMLElement* xml) override;
    std::shared_ptr<Visual> get()override; 
    ~VisualParser();
private:
    std::shared_ptr<Visual> p_;
};
#endif // INCLUDE_TINYURDF_INTERNAL_VISUAL_PARSER_H_

