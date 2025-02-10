#ifndef INCLUDE_TINYURDF_IMAGE_H_
#define INCLUDE_TINYURDF_IMAGE_H_

// Copyright 2025 Wiisem CHIHA

#include <vector>
#include <utility>
#include <cstddef>

template <typename T = double, std::size_t Channels = 4>
class Image {
public:
   /// Alias for the type used to represent individual pixel values
   using value_type = T;
   /// Default-construct a new image object
   Image();
   /// Copy-construct a new image object
   Image(const Image& other);
   /// Move-construct a new image object
   Image(Image&& other) noexcept;
   /// Construct a new image object with the given width and height
   Image(std::size_t width, std::size_t height);
   /**
   * Construct a new image object with the given width and height and
   * initialize it with the provided data.
   * The data array is assumed to have the following properties:
   * - Planar memory layout (i.e. all red samples before all green samples
   *   before all blue samples, etc.)
   */
   Image(const T* data, std::size_t width, std::size_t height);
   /// Get direct access to the underlying data
   T* data() noexcept;
   const T* data() const noexcept;
   /// Get the width of the image
   std::size_t width() const;
   /// Get the height of the image
   std::size_t height() const;
   /// Get the number of channels in the image
   constexpr std::size_t channels() const;
   /// Get the size of the data array containing the image
   constexpr std::size_t size() const;
   /// Get a reference to the sample at the specified offset
   T& operator[](std::size_t offset);
   const T& operator[](std::size_t offset) const;
 private:
   std::size_t m_width;
   std::size_t m_height;
   std::vector<T> m_data;
};
#endif  // INCLUDE_TINYURDF_CORE_IMAGE_H_
