cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)

set(TINYURDF_LIBRARY_SOURCES
   image.cc
   camera.cc
   color.cc
   collision.cc
   visual.cc
   inertia.cc
   pose.cc
   material.cc
   box.cc
   box_parser.cc
   cylinder.cc
   sphere.cc
   mesh.cc
   inertia.cc
   utils.cc
   version.cc
   link.cc
   joint.cc
   model.cc
   joint_calibration.cc
   joint_dynamics.cc
   joint_limits.cc
   joint_mimic.cc
   joint_safety.cc
   joint_parser.cc
   visual_parser.cc
   inertia_parser.cc
   material_parser.cc
   geometry_parser.cc
   collision_parser.cc
   version_parser.cc
   link_parser.cc
   model_parser.cc
   urdf_parser.cc
   color_parser.cc
   mesh_parser.cc
)

if(USE_VTK)
    set(TINYURDF_LIBRARY_SOURCES
        ${TINYURDF_LIBRARY_SOURCES}
        vtk_joint_renderer.cc
        vtk_link_renderer.cc
        vtk_model_renderer.cc
        urdf_renderer.cc
    ) 
endif()

set(TINYURDF_INCLUDE_DIRECTORIES
    ${CMAKE_SOURCE_DIR}/include/tinyurdf
    ${CMAKE_SOURCE_DIR}/extern
)

if(USE_VTK)
    set(TINYURDF_INCLUDE_DIRECTORIES
    ${TINYURDF_INCLUDE_DIRECTORIES}
    ${VTK_DIR}
    )
endif()

add_library(tinyurdf ${TINYURDF_LIBRARY_SOURCES})

target_include_directories(tinyurdf PUBLIC ${TINYURDF_INCLUDE_DIRECTORIES})
target_link_libraries(tinyurdf PUBLIC Eigen3::Eigen loguru tinyxml2)

if(USE_VTK)
    target_link_libraries(tinyurdf PUBLIC ${VTK_LIBRARIES})
    vtk_module_autoinit(
        TARGETS tinyurdf 
        MODULES ${VTK_LIBRARIES}
    )
endif()