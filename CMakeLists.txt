cmake_minimum_required(VERSION 3.10)

project(DynaSfM VERSION 1.0.0)

set(USE_CUDA  OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})

set(BUILD_SHARED_LIBS  OFF)
set(BUILD_TESTS        OFF)
set(USE_VTK            OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -DDEBUG")
    elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
    endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Od")
endif()
if(WIN32)
    cmake_policy(SET CMP0135 NEW)
endif()
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS 1)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
include(External-Eigen)
#include (External-OpenCV)

if (BUILD_TESTS)
    include(External-GTest)
endif()

if(USE_VTK)
    include(External-VTK)
endif(USE_VTK)

add_subdirectory(extern/loguru)
add_subdirectory(extern/cnpy)

if (BUILD_SHARED_LIBS)
    set_target_properties(tinyurdf PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

if (BUILD_TESTS)
    add_subdirectory(test)
endif(BUILD_TESTS)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include DESTINATION include)