#ifndef INCLUDE_TINYURDF_VISUAL_PARSER_H_
#define INCLUDE_TINYURDF_VISUAL_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <memory>

#include "visual.h"
#include "parser_base.h"
#include "geometry_base.h"
#include "geometry_parser.h"
#include "pose_parser.h"
#include "material_parser.h"
#include "material.h"
#include "box.h"
#include "sphere.h"
#include "mesh.h"
#include "cylinder.h"
#include "utils.h"

class VisualParser : public ParserBase<Visual>{
public:
    VisualParser();
    void print(std::ostream& os) override;
    bool empty() const override;
    void clear() override;
    const char* getTypename() override;
    bool isA(const char* name) override;
    void parse(const tinyxml2::XMLElement* xml) override;
    std::shared_ptr<Visual> get()override; 
    ~VisualParser();
private:
    std::shared_ptr<Visual> p_;
};
#endif // INCLUDE_TINYURDF_VISUAL_PARSER_H_

