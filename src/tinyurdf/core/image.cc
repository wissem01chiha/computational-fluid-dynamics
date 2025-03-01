#define STB_IMAGE_IMPLEMENTATION 1 
#include "core/image.h"

template <typename T, std::size_t Channels>
Image<T, Channels>::Image() : m_width(0), m_height(0), m_data() {}

template <typename T, std::size_t Channels>
Image<T, Channels>::Image(const Image& other)
    : m_width(other.m_width), m_height(other.m_height), m_data(other.m_data) {}

template <typename T, std::size_t Channels>
Image<T, Channels>::Image(Image&& other) noexcept
    : m_width(other.m_width), m_height(other.m_height), m_data(std::move(other.m_data)) {}

template <typename T, std::size_t Channels>
Image<T, Channels>::Image(std::size_t width, std::size_t height)
    : m_width(width), m_height(height), m_data(width * height * Channels, T{}) {}

template <typename T, std::size_t Channels>
Image<T, Channels>::Image(const T* data, std::size_t width, std::size_t height)
    : m_width(width), m_height(height), m_data(data, data + width * height * Channels) {}

template <typename T, std::size_t Channels>
const T* Image<T, Channels>::data() const noexcept {
    return m_data.data();
}

template <typename T, std::size_t Channels>
T* Image<T, Channels>::data() noexcept {
    return m_data.data();
}

template <typename T, std::size_t Channels>
std::size_t Image<T, Channels>::width() const {
    return m_width;
}

template <typename T, std::size_t Channels>
std::size_t Image<T, Channels>::height() const {
    return m_height;
}

template <typename T, std::size_t Channels>
constexpr std::size_t Image<T, Channels>::channels() const {
    return Channels;
}

template <typename T, std::size_t Channels>
constexpr std::size_t Image<T, Channels>::size() const {
    return m_data.size();
}

template <typename T, std::size_t Channels>
T& Image<T, Channels>::operator[](std::size_t offset) {
    return m_data[offset];
}

template <typename T, std::size_t Channels>
const T& Image<T, Channels>::operator[](std::size_t offset) const {
    return m_data[offset];
}

template <typename T, std::size_t Channels>
Image<T, Channels>& Image<T, Channels>::operator=(const Image& other) {

    if (this != &other) {
        m_width = other.m_width;
        m_height = other.m_height;
        m_data = other.m_data;   
    }
    return *this;
}

template <typename T, std::size_t Channels>
Image<T, Channels>& Image<T, Channels>::imread(const std::string& filename) {

    int w, h, c;
    unsigned char* imageData = stbi_load(filename.c_str(), &w, &h, &c, Channels);

    if (!imageData) {
        LOG_F(ERROR,"Failed to load image: %s", filename.c_str());
        return *this;
    }

    m_width = static_cast<std::size_t>(w);
    m_height = static_cast<std::size_t>(h);
    m_data.assign(imageData, imageData + (m_width * m_height * Channels));

    stbi_image_free(imageData);
    return *this;
}

template class Image<double,4>;
template class Image<double,3>;
template class Image<float,4>;
template class Image<float,3>;