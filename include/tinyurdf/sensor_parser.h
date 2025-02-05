#ifndef TINYURDF_SENSOR_PARSER_H_
#define TINYURDF_SENSOR_PARSER_H_

#include "sensor_base.h"
#include "parser_base.h"

template <typename T> 
class SensorParser : public ParserBase<SensorBase<T>> {
public:
    SensorParser();
    ~SensorParser();
private:
    std::shared_ptr<SensorBase<T>> p_;
};
#endif // TINYURDF_SENSOR_PARSER_H_