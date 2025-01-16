
#include "pnp_ransac_problem.h"
#include <camera/camera_extrinsics.h>
#include <camera/camera_intrinsics.h>
#include <camera/camera.h>
#include <geometry/pose_estimator_2d3d.h>
#include <geometry/reprojection_error.h>



// ------------ PnPRansacModel methods ------------ //

// Default constructor. Initialize to empty matches and default camera.
// Note: this should really never be used -- instead use the constructor below.
PnPRansacModel::PnPRansacModel()
  : camera_(Camera()),
    matches_(std::vector<Observation::Ptr>()),
    error_(0.0) {}

// Constructor. Set parameters as given.
// Use this constructor instead of the default.
PnPRansacModel::PnPRansacModel(const Camera& camera,
			       const std::vector<Observation::Ptr>& matches)
  : camera_(camera),
    matches_(matches),
    error_(0.0) {}

// Destructor.
PnPRansacModel::~PnPRansacModel() {}

// Return model error.
double PnPRansacModel::Error() const {
  // Evaluate reprojection error over all observations.
  return ReprojectionError(matches_, camera_);
}

// Evaluate model on a single data element and update error.
bool PnPRansacModel::IsGoodFit(const Observation::Ptr& observation,
                               double error_tolerance) const {
  return ReprojectionError(observation, camera_) <= error_tolerance;
}

// ------------ PnPRansacProblem methods ------------ //

// Default constructor/destructor.
PnPRansacProblem::PnPRansacProblem() {}
PnPRansacProblem::~PnPRansacProblem() {}

// Set camera intrinsics.
void PnPRansacProblem::SetIntrinsics(CameraIntrinsics& intrinsics) {
  intrinsics_ = intrinsics;
}

// Subsample the data.
std::vector<Observation::Ptr> PnPRansacProblem::SampleData(
   unsigned int num_samples) {

  // Randomly shuffle the entire dataset and take the first elements.
  std::random_shuffle(data_.begin(), data_.end());

  // Make sure we don't over step.
  if (static_cast<size_t>(num_samples) > data_.size()) {
    VLOG(1) << "Requested more RANSAC data samples than are available. "
	    << "Returning all data.";
    num_samples = data_.size();
  }

  // Get samples.
  std::vector<Observation::Ptr> samples(
    data_.begin(), data_.begin() + static_cast<size_t>(num_samples));

  return samples;
}

// Return the data that was not sampled.
std::vector<Observation::Ptr> PnPRansacProblem::RemainingData(
    unsigned int num_sampled_previously) const {
  // In Sample(), the data was shuffled and we took the first
  // 'num_sampled_previously' elements. Here, take the remaining elements.
  if (num_sampled_previously >= data_.size()) {
    VLOG(1) << "No remaining RANSAC data to sample.";
    return std::vector<Observation::Ptr>();
  }

  return std::vector<Observation::Ptr>(
    data_.begin() + num_sampled_previously, data_.end());
}

// Fit a model to the provided data using PoseEstimatorPnP.
PnPRansacModel PnPRansacProblem::FitModel(
    const std::vector<Observation::Ptr>& input_data) const {

  // Extract a FeatureList and a Point3DList from input_data.
  FeatureList points_2d;
  Point3DList points_3d;
  points_2d.reserve(input_data.size());
  points_3d.reserve(input_data.size());

  for (const auto& observation : input_data) {
    CHECK_NOTNULL(observation.get());

    // Extract feature and append.
    points_2d.push_back(observation->Feature());

    // Extract landmark position and append.
    Landmark::Ptr landmark = observation->GetLandmark();
    CHECK_NOTNULL(landmark.get());
    points_3d.push_back(landmark->Position());
  }

  // Set up solver.
  PoseEstimator2D3D solver;
  solver.Initialize(points_2d, points_3d, intrinsics_);

  // Solve.
  Pose calculated_pose;
  if (!solver.Solve(calculated_pose)) {
    VLOG(1) << "Could not estimate a pose using the PnP solver. "
	    << "Assuming identity pose.";
  }

  // Generate a model from this Pose.
  CameraExtrinsics extrinsics(calculated_pose);
  Camera camera(extrinsics, intrinsics_);

  PnPRansacModel model(camera, input_data);
  return model;
}

