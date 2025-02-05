#include "color_parser.h"

ColorParser::ColorParser() {
    this->p_ = std::make_shared<Color>();
}

void ColorParser::print(std::ostream& os)  {
    os << "Parsed Color = [";
    p_->print(os);
    os << "]";
}

bool ColorParser::empty() const {
    return false;
}

void ColorParser::clear() {
    p_->clear();
}

const char* ColorParser::getTypename() {
    return "color";
}

bool ColorParser::isA(const char* name) {
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
