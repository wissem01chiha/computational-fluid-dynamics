cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

find_package(PCL 1.14 QUIET)

if(PCL_FOUND)
    message(STATUS "PCL Found : ${PCL_INCLUDE_DIRS}")
else(PCL_FOUND)
    message(STATUS "PCL 1.14 not found. Downloading and building from source...")
    include(ExternalProject)
    ExternalProject_Add(
        PCL
        GIT_REPOSITORY https://github.com/PointCloudLibrary/pcl.git
        GIT_TAG pcl-1.14.1
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
                -DBUILD_SHARED_LIBS=ON
                -DBUILD_visualization=ON
               
        )
    include_directories(${PCL_INCLUDE_DIRS})
    link_directories(${PCL_LIBRARY_DIRS})
    add_definitions(${PCL_DEFINITIONS})
endif()