cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)
enable_testing()
set(TINYURDF_TEST_SOURCES
    geometry_parser_test.cc
    inertia_parser_test.cc
    version_test.cc
    pose_test.cc
    color_test.cc
    joint_test.cc
    mesh_test.cc
    link_test.cc
    pose_parser_test.cc
    property_parser_test.cc
    visual_parser_test.cc
    collision_parser_test.cc
    link_parser_test.cc
    joint_parser_test.cc
    utils_test.cc
    model_test.cc
    model_parser_test.cc
    material_parser_test.cc
)
if(USE_VTK)  
    set(TINYURDF_TEST_SOURCES 
        ${TINYURDF_TEST_SOURCES}
        vtk_joint_renderer_test.cc
        vtk_link_renderer_test.cc
        vtk_model_renderer_test.cc
    )
endif(USE_VTK)
foreach(TEST_SOURCE_FILE IN LISTS TINYURDF_TEST_SOURCES)
    get_filename_component(TEST_EXECUTABLE_NAME ${TEST_SOURCE_FILE} NAME_WE)
    add_executable(${TEST_EXECUTABLE_NAME} ${TEST_SOURCE_FILE})
    target_include_directories(${TEST_EXECUTABLE_NAME} PRIVATE ${TINYURDF_INCLUDE_DIRECTORIES})
    target_link_libraries(${TEST_EXECUTABLE_NAME} PRIVATE GTest::gtest_main tinyurdf)
    if(USE_VTK)
        target_link_libraries(${TEST_EXECUTABLE_NAME} PRIVATE ${VTK_LIBRARIES})
        vtk_module_autoinit(
            TARGETS ${TEST_EXECUTABLE_NAME}
            MODULES ${VTK_LIBRARIES}
        )
    endif(USE_VTK)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
            target_compile_options(${TEST_EXECUTABLE_NAME} PRIVATE -g  -DDEBUG)
        elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
            target_compile_options(${TEST_EXECUTABLE_NAME} PRIVATE /Zi /DDEBUG)
            target_link_options(${TEST_EXECUTABLE_NAME} PRIVATE /DEBUG)
        endif()
        
    endif()
    add_dependencies(${TEST_EXECUTABLE_NAME} tinyurdf)
    include(GoogleTest)
    gtest_discover_tests(${TEST_EXECUTABLE_NAME})
endforeach()