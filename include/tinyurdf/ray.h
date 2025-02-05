#ifndef INCLUDE_TINYURDF_CORE_RAY_H_
#define INCLUDE_TINYURDF_CORE_RAY_H_

// Copyright 2025 Wissem CHIHA

#include <vector>

/**
 * @brief Class representing a ray in the system.
 * This class stores information related to distances, intensities, and angles 
 * for rays used in the system.
 */
class Ray {
public:
  Ray();
  ~Ray();
  void setDistances(const std::vector<double>& d);
  void getDistances(std::vector<double>& d) const;
  void setIntensities(const std::vector<double>& i);
  void getIntensities(std::vector<double>& i) const;
  void setHorizontalMinAngle(double a);
  void getHorizontalMinAngle(double& a) const;
  void setHorizontalMaxAngle(double a);
  void getHorizontalMaxAngle(double& a) const;
  void setVerticalMinAngle(double a);
  void getVerticalMinAngle(double& a) const;
  void setVerticalMaxAngle(double a);
  void getVerticalMaxAngle(double& a) const;
  void setHorizontalSamples(int s);
  void getHorizontalSamples(int& s) const;
  void setVerticalSamples(int s);
  void getVerticalSamples(int& s) const;
  void setResolution(double r);
  void getResolution(double& r) const;
  void update();
  void reset();
  void getDistances(std::vector<double>& d, std::vector<double>& i) const;
  void getTypename(const char* t) const;
private:
  std::vector<double> distances;
  std::vector<double> intensities;
  double horizontal_min_angle;
  double horizontal_max_angle;
  double vertical_min_angle;
  double vertical_max_angle;
  int    horizontal_samples;
  int    vertical_samples;
  double resolution;
};

#endif  // INCLUDE_TINYURDF_CORE_RAY_H_
