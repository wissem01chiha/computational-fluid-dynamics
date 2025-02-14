cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

find_package(pybind11 QUIET)
if(pybind11_FOUND)
    message(STATUS "Pybind Found : ${pybind11_INCLUDE_DIRS}")
else()
    include(FetchContent)
    set(FETCHCONTENT_QUIET FALSE)
    FetchContent_Declare(
    pybind11
    URL https://github.com/pybind/pybind11/archive/v2.13.6.tar.gz
    )
    FetchContent_GetProperties(pybind11)
    if(NOT pybind11_POPULATED)
        FetchContent_Populate(pybind11)
        add_subdirectory(${pybind11_SOURCE_DIR} ${pybind11_BINARY_DIR})
    endif()
endif(pybind11_FOUND)