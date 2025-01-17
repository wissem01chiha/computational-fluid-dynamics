cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
find_package(Eigen3 QUIET)

if(Eigen3_FOUND)
    message(STATUS "Eigen3 found: ${Eigen3_DIR}")
else()
    message(STATUS "Eigen3 not found. Downloading and building from source...")
    include(FetchContent)
    FetchContent_Declare(
        eigen
        URL https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.gz
    )
    FetchContent_MakeAvailable(eigen)
    if(TARGET eigen) 
        get_target_property(Eigen3_INCLUDE_DIRS eigen INTERFACE_INCLUDE_DIRECTORIES) 
        message(STATUS "Eigen3 has been fetched and is available at ${Eigen3_INCLUDE_DIRS}") 
        include_directories(${Eigen3_INCLUDE_DIRS}) 
    endif()
endif()
