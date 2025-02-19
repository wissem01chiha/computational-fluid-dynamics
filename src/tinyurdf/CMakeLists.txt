cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
set(SOURCE_FILES "")
add_subdirectory(core)
add_subdirectory(utility)
add_subdirectory(internal)
add_subdirectory(common)
add_subdirectory(detail)
add_library(tinyurdf ${SOURCE_FILES})
target_include_directories(tinyurdf
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include/tinyurdf
    ${CMAKE_SOURCE_DIR}/thirdparty
)
target_link_libraries(tinyurdf PUBLIC 
            Eigen3::Eigen loguru tinyxml2)
if (BUILD_SHARED_LIBS)
    set_target_properties(tinyurdf PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()
