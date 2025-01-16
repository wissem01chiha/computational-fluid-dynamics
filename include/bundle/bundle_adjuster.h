#pragma once 

#include <string>
#include <ceres/ceres.h>
#include <eigen3/Eigen/Core>

class BundleAdjuster{
public:
  BundleAdjuster();
  bool solve(const std::vector<unsigned int>& view_indices) const;
  void setMaxNumIteratons(unsigned int n);
  ~BundleAdjuster();
 private:
  unsigned int max_num_iterations = 50;
  double gradient_tolerance = 1e-16;
  double function_tolerance = 1e-16;
  std::string solver_type = "SPARSE_SCHUR";
};  