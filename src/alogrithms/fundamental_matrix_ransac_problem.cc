
#include <iostream>

#include <algorithm>
#include <Eigen/Core>
#include <gflags/gflags.h>


#include "ransac_problem.h"
#include "fundamental_matrix_ransac_problem.h"
#include "../math/random_generator.h"
#include "../geometry/eight_point_algorithm_solver.h"
#include "../geometry/fundamental_matrix_solver_options.h"


// ------------ FundamentalMatrixRansacModel methods ------------ //

// Default constructor.
FundamentalMatrixRansacModel::FundamentalMatrixRansacModel()
    : F_(Matrix3d::Identity()), error_(0.0) {}

FundamentalMatrixRansacModel::FundamentalMatrixRansacModel(
    const Matrix3d& F)
    : F_(F), error_(0.0) {}

// Destructor.
FundamentalMatrixRansacModel::~FundamentalMatrixRansacModel() {}

// Return model error.
double FundamentalMatrixRansacModel::Error() const {
  return error_;
}

// Evaluate model on a single data element and update error.
bool FundamentalMatrixRansacModel::IsGoodFit(
    const FeatureMatch& data_point,
    double error_tolerance) const {
  const double error = EvaluateEpipolarCondition(data_point);

  // Test squared error against the provided tolerance.
  if (error * error < error_tolerance) {
    return true;
  }
  return false;
}

double FundamentalMatrixRansacModel::EvaluateEpipolarCondition(
    const FeatureMatch& match) const {
  // Construct vectors for 2D keypoints in match.
  Vector3d kp1, kp2;
  kp1 << match.feature1_.u_, match.feature1_.v_, 1;
  kp2 << match.feature2_.u_, match.feature2_.v_, 1;

  // Compute deviation from the epipolar condition.
  const double epipolar_condition = kp2.transpose() * F_ * kp1;
  return epipolar_condition;
}

// ------------ FundamentalMatrixRansacProblem methods ------------ //

// RansacProblem constructor.
FundamentalMatrixRansacProblem::FundamentalMatrixRansacProblem() {}

// RansacProblem destructor.
FundamentalMatrixRansacProblem::~FundamentalMatrixRansacProblem() {}

// Subsample the data.
std::vector<FeatureMatch> FundamentalMatrixRansacProblem::SampleData(
    unsigned int num_samples) {
  // Randomly shuffle the entire dataset and take the first elements.
  std::random_shuffle(data_.begin(), data_.end());

  // Make sure we don't over step.

  if (static_cast<size_t>(num_samples) > data_.size()) {
    VLOG(1) << "Requested more RANSAC data samples than are available. "
               "Returning all data.";
    num_samples = data_.size();
  }

  // Get samples.
  std::vector<FeatureMatch> samples(
      data_.begin(), data_.begin() + static_cast<size_t>(num_samples));

  return samples;
}

// Return all data that was not sampled.
std::vector<FeatureMatch> FundamentalMatrixRansacProblem::RemainingData(
    unsigned int num_sampled_previously) const {
  // In Sample(), the data was shuffled and we took the first
  // 'num_sampled_previously' elements. Here, take the remaining elements.
  if (num_sampled_previously >= data_.size()) {
    VLOG(1) << "No remaining RANSAC data to sample.";
    return std::vector<FeatureMatch>();
  }

  return std::vector<FeatureMatch>(
      data_.begin() + num_sampled_previously, data_.end());
}

// Fit a model to the provided data using the 8-point algorithm.
FundamentalMatrixRansacModel FundamentalMatrixRansacProblem::FitModel(
    const std::vector<FeatureMatch>& input_data) const {
  // Create an empty fundamental matrix.
  Matrix3d F;

  // Run the 8-point algorithm with default options.
  EightPointAlgorithmSolver solver;
  FundamentalMatrixSolverOptions options;
  solver.SetOptions(options);

  if (solver.ComputeFundamentalMatrix(input_data, F)) {
    // Create a new RansacModel using the computed fundamental matrix.
    FundamentalMatrixRansacModel model_out(F);

    // Record sum of squared error over all matches.
    model_out.error_ = 0.0;
    for (const auto& feature_match : input_data) {
      const double error = model_out.EvaluateEpipolarCondition(feature_match);
      model_out.error_ += error * error;
    }

    return model_out;
  }
  // Set a large error - we didn't find a model that fits the data.
  FundamentalMatrixRansacModel model_out(Matrix3d::Identity());
  model_out.error_ = std::numeric_limits<double>::infinity();
  return model_out;
}

}  //\namespace bsfm
