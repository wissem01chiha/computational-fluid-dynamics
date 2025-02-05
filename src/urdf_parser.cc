#include "urdf_parser.h"

URDFParser::URDFParser()
{
    this->model_ = std::make_shared<Model>();
}

void URDFParser::parse(const std::string &filename)
{
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError eResult = doc.LoadFile(filename.c_str());
    if (eResult != tinyxml2::XML_SUCCESS) {
        LOG_F(ERROR, "Error loading XML file: %s" , doc.ErrorStr());
    }
    else {
        const tinyxml2::XMLElement *xml;
        const tinyxml2::XMLElement *xml1 = doc.FirstChildElement("model");
        const tinyxml2::XMLElement *xml2 = doc.FirstChildElement("robot");
        if(xml1 == nullptr & xml2 == nullptr) {
            LOG_F(ERROR, "Error: This is not a valid URDF file format");
        }else if(xml1){
            xml = xml1;
        }else {
            xml = xml2;
        }
        ModelParser mp;
        //VersionParser vp;
        mp.parse(xml);
        //vp.parse(&doc);
        this->model_ = mp.get();
    }
}

void URDFParser::parse(const char *filename)
{
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError eResult = doc.LoadFile(filename);
    if (eResult != tinyxml2::XML_SUCCESS) {
        LOG_F(ERROR, "Error loading XML file: %s" , doc.ErrorStr());
    }
    else {
        const tinyxml2::XMLElement *xml;
        const tinyxml2::XMLElement *xml1 = doc.FirstChildElement("model");
        const tinyxml2::XMLElement *xml2 = doc.FirstChildElement("robot");
        if(xml1 == nullptr & xml2 == nullptr) {
            LOG_F(ERROR, "Error: This is not a valid URDF file format");
        }else if(xml1){
            xml = xml1;
        }else {
            xml = xml2;
        }
        ModelParser mp;
        //VersionParser vp;
        mp.parse(xml);
        //vp.parse(&doc);
        this->model_ = mp.get();
    }
}

void URDFParser::parse(const tinyxml2::XMLElement *xml)
{
    ModelParser mp;
    mp.parse(xml);
    this->model_ = mp.get();
}

std::shared_ptr<Model> URDFParser::get()
{
    return this->model_;
}

void URDFParser::print(std::ostream &os) 
{
    this->model_->print(os);
}

bool URDFParser::isA(const char *name)
{
    return this->model_->isA(name);
}

bool URDFParser::empty() const
{
    return this->model_->empty();
}

void URDFParser::clear()
{
    this->model_->clear();
}

const char *URDFParser::getTypename()
{
    return this->model_->getTypename();
}

URDFParser::~URDFParser(){}