#include <pybind11/pybind11.h>

namespace py = pybind11;

#include "pyurdf_parser.cc"
#include "pyurdf_render.cc"

PYBIND11_MODULE(pytinyurdf, m) {
    m.doc() = "Python bindings for TinyURDF";  
    init_pyurdf_render(m);
    init_pyurdf_parser(m);
}