#ifndef TINYURDF_SENSOR_BASE_H_
#define TINYURDF_SENSOR_BASE_H_

// Copyright 2025 Wissem CHIHA

#include "object_base.h"
#include "pose.h"

/**
 * @brief Base class for sensors 
 * @tparam T 
 * - numeric (`double`, `int`, `bool`) for distance, pressure, or binary states.
 * - structured (`Pose`, `std::array`, `std::vector`) for position and vector data.
 * - advanced (`Image`, `PointCloud`, `Audio`) for visual, depth, and audio data.
 * - domain-specific (`RadarData`, `SpectralData`, `Event`) for specialized sensor outputs.
 * - time-series (`TimeSeries`, `StreamingData`) for continuous sensor measurements.
 */
template<class T>
class SensorBase : public ObjectBase{
public:
    virtual void setRange(T& r) = 0;
    virtual void getRange(T& r) = 0;
    virtual void setUpdateRate(double ur) = 0 ;
    virtual void getUpdateRate(double& ur) const = 0;
    virtual void setOrigin(std::shared_ptr<Pose> o) = 0;
    virtual void getOrigin(double* xyz) const = 0;
protected:
    SensorBase();
    ~SensorBase() override;
    virtual void update(){};
    virtual void reset(){};
    virtual void get(T& o) const = 0; 
    virtual const char* getTypename() const = 0;
};
#endif // TINYURDF_SENSOR_BASE_H_