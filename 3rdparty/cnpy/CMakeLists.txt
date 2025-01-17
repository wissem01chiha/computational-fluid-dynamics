find_package(ZLIB REQUIRED)
add_library(cnpy cnpy.cpp)
target_link_libraries(cnpy PRIVATE ZLIB::ZLIB)