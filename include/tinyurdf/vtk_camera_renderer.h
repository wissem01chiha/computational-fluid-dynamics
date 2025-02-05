#ifndef TINYURDF_CAMERA_RENDERER_H_
#define TINYURDF_CAMERA_RENDERER_H_

// Copyright 2025 Wissem CHIHA

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

#include "Image.h"
#include "camera.h"
#include "renderer_base.h"

class VtkCameraRenderer : public RendererBase<Camera>
{
public:
    VtkCameraRenderer();
    ~VtkCameraRenderer();
private:
    std::shared_ptr<Camera> camera_;
};
#endif // TINYURDF_CAMERA_RENDERER_H_