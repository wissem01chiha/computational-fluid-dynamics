#include "internal/collision_parser.h"

CollisionParser::CollisionParser()
{
    this->p_ = std::make_shared<Collision>();
}

std::string CollisionParser::toString() const
{
   std::ostringstream os;
    os << "Parsed Collision = [";
    os << p_->toString();
    os << "]";
    return os.str();
}

bool CollisionParser::empty() const
{
    return false;
}

void CollisionParser::clear()
{
    this->p_->clear();
}

const char *CollisionParser::getTypename() const 
{
    return "collision";
}

bool CollisionParser::isA(const char *name) const 
{
    return false;
}

void CollisionParser::parse(const tinyxml2::XMLElement *xml)
{
    ParserBase<Collision>::parse(xml);
    const tinyxml2::XMLElement * o_xml = xml->FirstChildElement("origin");
    if(o_xml){
        PoseParser pp;
        pp.parse(o_xml);
        const auto pp_ptr = pp.get();
        p_->setOrigin(pp_ptr);
    }
    const tinyxml2::XMLElement * geometry_xml = xml->FirstChildElement("geometry");
    
    if(geometry_xml){
        GeometryParser gp;
        gp.parse(geometry_xml);
        const auto gp_ptr = gp.get();
        p_->setGeometry(gp_ptr);
    }
}

std::shared_ptr<Collision> CollisionParser::get()
{
    return this->p_;
}

CollisionParser::~CollisionParser()
{}
