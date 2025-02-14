#include "internal/model_parser.h"

ModelParser::ModelParser()
{
    p_= std::make_shared<Model>();
}

void ModelParser::parse(const tinyxml2::XMLElement *xml)
{
    ParserBase<Model>::parse(xml);
    LOG_F(INFO, "Parsing Model links ...");
    const tinyxml2::XMLElement* link_xml = xml->FirstChildElement("link");
    while (link_xml)
    {
        LinkParser parser;
        parser.parse(link_xml);
        auto link = parser.get();
        p_->setLink(link);
        link_xml = link_xml->NextSiblingElement("link");
    }
    LOG_F(INFO, "Parsing Model joints ...");
    const tinyxml2::XMLElement* joint_xml = xml->FirstChildElement("joint");
    int i =0; 
    while (joint_xml)
    {
      JointParser parser;
      parser.parse(joint_xml);
      const auto joint = parser.get();
       p_->setJoint(joint);
       joint_xml = joint_xml->NextSiblingElement("joint");
    }
    LOG_F(INFO, "Model parsed successfully");
}

std::shared_ptr<Model> ModelParser::get()
{
    return p_;
}

std::string ModelParser::toString() const  
{
    std::ostringstream os;
    os << "Parsed Model :[" ;
    os << p_->toString();
    os << "]\n";
    return os.str();
}

bool ModelParser::isA(const char *name) const 
{
    return p_->isA(name);
}

bool ModelParser::empty() const
{
    return p_->empty();
}

void ModelParser::clear()
{
    p_->clear();
}

const char *ModelParser::getTypename() const 
{
    return p_->getTypename();
};
