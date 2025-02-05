#ifndef TINYURDF_WORLD_RENDERER_H_
#define TINYURDF_WORLD_RENDERER_H_

// Copyright 2025 Wissem CHIHA

#include "renderer_base.h"
#include "world.h"

template<typename... PropertyBase>
class vtkWorldRenderer : public RendererBase<World<PropertyBase...>>
{
public:
    vtkWorldRenderer ();
    ~vtkWorldRenderer();
private:
};
#endif // TINYURDF_WORLD_RENDERER_H_
