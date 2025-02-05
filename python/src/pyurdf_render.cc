#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>  
#include "urdf_renderer.h"
#include <vtkSmartPointer.h>  

namespace py = pybind11;

void init_pyurdf_render(py::module &m) {
    py::class_<URDFRenderer, std::shared_ptr<URDFRenderer>>(m, "URDFRenderer")
        .def(py::init<>())  
        .def("setModel", &URDFRenderer::setModel, "Set the URDF model")
        .def("show", &URDFRenderer::show, "Display the renderer")
        .def("setBackground", &URDFRenderer::setBackrgournd,  
             "Set the background color",
             py::arg("r"), py::arg("g"), py::arg("b"), py::arg("a"))
        .def("setWindowSize", &URDFRenderer::setWindowSize,  
             "Set the render window size",
             py::arg("width"), py::arg("height"))
        .def("getModel", &URDFRenderer::getModel, py::return_value_policy::reference_internal,
             "Get the current URDF model");
}

PYBIND11_MODULE(pyurdf_render, m) {
    m.doc() = "Python bindings for URDF Render"; 
    init_pyurdf_render(m);
}