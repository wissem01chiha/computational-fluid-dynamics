#ifndef TINYURDF_VTK_JOINT_RENDRER_H_
#define TINYURDF_VTK_JOINT_RENDRER_H_

// Copyright 2025 Wissem CHIHA

#include <thread>
#include <vector>

#include <vtkNew.h>
#include <vtkActor.h>
#include <vtkCamera.h>
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
#include <vtkRenderWindowInteractor.h>
#include <vtkCaptionActor2D.h>

#include "renderer_base.h"
#include "joint.h"
#include "pose.h"

class VtkJointRenderer : public RendererBase<Joint>{
public:
    VtkJointRenderer();
    void update() override;
    void show() override;
    void setLabelsVisibility(bool isVisible) override;
    void setArrowsVisibility(bool isVisible);
    void setRenderer(vtkSmartPointer<vtkRenderer> renderer);
    void setWindowSize(const int32_t width, const int32_t height) override;
    void setBackrgournd(double r, double g, double b, double a) override;
    vtkSmartPointer<vtkRenderer> getRenderer(); 
    void setJoint(const Joint& joint);
    void clear() override;
    bool isA(const char* name) override;
    void print(std::ostream& os) override;
    bool empty() const override;
    const char* getTypename() override;
    void setJoints(const std::vector<Joint>& joints);
    ~VtkJointRenderer(){};
private:
    int32_t width_ = 800;
    int32_t height_ = 600;
    vtkSmartPointer<vtkRenderer> renderer_;
    vtkSmartPointer<vtkRenderWindow> window_;
    std::vector<Joint> joints_;
    bool labels_ = true;
    bool arrow_ = false;
    void Pose2vtkMatrix(Pose& pose, vtkSmartPointer<vtkMatrix4x4> matrix);
};
#endif // TINYURDF_VTK_JOINT_RENDRER_H_

