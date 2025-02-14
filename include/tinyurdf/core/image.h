#ifndef INCLUDE_TINYURDF_CORE_IMAGE_H_
#define INCLUDE_TINYURDF_CORE_IMAGE_H_

// Copyright 2025 Wiisem CHIHA

#include <string>
#include <vector>
#include <stb/stb_image.h>
#include <loguru/loguru.hpp>

/**
 * @brief base image class definition  
 * @tparam T image data type storage
 * @tparam Channels
 * @todo  create a  port for opencv cv::Mat image convert or load 
 */
template <typename T = double, std::size_t Channels = 4>
class Image {
 public:
   /// @brief Alias for the type used to represent individual pixel values
   using value_type = T;

   /// @brief Default-construct a new image object
   Image();

   /// @brief Copy-construct a new image object
   Image(const Image& other);

   /// @brief Move-construct a new image object
   Image(Image&& other) noexcept;

   /// @brief Construct a new image object with the given width and height
   Image(std::size_t width, std::size_t height);

   /**
   * @brief construct a new image object with the given width and height and
   * initialize it with the provided data.
   * The data array is assumed to have the following properties:
   * - planar memory layout (i.e. all red samples before all green samples
   *   before all blue samples, etc.)
   */
   Image(const T* data, std::size_t width, std::size_t height);

   /// @brief Load an image from a file
   Image& imread(const std::string& filename);

   /// @brief get direct access to the underlying data
   T* data() noexcept;

   /// @brief get direct access to the underlying data
   const T* data() const noexcept;

   /// @brief Get the width of the image
   std::size_t width() const;

   /// @brief Get the height of the image
   std::size_t height() const;

   /// @brief Get the number of channels in the image
   constexpr std::size_t channels() const;

   /// @brief Get the size of the data array containing the image
   constexpr std::size_t size() const;

   /// @brief Get a reference to the sample at the specified offset
   T& operator[](std::size_t offset);
  
   /// @brief Get a reference to the sample at the specified offset
   const T& operator[](std::size_t offset) const;

   /// @brief copy assign operator 
   Image& operator=(const Image& other) ;

 private:
   std::size_t m_width;
   std::size_t m_height;
   std::vector<T> m_data;
};
#endif  // INCLUDE_TINYURDF_CORE_IMAGE_H_
