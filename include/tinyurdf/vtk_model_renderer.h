#ifndef TINYURDF_URDF_RENDER_H
#define TINYURDF_URDF_RENDER_H

// Copyright 2025 Wissem CHIHA
#include <vtkNew.h>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkConeSource.h>
#include <vtkArrowSource.h>
#include <vtkSphereSource.h>
#include <vtkCylinderSource.h>
#include <vtkNamedColors.h>
#include <vtkTransformFilter.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkSTLReader.h>
#include <vtkRenderWindow.h>
#include <vtkAxesActor.h>
#include <vtkRenderer.h>
#include <vtkTransform.h>
#include <vtkCallbackCommand.h>
#include <vtkDataSetMapper.h>
#include <vtkCubeSource.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkCallbackCommand.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkCaptionActor2D.h>
#include <vtkTextProperty.h>
#include <vtkMath.h>

#include "model.h"
#include "renderer_base.h"
#include "vtk_link_renderer.h"
#include "vtk_joint_renderer.h"

/**
 * @brief this is the main renderer for models
 * @note ground display, and all related transformation are not implemented yet
 * it will be supported as soon as world module parsing and rendering is done
 * @todo relative scaling of scene object are not yet supported, dfault assumed!
 * @warning this can lead to some overlapping of objects, and wrong scaling.
 */
class VtkModelRenderer : public  RendererBase<Model>
{
public:
    VtkModelRenderer(); 
    void show() override;
    void update() override;
    void setLabelsVisibility(bool isVisible) override;
    void setRenderer(vtkSmartPointer<vtkRenderer> renderer);
    void setWindowSize(const int32_t width, const int32_t height) override;
    void setBackrgournd(double r, double g, double b, double a) override;
    vtkSmartPointer<vtkRenderer> getRenderer();
    void setModel(const Model& model);
    void clear() override;
    bool isA(const char* name) override;
    void print(std::ostream& os) override;
    bool empty() const override;
    const char* getTypename() override;
    void setModels(const std::vector<Model>& models);
    ~VtkModelRenderer();
private:
    int32_t width_ = 800;
    int32_t height_ = 600;
    vtkSmartPointer<vtkRenderer> renderer_;
    vtkSmartPointer<vtkRenderWindow> window_;
    std::vector<Model> models_;
    bool labels_ = false;
};
#endif // TINYURDF_URDF_RENDER_H