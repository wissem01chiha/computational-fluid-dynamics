#ifndef INCLUDE_TINYURDF_UTILS_H_
#define INCLUDE_TINYURDF_UTILS_H_

// Copyright 2025 Wissem CHIHA

#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>

#include <loguru/loguru.hpp>
#include <Eigen/Dense>

using Vec3 = Eigen::Matrix<double, 3, 1>;
using Rot3 = Eigen::Quaternion<double>;

/// @brief constructs an array of double object from a space-separated string.
/// @example "1.0 2.3 1.1" -> [1.0, 2.3, 1.1]
void str2array(const char* str_, double* arr);

/// @brief a locale-safe version of string-to-double
void str2double(const char *in, double& num_);

///@brief splits a string by a delimiter into a vector of strings.
void split(const std::string& str, std::vector<std::string>& split_result,
    const std::string& delimiter);

#endif // INCLUDE_TINYURDF_UTILS_H_