#ifndef TINYURDF_WORLD_RENDERER_H_
#define TINYURDF_WORLD_RENDERER_H_

// Copyright 2025 Wissem CHIHA

#include "renderer_base.h"
#include "world.h"

template<typename... PropertyBase>
class VtkWorldRenderer : public RendererBase<World<PropertyBase...>>
{
public:
    VtkWorldRenderer ();
    ~VtkWorldRenderer();
private:
};
#endif // TINYURDF_WORLD_RENDERER_H_
