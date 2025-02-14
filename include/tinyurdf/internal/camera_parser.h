#ifndef INCLUDE_TINYURDF_INTERNAL_CAMERA_PARSER_H_
#define INCLUDE_TINYURDF_INTERNAL_CAMERA_PARSER_H_

// Copyright 2024 Wissem CHIHA

#include "common/parser_base.h"
#include "internal/pose_parser.h"
#include "common/property_parser.h"
#include "core/camera.h"
#include "core/color.h"

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
class CameraParser final : public ParserBase<Camera>{
 public:
  CameraParser();
  void parse(const tinyxml2::XMLElement* xml) override;
  std::shared_ptr<Camera> get() override;
  const char* getTypename() const override;
  bool isA(const char* name) const override;
  bool empty() const override;
  void clear() override;
  std::string toString() const override;
 private:
  std::shared_ptr<Camera> p_;
};
#endif // INCLUDE_TINYURDF_INTERNAL_CAMERA_PARSER_H_