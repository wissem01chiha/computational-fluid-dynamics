#ifndef INCLUDE_TINYURDF_MESH_H_
#define INCLUDE_TINYURDF_MESH_H_

// Copyright 2025 Wissem CHIHA

#include <iostream>
#include <string>
#include <filesystem>

#include <loguru/loguru.hpp>

#include "geometry_base.h"
#include "color.h"
#include "utils.h"

class Mesh : public GeometryBase {
public:
    Mesh();
    ~Mesh();
    bool isA(const char* name) override;
    void clear() override;
    void setFilename(const std::string& path);
    std::string getFilename() override;
    void setScale(double xs, double ys, double zs);
    Vec3 getScale() override;
    void setColor(Color c);
    void setColor(double r, double g, double b, double a = 1.0);
    void print(std::ostream& os) override;
    void setOrigin(double x, double y, double z) override;
    void getOrigin(double* xyz) const override;
    bool empty() const override;
    const char* getTypename() override;
private:
    std::string filename;
    Vec3 scale;
    Color color;
};
#endif  // INCLUDE_TINYURDF_GEOMETRY_MESH_H_
