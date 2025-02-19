#include "common/property_parser.h"

template <typename T>
PropertyParser<T>::PropertyParser() {
    p_ = std::make_shared<std::unordered_map<std::string, T>>();
}

template <typename T>
PropertyParser<T>::~PropertyParser() {}

template <typename T>
std::string PropertyParser<T>::toString() const {
    std::ostringstream oss;
    oss << "Parsed Property-Values = [";
    bool first = true;
    for (const auto& pair : *p_) {
        if (!first) oss << ", ";
        oss << pair.first << "=" << pair.second;
        first = false;
    }
    oss << "]";
    return oss.str();
}

template <typename T>
bool PropertyParser<T>::empty() const {
    return p_->empty();
}

template <typename T>
void PropertyParser<T>::clear() {
    p_->clear();
}

template <typename T>
const char* PropertyParser<T>::getTypename() const {
    return "property_value_parser";
}

template <typename T>
bool PropertyParser<T>::isA(const char* name) const {
    return std::string(name) == "property_value_parser";
}

template <typename T>
void PropertyParser<T>::parse(const tinyxml2::XMLElement* xml) {
    ParserBase<std::unordered_map<std::string, T>>::parse(xml);
    const tinyxml2::XMLAttribute* attr = xml->FirstAttribute();

    while (attr) {
        if constexpr (std::is_same_v<T, double>) {
            double val;
            str2double(attr->Value(), val);
            (*p_)[std::string(attr->Name())] = val;
        } else if constexpr (std::is_same_v<T, std::string>) {
            (*p_)[std::string(attr->Name())] = std::string(attr->Value());
        } else {
            LOG_F(ERROR, "failed to parse attribute: unsupported type for conversion");
        }
        attr = attr->Next();
    }
}

template <typename T>
std::shared_ptr<std::unordered_map<std::string, T>> PropertyParser<T>::get() {
    return p_;
}

template class PropertyParser<double>;
template class PropertyParser<std::string>;
template class PropertyParser<float>;
template class PropertyParser<const char*>;