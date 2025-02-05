#include "vtk_joint_renderer.h"

VtkJointRenderer::VtkJointRenderer()
{
    this->renderer_ = vtkSmartPointer<vtkRenderer>::New();
    this->window_ = vtkSmartPointer<vtkRenderWindow>::New();
}

void VtkJointRenderer::update()
{   
    this->window_->SetSize(this->width_,this->height_);
    if(this->joints_.size()==1){
        window_->SetWindowName(this->joints_[0].getName().c_str());
    }
    for(auto joint : this->joints_){ 

        Vec3 axis = joint.getAxis();
        std::vector<std::shared_ptr<Pose>> poses = joint.getTransform();

        for(auto pose : poses)
        {
            Vec3 position = pose->getPosition();
            double startAxisPoint[3];
            for (size_t k = 0; k < 3; k++){
                startAxisPoint[k] = position[k];
            }
            double endAxisPoint[3];
            for(size_t k=0; k< 3; k++){
                endAxisPoint[k] = startAxisPoint[k] + axis[k];
            }
            double normalizedX[3];
            double normalizedY[3];
            double normalizedZ[3];
            vtkMath::Subtract(endAxisPoint, startAxisPoint, normalizedX);
            double length = vtkMath::Norm(normalizedX);
            vtkMath::Normalize(normalizedX);
            double arbitrary[3]={0.025,1.25,1.36};
            vtkMath::Cross(normalizedX, arbitrary, normalizedZ);
            vtkMath::Normalize(normalizedZ);
            vtkMath::Cross(normalizedZ, normalizedX, normalizedY);

            vtkNew<vtkMatrix4x4> matrix;
            matrix->Identity();
            for (auto i = 0; i < 3; i++){
                matrix->SetElement(i, 0, normalizedX[i]);
                matrix->SetElement(i, 1, normalizedY[i]);
                matrix->SetElement(i, 2, normalizedZ[i]);
            }
            vtkNew<vtkTransform> transform;
            transform->Translate(startAxisPoint);
            transform->Concatenate(matrix);
            transform->Scale(1, 1, 1);

            vtkNew<vtkPolyDataMapper> mapper;
            vtkNew<vtkActor> actor;
            vtkNew<vtkArrowSource> arrow;
   
            mapper->SetInputConnection(arrow->GetOutputPort());
            actor->SetUserMatrix(transform->GetMatrix());
            actor->SetMapper(mapper);
            actor->GetProperty()->SetColor(0.5,0.4,1);
            if(arrow_){
                this->renderer_->AddActor(actor);
            }
        
            vtkNew<vtkMatrix4x4> poseTransformMatrix;
            Pose2vtkMatrix(*pose, poseTransformMatrix);
            Rot3 rotation = pose->getRotation();
            Eigen::Matrix3d rotationMatrix = rotation.toRotationMatrix();
            vtkNew<vtkTransform> axisTransform;
            axisTransform->Identity();
            axisTransform->SetMatrix(poseTransformMatrix);

            vtkNew<vtkAxesActor> axes;

            axes->GetXAxisCaptionActor2D()->GetCaptionTextProperty()->SetColor(1,0,0);
            axes->GetYAxisCaptionActor2D()->GetCaptionTextProperty()->SetColor(0,1,0);
            axes->GetZAxisCaptionActor2D()->GetCaptionTextProperty()->SetColor(0,0,1);
            
            if(labels_){
                axes->SetXAxisLabelText("x"); 
                axes->SetYAxisLabelText("y"); 
                axes->SetZAxisLabelText(joint.getName().c_str());
            }
            axes->AxisLabelsOff();
            axes->GetZAxisCaptionActor2D()->GetCaptionTextProperty()->SetFontSize(1);
            axes->SetTotalLength(length/2, length/2, length/2); 
            axes->SetUserTransform(axisTransform);
            renderer_->AddActor(axes);
        }
    }
}

void VtkJointRenderer::show()
{
    this->update();
    this->window_->AddRenderer(this->renderer_);
    for (int i = 0; i < 360; ++i){
        window_->Render();
        this->renderer_->GetActiveCamera()->Azimuth(0.5);
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void VtkJointRenderer::setLabelsVisibility(bool isVisible)
{
    this->labels_ = isVisible;
}

void VtkJointRenderer::setArrowsVisibility(bool isVisible)
{
    this->arrow_ = isVisible;
}

void VtkJointRenderer::setRenderer(vtkSmartPointer<vtkRenderer> renderer)
{
    if(!renderer){
        LOG_F(ERROR, "Renderer pointer is null");
        return;
    }else{
        this->renderer_ = renderer;
    }
}

void VtkJointRenderer::setWindowSize(const int32_t width, const int32_t height)
{
    this->width_ = width;
    this->height_ = height;
}

void VtkJointRenderer::setBackrgournd(double r, double g, double b, double a)
{
    this->renderer_->SetBackground(r, g, b);
    this->window_->SetAlphaBitPlanes(1);
    this->window_->SetMultiSamples(0);
    this->renderer_->SetBackgroundAlpha(a);
    this->renderer_->SetGradientBackground(true);
}

vtkSmartPointer<vtkRenderer>  VtkJointRenderer::getRenderer()
{
    return this->renderer_;
}

void VtkJointRenderer::setJoint(const Joint &joint)
{
    this->joints_.push_back(joint);
}

void VtkJointRenderer::clear()
{
    this->joints_.clear();
}

bool VtkJointRenderer::isA(const char *name)
{
    return std::string(name) == "VtkJointRenderer";
}

void VtkJointRenderer::print(std::ostream &os) 
{
    if(this->joints_.empty()){
        LOG_F(ERROR, "Joints vector is empty");
        return;
    }else{
        for (auto joint : this->joints_){
            joint.print(os);
        }
    }
}

bool VtkJointRenderer::empty() const
{
    return this->joints_.empty();
}

const char *VtkJointRenderer::getTypename()
{
    return "VtkJointRenderer";
}

void VtkJointRenderer::setJoints(const std::vector<Joint> &joints)
{
    if(joints.empty()){
        LOG_F(ERROR, "Joints vector is empty");
        return;
    }else
    {
        for(auto joint : joints){
            this->joints_.push_back(joint);
        }
    }
}

void VtkJointRenderer::Pose2vtkMatrix(Pose &pose, vtkSmartPointer<vtkMatrix4x4> matrix)
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
};