cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
find_package(GLOG QUIET)
if(GLOG_FOUND)
    message(STATUS "GLOG found: ${GLOG_DIR}")
    include_directories(${GLOG_DIR})
else()
    message(STATUS "GLog not found. Downloading and building from source...")
    include(ExternalProject)
    ExternalProject_Add(
        glog
        GIT_REPOSITORY https://github.com/google/glog.git
        GIT_TAG v0.7.1  
        CMAKE_ARGS 
        -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/glog_build
        -DBUILD_SHARED_LIBS:BOOL=FALSE  
        -DBUILD_EXAMPLES:BOOL=FALSE
        -DWITH_GTEST:BOOL=FALSE
    )
    include_directories(${CMAKE_BINARY_DIR}/glog-prefix)
    link_directories(${CMAKE_BINARY_DIR}/glog_build/lib)
endif()
