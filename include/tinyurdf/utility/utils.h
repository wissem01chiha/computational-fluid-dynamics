#ifndef INCLUDE_TINYURDF_UTILITY_UTILS_H_
#define INCLUDE_TINYURDF_UTILITY_UTILS_H_

// Copyright 2025 Wissem CHIHA

#include <string>
#include <vector>
#include <sstream>
#include <Eigen/Dense>
#include <loguru/loguru.hpp>
#ifdef BUILD_3D_ENGINE
    #include <glm/glm.hpp>
    #include <glm/gtc/matrix_transform.hpp>
    #include <glm/gtc/type_ptr.hpp>
#endif
#ifdef USE_OPENMP
    #include <omp.h>
#endif
/**
 * @brief Base struct for 3D position vectors.
 */
using Vec3 = Eigen::Matrix<double, 3, 1>;

/**
 * @brief Base struct for 3D rotation elements.
 */
using Rot3 = Eigen::Quaternion<double>;

/**
 * @brief Constructs an array of double values from a space-separated string.
 * @param str_ The input string containing space-separated numeric values.
 * @param arr Pointer to the output array where values will be stored.
 * @example "1.0 2.3 1.1" -> [1.0, 2.3, 1.1]
 */
void str2array(const char* str_, double* arr);

/**
 * @brief Converts a string to a double value in a locale-safe manner.
 */
void str2double(const char* in, double& num_);

/**
 * @brief Splits a string by a delimiter into a vector of strings.
 * @param str The input string to split.
 * @param split_result Vector to store the resulting substrings.
 * @param delimiter The delimiter used for splitting the string.
 */
void split(const std::string& str, std::vector<std::string>& split_result,
           const std::string& delimiter);

/**
 * @brief Joins a vector of strings into a single string with a given delimiter.
 * @param elements The vector of strings to join.
 * @param delimiter The delimiter to insert between elements.
 */
std::string join(const std::vector<std::string>& elements, const std::string& delimiter);

/**
 * @brief Trims leading and trailing whitespace from a string.
 */
std::string trim(const std::string& str);

/**
 * @brief Converts a string to lowercase.
 */
std::string toLower(const std::string& str);

/**
 * @brief Converts a string to uppercase.
 */
std::string toUpper(const std::string& str);

#endif // INCLUDE_TINYURDF_UTILITY_UTILS_H_