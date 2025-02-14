#include "internal/link_parser.h"

LinkParser::LinkParser(){
  p_ = std::make_shared<Link>();
}

void LinkParser::parse(const tinyxml2::XMLElement *xml)
{
  ParserBase<Link>::parse(xml);
  const char* link_name = ParserBase::getNameOf(xml);
  p_->setName(std::string(link_name));
  const tinyxml2::XMLElement* inertia_xml = xml->FirstChildElement("inertial");
  if(inertia_xml){

    InertiaParser ip;
    ip.parse(inertia_xml);
    const auto id = ip.get();
    p_->setInertia(id);
  }

  const tinyxml2::XMLElement* collision_xml = xml->FirstChildElement("collision");
  if(collision_xml)
  {
    CollisionParser coop;
    coop.parse(collision_xml);
    const auto co_ptr = coop.get();
    p_->setCollision(co_ptr);
  }
  const tinyxml2::XMLElement* viusal_xml = xml->FirstChildElement("visual");
  if(viusal_xml)
  {
    VisualParser vp;
    vp.parse(viusal_xml);
    const auto vi_ptr = vp.get();
    p_->setVisual(vi_ptr);
  }
}

bool LinkParser::isA(const char *name) const 
{
  return p_->isA(name);
}

bool LinkParser::empty() const
{
  return p_->empty();
}

void LinkParser::clear()
{
  p_->clear();
}

std::string LinkParser::toString() const
{
  std::ostringstream os;
  os << "Parsed Link = [";
  os << p_->toString();
  os << "]\n";
  return os.str();
}

const char *LinkParser::getTypename() const 
{
  return p_->getTypename();
}

std::shared_ptr<Link> LinkParser::get()
{
  return p_;
}
