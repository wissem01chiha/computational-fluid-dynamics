#ifndef INCLUDE_TINYURDF_CORE_CAMERA_H_
#define INCLUDE_TINYURDF_CORE_CAMERA_H_

// Copyright 2024 Wissem CHIHA

#include "common/sensor_base.h"
#include "core/image.h"
#include "core/pose.h"

/**
 * @brief Base class for camera sensor definition
 * @param type : camera type 
 */
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
    void setHfov(double hfov_);
    void setNear(double near_);
    void setFar(double far_);
    void setUpdateRate(double ur) override;
    void getUpdateRate(double& ur) const override;
    void setOrigin(std::shared_ptr<Pose> o) override;
    const char* getTypename() const override;
    bool empty() const override;
    bool isA(const char* name) const override;
    void clear() override;
    void getRange(Image<double,4>& r)  override;
    void setRange(Image<double,4>& r) override;
    void get(Image<double,4>& o) const override;
    void set(const std::shared_ptr<Image<double,4>> mat);
    std::string toString() const  override;
 private:
    Type type; 
    std::shared_ptr<Pose>  origin;
    std::shared_ptr<Image<double,4>> mat;
    double hfov, near, far, update_rate;
};
#endif // INCLUDE_TINYURDF_CORE_CAMERA_H_