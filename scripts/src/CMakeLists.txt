cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
file(GLOB SCRIPT_SOURCES *.cc)
foreach(SCRIPT_SOURCE_FILE IN LISTS SCRIPT_SOURCES)
    get_filename_component(SCRIPT_EXECUTABLE_NAME ${SCRIPT_SOURCE_FILE} NAME_WE)
    add_executable(${SCRIPT_EXECUTABLE_NAME} ${SCRIPT_SOURCE_FILE})
    target_include_directories(${SCRIPT_EXECUTABLE_NAME} PRIVATE 
                                ${CMAKE_SOURCE_DIR}/include
                                ${CMAKE_SOURCE_DIR}/thirdparty
                            )
    target_link_libraries(${SCRIPT_EXECUTABLE_NAME} PRIVATE tinyurdf)
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