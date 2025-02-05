#include "collision_parser.h"

CollisionParser::CollisionParser()
{
    this->p_ = std::make_shared<Collision>();
}

void CollisionParser::print(std::ostream &os) 
{
    os << "Parsed Collision = [";
    p_->print(os);
    os << "]";
}

bool CollisionParser::empty() const
{
    return false;
}

void CollisionParser::clear()
{
    this->p_->clear();
}

const char *CollisionParser::getTypename()
{
    return "collision";
}

bool CollisionParser::isA(const char *name)
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
