#include "geometry_parser.h"


GeometryParser::GeometryParser() {}

void GeometryParser::parse(const tinyxml2::XMLElement* xml) {
  if (!xml) {
    return;
  }

  const tinyxml2::XMLNode* geometry_node = xml->FirstChild();
  if (geometry_node) {
    const tinyxml2::XMLElement* geometry_element = geometry_node->ToElement();
    if (!geometry_element) {
      return;
    }

    const char* geometry_name = geometry_element->Name();

    if (std::strcmp(geometry_name, "box") == 0) {
      BoxParser parser;
      parser.parse(geometry_element);
      auto box_ptr = parser.get();
      if (box_ptr) {
        p_ = std::static_pointer_cast<GeometryBase>(box_ptr);
      }
    }

    if (std::strcmp(geometry_name, "sphere") == 0) {
      SphereParser parser;
      parser.parse(geometry_element);
      auto sphere_ptr = parser.get();
      if (sphere_ptr) {
        p_ = std::static_pointer_cast<GeometryBase>(sphere_ptr);
      }
    }

    if (std::strcmp(geometry_name, "cylinder") == 0) {
      CylinderParser parser;
      parser.parse(geometry_element);
      auto cylinder_ptr = parser.get();
      if (cylinder_ptr) {
        p_ = std::static_pointer_cast<GeometryBase>(cylinder_ptr);
      }
    }

    if (std::strcmp(geometry_name, "mesh") == 0) {
      MeshParser parser;
      parser.parse(geometry_element);
      auto mesh_ptr = parser.get();
      if (mesh_ptr) {
        p_ = std::static_pointer_cast<GeometryBase>(mesh_ptr);
      }
    }
  }
}

const char* GeometryParser::getTypename() {
  return p_ ? p_->getTypename() : "unknown";
}

bool GeometryParser::empty() const {
  return p_->empty();
}

void GeometryParser::clear() {
  p_->clear();
}

bool GeometryParser::isA(const char* name) {
  return p_->isA(name);
}

void GeometryParser::print(std::ostream& os) {
  os << "Parsed Geometry = [";
  if (p_) {
    p_->print(os);
  } else {
    os << "None";
  }
  os << "]";
}

std::shared_ptr<GeometryBase> GeometryParser::get() {
  return p_;
}

GeometryParser::~GeometryParser() {}
