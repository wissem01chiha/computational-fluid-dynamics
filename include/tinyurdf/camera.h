#ifndef INCLUDE_TINYURDF_CAMERA_H_
#define INCLUDE_TINYURDF_CAMERA_H_

// Copyright 2025 Wissem CHIHA

#include "sensor_base.h"
#include "image.h"
#include "pose.h"

class Camera : public SensorBase<Image<double,4>>{
public:
    enum class Type {
        L8, R8G8B8, B8G8R8, BAYER_RGGB8, BAYER_BGGR8, 
        BAYER_GBRG8, BAYER_GRBG8
    };
    Camera();
    Camera(const Camera& rhs); 
    void reset() override;
    void update() override;
    void getOrigin(double* xyz) const override;
    void setType(Type t_);
    void setType(const char* c);
    void setUpdateRate(double ur) override;
    void getUpdateRate(double& ur) const override;
    void setOrigin(std::shared_ptr<Pose> o) override;
    const char* getTypename() override;
    void getRange(Image<double,4>& r)  override;
    void setRange(Image<double,4>& r) override;
    void get(Image<double,4>& o) const override;
    void print(std::ostream& os) override;
private:
    Type type; 
    std::shared_ptr<Pose>  origin;
    std::shared_ptr<Image<double,4>> mat;
    double hfov, near, far, update_rate;
};
#endif // INCLUDE_TINYURDF_CAMERA_H_