#include "internal/color_parser.h"

ColorParser::ColorParser() {
    this->p_ = std::make_shared<Color>();
}

std::string ColorParser::toString() const  {
    std::ostringstream os;
    os << "Parsed Color = [";
    os << p_->toString();
    os << "]";
    return os.str();
}

bool ColorParser::empty() const {
    return false;
}

void ColorParser::clear() {
    p_->clear();
}

const char* ColorParser::getTypename() const {
    return "color";
}

bool ColorParser::isA(const char* name) const {
    return std::string(name) == "color_parser";
}

void ColorParser::parse(const tinyxml2::XMLElement* xml) {
    ParserBase<Color>::parse(xml);
    std::string color_string_vector = std::string(xml->Attribute("rgba"));
    p_ = std::make_shared<Color>(color_string_vector);
}

std::shared_ptr<Color> ColorParser::get() {
    return p_;
}
