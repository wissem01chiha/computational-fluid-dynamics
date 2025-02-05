#include <memory>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>  
#include "urdf_parser.h"

namespace py = pybind11;

void init_model(py::module &m) {
    py::class_<Model, std::shared_ptr<Model>>(m, "Model")
        .def(py::init<>())  
        .def("clear", &Model::clear)
        .def("setName", &Model::setName)
        .def("getName", &Model::getName)
        .def("isA", &Model::isA)
        .def("getTypename", &Model::getTypename)
        .def("empty", &Model::empty)
        .def("setLink", static_cast<void (Model::*)(std::shared_ptr<Link>)>(&Model::setLink))
        .def("setLink", static_cast<void (Model::*)(std::vector<std::shared_ptr<Link>>)>(&Model::setLink))
        .def("setJoint", static_cast<void (Model::*)(std::shared_ptr<Joint>)>(&Model::setJoint))
        .def("setJoint", static_cast<void (Model::*)(std::shared_ptr<Joint>, const std::string&, const std::string&)>(&Model::setJoint))
        .def("getJoints", &Model::getJoints)
        .def("getLinks", &Model::getLinks)
        .def("setJoint", static_cast<void (Model::*)(std::vector<std::shared_ptr<Joint>>)>(&Model::setJoint));
}

void init_pyurdf_parser(py::module &m) {
    py::class_<URDFParser, std::shared_ptr<URDFParser>>(m, "URDFParser")
        .def(py::init<>())  
        .def("get", &URDFParser::get, py::return_value_policy::take_ownership) 
        .def("parse", static_cast<void (URDFParser::*)(const std::string&)>(&URDFParser::parse),
             "Parse URDF from filename")
        .def("parse", static_cast<void (URDFParser::*)(const char*)>(&URDFParser::parse),
             "Parse URDF from C-string filename")
        .def("parse", static_cast<void (URDFParser::*)(const tinyxml2::XMLElement*)>(&URDFParser::parse),
             "Parse URDF from XML element")

        .def("print", [](URDFParser &self) {
            std::ostringstream os;
            self.print(os);
            return os.str();
        }, "Prints the parser's state")
        .def("clear", &URDFParser::clear, "Clears the parser's state")
        .def("isA", &URDFParser::isA, "Check the type of the parser")
        .def("empty", &URDFParser::empty, "Check if the parser is empty")
        .def("getTypename", &URDFParser::getTypename, "Get the type name of the parser");
}

PYBIND11_MODULE(pyurdf_parser, m) {
    m.doc() = "Python bindings for URDF Parser "; 
    init_pyurdf_parser(m);
    init_model(m);
}