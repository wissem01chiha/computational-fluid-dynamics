#include "vtk_link_renderer.h"


VtkLinkRenderer::VtkLinkRenderer()
{
    this->renderer_ = vtkSmartPointer<vtkRenderer>::New();
    this->window_ = vtkSmartPointer<vtkRenderWindow>::New();
}

void VtkLinkRenderer::update()
{
    for (const auto link : this->links_){
        
        vtkNew<vtkPolyDataMapper> mapper;
        vtkNew<vtkActor> actor;
        vtkNew<vtkTransform> transform;
        vtkNew<vtkMatrix4x4> poseTransformMatrix;
        
        auto visual_ptr = link.getVisual();
        std::shared_ptr<Pose> pose_ptr = link.getVisual()->getPose();
        Vec3 position = pose_ptr->getPosition();

        auto geometry = link.getVisual()->getGeometry();

        transform->Identity();
        Pose2vtkMatrix(*pose_ptr, poseTransformMatrix);

        if(geometry->isA("box")){

            vtkNew<vtkCubeSource> cube;
        
            double center[3];
            geometry->getOrigin(center);

            cube->SetCenter(position[0], position[1], position[2]);
            cube->SetXLength(center[0]);
            cube->SetYLength(center[1]);
            cube->SetZLength(center[2]);

            mapper->SetInputConnection(cube->GetOutputPort());

        }else if(geometry->isA("cylinder")){

            vtkNew<vtkCylinderSource> cylinderSource;

            cylinderSource->SetCenter(position[0], position[1], position[2]);
            cylinderSource->SetRadius(geometry->getRadius());
            cylinderSource->SetHeight(geometry->getLength());
            cylinderSource->SetResolution(100);
            mapper->SetInputConnection(cylinderSource->GetOutputPort());
        }
        else if(geometry->isA("sphere")){

            vtkNew<vtkSphereSource> sphereSource;

            sphereSource->SetRadius(geometry->getRadius());
            sphereSource->SetCenter(position[0], position[1], position[2]);
            sphereSource->SetPhiResolution(20);
            sphereSource->SetThetaResolution(20);
            mapper->SetInputConnection(sphereSource->GetOutputPort());
        }
        else if(geometry->isA("mesh")){

            vtkNew<vtkSTLReader> reader;
  
            reader->SetFileName(geometry->getFilename().c_str());
            transform->Scale(geometry->getScale()[0], geometry->getScale()[1], geometry->getScale()[2]);
            vtkNew<vtkTransformFilter> transformFilter;
            transformFilter->SetInputConnection(reader->GetOutputPort());
            transformFilter->SetTransform(transform);
            mapper->SetInputConnection(transformFilter->GetOutputPort());
        }
        else{
            LOG_F(ERROR, "Geometry type not supported");
        }
        if(labels_){
            vtkNew<vtkTextActor3D> textActor3D;
            textActor3D->SetInput(link.getName().c_str());

            vtkSmartPointer<vtkTextProperty> textProperty = vtkSmartPointer<vtkTextProperty>::New();
            textProperty->SetColor(0.0, 0.0, 0.0); 
            textProperty->BoldOn(); 
            textActor3D->SetTextProperty(textProperty);

            textActor3D->SetScale(0.005);
            textActor3D->SetPosition(1.01*position[0], 1.01*position[1], 1.01*position[2]);
            this->renderer_->AddActor2D(textActor3D);
        }
        actor->SetMapper(mapper);
        actor->SetUserMatrix(poseTransformMatrix);
        this->renderer_->AddActor(actor);
    }
}

void VtkLinkRenderer::show()
{
    this->update();
    this->window_->SetSize(this->width_, this->height_);
    this->window_->AddRenderer(this->renderer_);
    for (int i = 0; i < 360; ++i){
        window_->Render();
        this->renderer_->GetActiveCamera()->Azimuth(0.5);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void VtkLinkRenderer::setRenderer(vtkSmartPointer<vtkRenderer> renderer)
{
    this->renderer_ = renderer;
    this->window_->AddRenderer(renderer);
}

void VtkLinkRenderer::setWindowSize(const int32_t width, const int32_t height)
{
    this->width_ = width;
    this->height_ = height;
}

void VtkLinkRenderer::setBackrgournd(double r, double g, double b, double a)
{
    this->renderer_->SetBackground(r, g, b);
    this->window_->SetAlphaBitPlanes(1);
    this->window_->SetMultiSamples(0);
    this->renderer_->SetBackgroundAlpha(a);
    this->renderer_->SetGradientBackground(true);
}

void VtkLinkRenderer::setLabelsVisibility(bool isVisible)
{
    this->labels_ = isVisible;
}

vtkSmartPointer<vtkRenderer> VtkLinkRenderer::getRenderer()
{
    return renderer_;
}

void VtkLinkRenderer::setLink(const Link &link)
{
    this->links_.push_back(link);
}

void VtkLinkRenderer::clear()
{
    this->links_.clear();
}

bool VtkLinkRenderer::isA(const char *name)
{
    return std::string(name) == "VtkLinkRenderer";
}

void VtkLinkRenderer::print(std::ostream &os) 
{
    if (this->links_.empty())
    {
        LOG_F(ERROR, "Links vector is empty");
        return;
    }
    else
    {
        for (auto link : this->links_)
        {
            link.print(os);
        }
    }
}

bool VtkLinkRenderer::empty() const
{
    return this->links_.empty();
}

const char *VtkLinkRenderer::getTypename()
{
    return "VtkLinkRenderer";
}

void VtkLinkRenderer::setLinks(const std::vector<Link> &links)
{
    if (links.empty())
    {
        LOG_F(ERROR, "Links vector is empty");
        return;
    }
    else
    {
        this->links_ = links;
    }
}

VtkLinkRenderer::~VtkLinkRenderer()
{
}

void VtkLinkRenderer::Pose2vtkMatrix(Pose &pose, vtkSmartPointer<vtkMatrix4x4> matrix)
{
    matrix->Identity();
    double pos[3];
    Vec3 position = pose.getPosition();
    for (int i = 0; i < 3; i++){
        pos[i] = position[i];
    }
    Rot3 rotation = pose.getRotation();
    Eigen::Matrix3d rotationMatrix = rotation.toRotationMatrix();
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            matrix->SetElement(row, col, rotationMatrix(row, col));
        }
    }
    for (int row = 0; row < 3; ++row){
        matrix->SetElement(row, 3, pos[row]);
    }
    matrix->SetElement(3, 0, 0.0);
    matrix->SetElement(3, 1, 0.0);
    matrix->SetElement(3, 2, 0.0);
    matrix->SetElement(3, 3, 1.0);
}
