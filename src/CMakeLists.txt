cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(LIBRARY_SOURCES
  geometry/pose.cc
  common/image.cc
  common/camera_extrinsics.cc
  common/camera_intrinsics.cc
  common/camera.cc
)
set(INCLUDE_DIRECTORIES
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/3rdparty
)
add_library(sfm ${LIBRARY_SOURCES})
target_include_directories(sfm PUBLIC ${INCLUDE_DIRECTORIES})
target_link_libraries(sfm PUBLIC Eigen3::Eigen glog::glog ${OpenCV_LIBS})
