#ifndef INCLUDE_TINYURDF_URDF_RENDERER_H_
#define INCLUDE_TINYURDF_URDF_RENDERER_H_

// Copyright 2025 Wissem CHIHA

#include "model.h"
#include "renderer_base.h"
#include "vtk_model_renderer.h"

class URDFRenderer {
public:
    URDFRenderer();
    void setModel(const Model& model);
    std::shared_ptr<Model> getModel() const;
    void show();
    void setWindowSize(const int32_t width, const int32_t height);
    void setBackrgournd(double r, double g, double b, double a);
    void setLabelsVisibility(bool isVisible);
    ~URDFRenderer();
private:
    vtkSmartPointer<vtkRenderWindow> renderWindow_;
    std::shared_ptr<Model> model_;
    int32_t width_= 800;
    int32_t height_ =600;
    bool labels_= true;
    double r_, g_, b_, a_;
};
#endif  // TINYURDF_URDF_RENDERER_H_