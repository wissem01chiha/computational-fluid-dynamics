#ifndef TINYURDF_SENSOR_RENDERER_H_
#define TINYURDF_SENSOR_RENDERER_H_

// Copyright 2025 Wissem CHIHA

#include "renderer_base.h"
#include "sensor_base.h"
#include "camera.h"

template<class T>
class vtkSensorRenderer : public RendererBase<SensorBase<T>>{ 
public:
    vtkSensorRenderer();
    ~vtkSensorRenderer();
private:
};
#endif // TINYURDF_SENSOR_RENDERER_H_
