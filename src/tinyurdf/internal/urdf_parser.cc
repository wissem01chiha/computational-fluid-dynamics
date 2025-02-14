#include "internal/urdf_parser.h"

URDFParser::URDFParser()
{
    this->model_ = std::make_shared<Model>();
}

void URDFParser::parse(const tinyxml2::XMLElement *xml)
{
    ModelParser mp;
    mp.parse(xml);
    this->model_ = mp.get();
}

void URDFParser::parse(const char *filename)
{
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError eResult = doc.LoadFile(filename);
    if (eResult != tinyxml2::XML_SUCCESS) {
        LOG_F(ERROR, "Error loading XML file: %s" , doc.ErrorStr());
    }
    else {
        const tinyxml2::XMLElement *xml = doc.FirstChildElement("robot");
        if(xml) {
            LOG_F(ERROR, "Error: This is not a valid URDF file format");
            return;
        }
        VersionParser vp;
        vp.parse(&doc);
        this->parse(xml);
    }
}

void URDFParser::parse(const std::string &filename)
{
    this->parse(filename.c_str());
}

std::shared_ptr<Model> URDFParser::get()
{
    return this->model_;
}

std::string URDFParser::toString() const
{
    std::ostringstream os;
    os << this->model_->toString();
    return os.str();
}

bool URDFParser::isA(const char *name) const 
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

const char *URDFParser::getTypename() const
{
    return this->model_->getTypename();
}

URDFParser::~URDFParser(){}