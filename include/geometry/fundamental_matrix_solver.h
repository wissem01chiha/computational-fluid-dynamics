
#include <eigen3/Eigen/Core>
#include <vector>

#include "fundamental_matrix_solver_options.h"
#include "../matching/pairwise_image_match.h"


class FundamentalMatrixSolver {
 public:
  FundamentalMatrixSolver() {}
  virtual ~FundamentalMatrixSolver() {}

  // Add data from one matched image pair.
  virtual void AddMatchedImagePair(
      const PairwiseImageMatch& matched_image_data);

  // Add data from a set of matched image pairs.
  virtual void AddMatchedImagePairs(
      const PairwiseImageMatchList& matched_image_data);


  virtual void setOptions(const FundamentalMatrixSolverOptions& options);

  // Compute the fundamental matrix for each image pair.
  virtual bool ComputeFundamentalMatrices(
      std::vector<Matrix3d>& fundamental_matrices);

  // Abstract method to compute the fundamental matrix for a single image pair.
  // Override this in the derived solver class to implement it.
  virtual bool ComputeFundamentalMatrix(
      const FeatureMatchList& matched_features,
      Matrix3d& fundamental_matrix) const = 0;

 protected:
  // The matched image data contains a list of matched features for a set of
  // images. The matched features contain (u, v) coordinates in each image. This
  // is a list because we can solve for a bunch of fundamental matrices for a
  // set of independent image matches at once.
  PairwiseImageMatchList matched_image_data_;

  // A set of options used for computing the fundamental matrix.
  FundamentalMatrixSolverOptions options_;

private:


};  