#include "urdf_renderer.h"

URDFRenderer::URDFRenderer()
{
    this->model_ = std::make_shared<Model>();
    this->renderWindow_ = vtkSmartPointer<vtkRenderWindow>::New();
}

void URDFRenderer::setModel(const Model &model)
{
    model_ = std::make_shared<Model>(model);
}

std::shared_ptr<Model> URDFRenderer::getModel() const
{
    return this->model_;
}

void URDFRenderer::show()
{
    VtkModelRenderer renderer;
    renderer.setLabelsVisibility(this->labels_);
    renderer.setModel(*this->model_);
    renderer.setWindowSize(this->width_, this->height_);
    renderer.setBackrgournd(this->r_, this->g_, this->b_, this->a_);
    renderer.show();
}

void URDFRenderer::setWindowSize(const int32_t width, const int32_t height)
{
    this->width_ = width;
    this->height_ = height;
}

void URDFRenderer::setBackrgournd(double r, double g, double b, double a)
{
    this->r_ = r;
    this->g_ = g;
    this->b_ = b;
    this->a_ = a;
}

URDFRenderer::~URDFRenderer()
{
    this->model_.reset();
    this->renderWindow_->Delete();
}

void URDFRenderer::setLabelsVisibility(bool isVisible){

    this->labels_ = isVisible;
}