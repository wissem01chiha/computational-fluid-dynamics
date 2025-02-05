/*********************************************************************
* Software License Agreement (BSD License)
*
*  Copyright (c) 2024, Wissem CHIHA.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the Willow Garage nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/
#include "box.h"
#include "sphere.h"
#include "mesh.h"
#include "cylinder.h"
#include "collision.h"
#include "color.h"
#include "color_parser.h"
#include "geometry_base.h"
#include "geometry_parser.h"
#include "image.h"
#include "inertia.h"
#include "inertia_parser.h"
#include "joint.h"
#include "joint_calibration.h"
#include "joint_dynamics.h"
#include "joint_limits.h"
#include "joint_mimic.h"
#include "joint_parser.h"
#include "joint_safety.h"
#include "link.h"
#include "link_parser.h"
#include "material.h"
#include "property_parser.h"
#include "parser_base.h"
#include "material_parser.h"
#include "model_parser.h"
#include "pose_parser.h"
#include "camera_parser.h"
#include "camera.h"
#include "model.h"
#include "object_base.h"
#include "pose.h"
#include "property_base.h"
#include "ray.h"
#include "ray_sensor.h"
#include "sensor_base.h"
#include "utils.h"
#include "version.h"
#include "visual.h"
#include "tinyurdf_config.h"
#ifdef USE_VTK 
    #include "renderer_base.h"
    #include "vtk_camera_renderer.h"
    #include "vtk_joint_renderer.h"
    #include "vtk_link_renderer.h"
    #include "vtk_model_renderer.h"
    #include "vtk_sensor_renderer.h"
    #include "vtk_world_renderer.h"
#endif