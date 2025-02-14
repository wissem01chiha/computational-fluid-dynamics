#include "internal/pose_parser.h"

PoseParser::PoseParser() {
  this->p_ = std::make_shared<Pose>();
}

std::string PoseParser::toString() const {

  std::ostringstream os;
  os << "Parsed Pose = [";
  os << p_->toString();
  os << "]";
  return os.str();
}

bool PoseParser::empty() const {
  return false;
}

void PoseParser::clear() {
  p_->clear();
}

const char* PoseParser::getTypename() const {
  return "pose";
}

bool PoseParser::isA(const char* name) const {
  return p_->isA(name);
}

void PoseParser::parse(const tinyxml2::XMLElement* xml) {
  ParserBase<Pose>::parse(xml);

  const char* xyz_str = xml->Attribute("xyz");
  const char* rpy_str = xml->Attribute("rpy");

  if (xyz_str) {
    double v[3];
    str2array(xyz_str, v);
    p_->setPosition(v[0], v[1], v[2]);
  }

  if (rpy_str) {
    double r[3];
    str2array(rpy_str, r);
    p_->setRotation(r[0], r[1], r[2]);
  }
}

std::shared_ptr<Pose> PoseParser::get() {
  return p_;
}
