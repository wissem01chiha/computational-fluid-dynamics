#ifndef TINYURDF_RENDRER_H_
#define TINYURDF_RENDRER_H_

// Copyright 2025 Wissem CHIHA

#include "object_base.h"

/**
 * @brief this is a base class for all renderers
 * all renderers impentation should inherit from this class 
 * at the moment we support only one renderer which is the VTK renderer
 * @tparam T template type for data structure, properties,...
 */
template<class T>
class RendererBase : public ObjectBase{
public:
    virtual void show() = 0;
    virtual void setLabelsVisibility(bool isVisible){};
    virtual void update() = 0;
    virtual void setWindowSize(const int32_t width, const int32_t height) = 0;
    virtual void setBackrgournd(double r, double g, double b, double a) = 0;
protected:
    RendererBase(){};
    ~RendererBase(){};
};
#endif // TINYURDF_RENDRER_H_