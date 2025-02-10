#ifndef INCLUDE_TINYURDF_CAMERA_PARSER_H_
#define INCLUDE_TINYURDF_CAMERA_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include "color.h"
#include "parser_base.h"
#include "camera.h"

/**
 * @brief sensor configuration for a camera sensor.
 * This is an example configuration for a camera sensor in the URDF format.
 * @code{.xml}
 * <sensor name="my_camera_sensor" update_rate="20">
 *   <parent link="optical_frame_link_name"/>
 *   <origin xyz="0 0 0" rpy="0 0 0"/>
 *   <camera>
 *     <image width="640" height="480" hfov="1.5708" format="RGB8" near="0.01" far="50.0"/>
 *   </camera>
 * </sensor>
 * @endcode
 */
class CameraParser : public ParserBase<Camera>{
public:
    CameraParser();
    void parse(const tinyxml2::XMLElement* xml) override;
    std::shared_ptr<Camera> get() override;
    const char* getTypename() override;
    bool isA(const char* name) override;
    bool empty() const override;
    void clear() override;
    void print(std::ostream& os) override;
private:
    std::shared_ptr<Camera> p_;
};
#endif // INCLUDE_TINYURDF_CAMERA_PARSER_H_