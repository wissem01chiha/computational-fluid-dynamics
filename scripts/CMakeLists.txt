cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)
set(TINYURDF_SCRIPT_SOURCES
    parse.cc
)
if(USE_VTK)  
    set(TINYURDF_SCRIPT_SOURCES
        ${TINYURDF_SCRIPT_SOURCES}
        render.cc
    )
endif(USE_VTK)
foreach(SCRIPT_SOURCE_FILE IN LISTS TINYURDF_SCRIPT_SOURCES)
    get_filename_component(SCRIPT_EXECUTABLE_NAME ${SCRIPT_SOURCE_FILE} NAME_WE)
    add_executable(${SCRIPT_EXECUTABLE_NAME} ${SCRIPT_SOURCE_FILE})
    target_include_directories(${SCRIPT_EXECUTABLE_NAME} PRIVATE ${TINYURDF_INCLUDE_DIRECTORIES})
    target_link_libraries(${SCRIPT_EXECUTABLE_NAME} PRIVATE tinyurdf)
    if(USE_VTK)
        target_link_libraries(${SCRIPT_EXECUTABLE_NAME} PRIVATE ${VTK_LIBRARIES})
        vtk_module_autoinit(
            TARGETS ${SCRIPT_EXECUTABLE_NAME}
            MODULES ${VTK_LIBRARIES}
        )
    endif(USE_VTK)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
            target_compile_options(${SCRIPT_EXECUTABLE_NAME} PRIVATE -g  -DDEBUG)
        elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
            target_compile_options(${SCRIPT_EXECUTABLE_NAME} PRIVATE /Zi /DDEBUG)
            target_link_options(${SCRIPT_EXECUTABLE_NAME} PRIVATE /DEBUG)
        endif()
        
    endif()
    add_dependencies(${SCRIPT_EXECUTABLE_NAME} tinyurdf)
endforeach()