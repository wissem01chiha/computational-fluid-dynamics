#include "vtk_model_renderer.h"

VtkModelRenderer::VtkModelRenderer()
{
    this->renderer_ = vtkSmartPointer<vtkRenderer>::New();
    this->window_ = vtkSmartPointer<vtkRenderWindow>::New();
}

void VtkModelRenderer::update()
{
    if(this->models_.empty())
    {
        LOG_F(ERROR, "Models container is empty");
        return;
    }
    for (auto model : models_)
    {
        VtkLinkRenderer linkRenderer;
        VtkJointRenderer jointRenderer;
        jointRenderer.setLabelsVisibility(this->labels_);

        for(auto link : model.getLinks()){

            linkRenderer.setLink(*link);
            linkRenderer.setRenderer(this->renderer_);
            linkRenderer.update();
        }
        for (auto joint : model.getJoints())
        {
            jointRenderer.setJoint(*joint);
            jointRenderer.setRenderer(this->renderer_);
            jointRenderer.update();
        } 
    }
}

void VtkModelRenderer::setLabelsVisibility(bool isVisible)
{
    this->labels_ = isVisible;
}

void VtkModelRenderer::show()
{
    this->update();
    this->window_->SetSize(this->width_, this->height_);
    this->window_->AddRenderer(this->renderer_);
    vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    this->window_->SetInteractor(interactor);

    vtkSmartPointer<vtkCallbackCommand> closeCallback = vtkSmartPointer<vtkCallbackCommand>::New();
    closeCallback->SetCallback([](vtkObject* caller, unsigned long, void*, void*) {
        vtkRenderWindowInteractor* interactor = static_cast<vtkRenderWindowInteractor*>(caller);
        interactor->TerminateApp(); 
    });
    interactor->AddObserver(vtkCommand::ExitEvent, closeCallback);

    interactor->Initialize();
    interactor->Start();
    window_->Render();
}

void VtkModelRenderer::setRenderer(vtkSmartPointer<vtkRenderer> renderer)
{
    this->renderer_ = renderer;
}

void VtkModelRenderer::setWindowSize(const int32_t width, const int32_t height)
{
    this->width_ = width;
    this->height_ = height;
    this->window_->SetSize(width, height);
}

void VtkModelRenderer::setBackrgournd(double r, double g, double b, double a)
{
    this->renderer_->SetBackground(r, g, b);
    this->renderer_->SetBackground2(r, g, b);
    this->renderer_->SetGradientBackground(true);
}

vtkSmartPointer<vtkRenderer> VtkModelRenderer::getRenderer()
{
    return this->renderer_;
}

void VtkModelRenderer::setModel(const Model &model)
{
    this->models_.push_back(model);
}

void VtkModelRenderer::clear()
{
    this->models_.clear();
}

bool VtkModelRenderer::isA(const char *name)
{
    return std::strcmp(name, "VtkModelRenderer") == 0;
}

void VtkModelRenderer::print(std::ostream &os) 
{
    for(auto model : this->models_)
    {
        model.print(os);
    }
}

bool VtkModelRenderer::empty() const
{
    return this->models_.empty();
}

const char *VtkModelRenderer::getTypename()
{
    return "VtkModelRenderer";
}

void VtkModelRenderer::setModels(const std::vector<Model> &models)
{
    this->models_ = models;
}

VtkModelRenderer::~VtkModelRenderer(){}