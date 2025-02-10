#ifndef TINYURDF_MATERIAL_H_
#define TINYURDF_MATERIAL_H_

// Copyright 2025 Wissem CHIHA

#include <filesystem>
#include <memory>
#include <string>

#include <loguru/loguru.hpp>

#include "property_base.h"
#include "color.h"

class Material : public PropertyBase {
public:
    Material();
    void clear() override;
    void setFilename(std::string& path);
    void setName(const std::string& name_);
    void setDensity(double d);
    void setColor(double r, double g, double b, double a = 1.0);
    bool isA(const char* name) override;
    void print(std::ostream& os) override;
private:
    std::string name;
    std::string texture_filename;
    std::shared_ptr<Color> color;
    double density;
};
#endif // TINYURDF_MATERIAL_H