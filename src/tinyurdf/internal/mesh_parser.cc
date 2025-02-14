#include "internal/mesh_parser.h"

MeshParser::MeshParser() {
  p_ = std::make_shared<Mesh>();
}

void MeshParser::parse(const tinyxml2::XMLElement* xml) {
  ParserBase<Mesh>::parse(xml);

  const char* scale_str = xml->Attribute("scale");
  const char* mesh_str = xml->Attribute("filename");
  const char* color_str = xml->Attribute("color");

  double s[3] = {0.0, 0.0, 0.0};

  if (scale_str) {
    str2array(scale_str, s);
    p_->setScale(s[0], s[1], s[2]);
  }

  if (mesh_str) {
    p_->setFilename(std::string(mesh_str));
  }

  if (color_str) {
    Color c_ = Color(std::string(color_str));
    p_->setColor(c_);
  }
}

bool MeshParser::isA(const char* name) const {
  return p_->isA(name);
}

const char* MeshParser::getTypename() const {
  return p_->getTypename();
}

std::string MeshParser::toString() const {

  std::ostringstream os;
  os << "Parsed mesh = [";
  os << p_->toString();
  os << "]";
  return os.str();
}

bool MeshParser::empty() const {
  return p_ == nullptr;
}

void MeshParser::clear() {
  p_->clear();
}

std::shared_ptr<Mesh> MeshParser::get() {
  return p_;
}

MeshParser::~MeshParser() = default;
