cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

find_package(PCL QUIET)

if(PCL_FOUND)
    message(STATUS "PCL Found : ${PCL_DIR}")
else()
    include(ExternalProject)
    ExternalProject_Add(
        PCL
        GIT_REPOSITORY https://github.com/PointCloudLibrary/pcl.git
        GIT_TAG pcl-1.12.1
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
                -DBUILD_SHARED_LIBS=ON
                
        )
endif()