#include "material_parser.h"

MaterialParser::MaterialParser() {
    this->p_ = std::make_shared<Material>();
}

void MaterialParser::print(std::ostream& os)  {
    os << "Parsed Material = [";
    p_->print(os);
    os << "]";
}

bool MaterialParser::empty() const {
    return false;
}

void MaterialParser::clear() {
    p_->clear();
}

const char* MaterialParser::getTypename() {
    return "material";
}

bool MaterialParser::isA(const char* name) {
    return p_->isA(name);
}

void MaterialParser::parse(const tinyxml2::XMLElement* xml) {
    const char* name_mat_str = xml->Attribute("name");
    if (name_mat_str) {
        p_->setName(std::string(name_mat_str));
    }
    
    const tinyxml2::XMLElement* density_xml = xml->FirstChildElement("density");
    PropertyParser<double> dp;
    dp.parse(density_xml);
    const auto d = dp.get();
    p_->setDensity((*d)["value"]);

    const tinyxml2::XMLElement* color_xml = xml->FirstChildElement("color");
    ColorParser cp;
    cp.parse(color_xml);
    const auto cd = cp.get();
    double r, g, b, a;
    r = cd->getR(); g = cd->getG(); b = cd->getB(); a = cd->getA();
    p_->setColor(r, g, b, a);

    const tinyxml2::XMLElement* txt_xml = xml->FirstChildElement("texture");
    PropertyParser<std::string> sp;
    sp.parse(txt_xml);
    const auto dsp = sp.get();
    p_->setFilename((*dsp)["filename"]);
}

std::shared_ptr<Material> MaterialParser::get() {
    return p_;
}

MaterialParser::~MaterialParser() = default;
