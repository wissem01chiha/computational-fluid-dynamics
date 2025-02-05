#include "inertia_parser.h"

InertiaParser::InertiaParser() {
  this->p_ = std::make_shared<Inertia>();
}

void InertiaParser::print(std::ostream& os)  {
  os << "Parsed Inertia = [";
  p_->print(os);
  os << "]";
}

bool InertiaParser::empty() const {
  return false;
}

void InertiaParser::clear() {
  p_->clear();
}

const char* InertiaParser::getTypename() {
  return p_->getTypename();
}

bool InertiaParser::isA(const char* name) {
  return std::string(name) == "inertia_parser";
}

void InertiaParser::parse(const tinyxml2::XMLElement* xml) {
  ParserBase<Inertia>::parse(xml);

  const tinyxml2::XMLElement* origin_xml = xml->FirstChildElement("origin");
  PoseParser pp;
  pp.parse(origin_xml);
  const auto pose = pp.get();
  Vec3 v = pose->getPosition();
  p_->setOrigin(v[0], v[1], v[2]);

  const tinyxml2::XMLElement* mass_xml = xml->FirstChildElement("mass");
  PropertyParser<double> massParser;
  massParser.parse(mass_xml);
  auto parsedData = massParser.get();
  p_->setMass((*parsedData)["value"]);

  const tinyxml2::XMLElement* inertia_xml = xml->FirstChildElement("inertia");
  PropertyParser<double> tensorParser;
  tensorParser.parse(inertia_xml);
  auto tensorParsedData = tensorParser.get();
  p_->setIxx((*tensorParsedData)["ixx"]);
  p_->setIxy((*tensorParsedData)["ixy"]);
  p_->setIxz((*tensorParsedData)["ixz"]);
  p_->setIyy((*tensorParsedData)["iyy"]);
  p_->setIyz((*tensorParsedData)["iyz"]);
  p_->setIzz((*tensorParsedData)["izz"]);
}

std::shared_ptr<Inertia> InertiaParser::get() {
  return p_;
}
