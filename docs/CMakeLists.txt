cmake_minimum_required(VERSION 3.22.1 FATAL_ERROR)
find_package(Doxygen REQUIRED)
set(DOXYFILE_IN ${CMAKE_SOURCE_DIR}/docs/Doxyfile)
set(DOXYFILE_OUT ${CMAKE_BINARY_DIR}/Doxyfile)
configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)
add_custom_target(documents ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM
)
add_dependencies(documents tinyurdf)