#ifndef TINYURDF_RAY_SENSOR_H_
#define TINYURDF_RAY_SENSOR_H_

// Copyright 2025 Wissem CHIHA

#include "sensor_base.h"
#include "ray.h"

class  RaySensor : public SensorBase<Ray>{
public:
    RaySensor();
    void print(std::ostream& os) override;
    void update() override;
    void reset() override;
    ~RaySensor();
private:
    std::shared_ptr<Ray> ray_;
};
#endif // TINYURDF_RAY_SENSOR_H_
 
