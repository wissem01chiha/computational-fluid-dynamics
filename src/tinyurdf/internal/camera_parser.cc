#include "internal/camera_parser.h"

CameraParser::CameraParser()
{
    p_ = std::make_shared<Camera>();
}

void CameraParser::parse(const tinyxml2::XMLElement* xml) {
    
    ParserBase<Camera>::parse(xml);
    const char* name = ParserBase<Camera>::getNameOf(xml);
    const char* ur_str = xml->Attribute("update_rate");
    double d_ur;
    str2double(ur_str,d_ur);
    p_->setUpdateRate(d_ur);
    const tinyxml2::XMLElement* parent_xml = xml->FirstChildElement("parent");
    if(parent_xml){

    }
    const tinyxml2::XMLElement * origin_xml = xml->FirstChildElement("origin");
    if(origin_xml){
        PoseParser op;
        op.parse(origin_xml);
        const auto o = op.get();
        p_->setOrigin(o);
    }
    const tinyxml2::XMLElement * camera_xml = xml->FirstChildElement("camera");
    if(camera_xml){
        const  tinyxml2::XMLElement * image_xml = camera_xml->FirstChildElement("image");
        if(image_xml){
            PropertyParser<double> pp;
            pp.parse(image_xml);
            const auto data = pp.get();
            p_->setHfov((*data)["hfov"]);
            p_->setFar((*data)["far"]);
            p_->setNear((*data)["near"]);
            double d_w = (*data)["width"];
            double h_w = (*data)["height"];
            std::size_t width = static_cast<std::size_t>(d_w);
            std::size_t height = static_cast<std::size_t>(h_w);
            p_->set(std::make_shared<Image<double,4>>( width, height));
        }
    }
}

std::shared_ptr<Camera> CameraParser::get() {
    return p_;
}

const char* CameraParser::getTypename() const {
    return p_->getTypename();
}

bool CameraParser::isA(const char* name) const {
    return std::string(name) == getTypename();
}

bool CameraParser::empty() const {
    return p_ == nullptr;
}

void CameraParser::clear() {
    p_.reset();
}

std::string CameraParser::toString() const {
    return p_->toString();
}