#ifndef TINYURDF_VTK_LINK_RENDERER_H
#define TINYURDF_VTK_LINK_RENDERER_H

// Copyright 2025 Wissem CHIHA

#include <thread>
#include <vector>

#include <vtkNew.h>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkTextActor3D.h>
#include <vtkCubeSource.h>
#include <vtkSphereSource.h>
#include <vtkNamedColors.h>
#include <vtkCylinderSource.h>
#include <vtkArrowSource.h>
#include <vtkSphereSource.h>
#include <vtkNamedColors.h>
#include <vtkElevationFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkTextProperty.h>
#include <vtkRenderWindow.h>
#include <vtkAxesActor.h>
#include <vtkRenderer.h>
#include <vtkTransform.h>
#include <vtkDataSetMapper.h>
#include <vtkTransformFilter.h>
#include <vtkMatrix4x4.h>
#include <vtkSTLReader.h>
#include <vtkCaptionActor2D.h>

#include "renderer_base.h"
#include "link.h"
#include "pose.h"
#include "box.h"
#include "cylinder.h"
#include "sphere.h"
#include "mesh.h"

class VtkLinkRenderer : public RendererBase<Link>{
public:
    VtkLinkRenderer();
    void show() override;
    void update() override;
    void setRenderer(vtkSmartPointer<vtkRenderer> renderer);
    void setWindowSize(const int32_t width, const int32_t height) override;
    void setBackrgournd(double r, double g, double b, double a) override;
    void setLabelsVisibility(bool isVisible) override;
    vtkSmartPointer<vtkRenderer> getRenderer();
    void setLink(const Link&  link);
    void clear() override;
    bool isA(const char* name) override;
    void print(std::ostream& os) override;
    bool empty() const override;
    const char* getTypename() override;
    void setLinks(const std::vector<Link>& links);
    ~VtkLinkRenderer();
private:
    int32_t width_ = 800;
    int32_t height_ = 600;
    vtkSmartPointer<vtkRenderer> renderer_;
    vtkSmartPointer<vtkRenderWindow> window_;
    std::vector<Link> links_;
    bool labels_ = false;
    void Pose2vtkMatrix(Pose& pose, vtkSmartPointer<vtkMatrix4x4> matrix);
};
#endif // TINYURDF_VTK_LINK_RENDERER_H