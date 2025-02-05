#include "visual_parser.h"


VisualParser::VisualParser()
{
    this->p_ = std::make_shared<Visual>();
}


void VisualParser::print(std::ostream &os) 
{
    os << "Parsed Visual = [";
    p_->print(os);
    os << "]";
}


bool VisualParser::empty() const
{
    return this->p_->empty();
}


void VisualParser::clear()
{
    p_->clear();
}


const char *VisualParser::getTypename()
{
    return this->p_->getTypename();
}


VisualParser::~VisualParser(){}


bool VisualParser::isA(const char *name)
{
    return p_->isA(name);
}


void VisualParser::parse(const tinyxml2::XMLElement *xml)
{
    ParserBase<Visual>::parse(xml);
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
    const tinyxml2::XMLElement * material_xml = xml->FirstChildElement("material");
    if(material_xml){
        MaterialParser mp;
        mp.parse(material_xml);
        const auto mp_ptr = mp.get();
        p_->setMaterial(mp_ptr);
    }
}

std::shared_ptr<Visual> VisualParser::get()
{
    return p_;
};
