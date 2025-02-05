cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)

set(TINYURDF_PYTHON_SOURCES
    src/pytinyurdf.cc
    src/pyurdf_parser.cc
)

if(USE_VTK)
    set(TINYURDF_PYTHON_SOURCES 
        ${TINYURDF_PYTHON_SOURCES} 
        src/pyurdf_render.cc
    )
endif(USE_VTK)

foreach(PYTHON_SOURCE_FILE IN LISTS TINYURDF_PYTHON_SOURCES)
    get_filename_component(PYTHON_EXECUTABLE_NAME ${PYTHON_SOURCE_FILE} NAME_WE)
    pybind11_add_module(${PYTHON_EXECUTABLE_NAME} ${PYTHON_SOURCE_FILE})
    target_link_libraries(${PYTHON_EXECUTABLE_NAME} PRIVATE tinyurdf)
endforeach()