

#include <eigen3/Eigen/Core>
#include "fundamental_matrix_solver.h"

class EightPointAlgorithmSolver : public FundamentalMatrixSolver {
 public:
  EightPointAlgorithmSolver() { }
  virtual ~EightPointAlgorithmSolver() { }

  virtual bool ComputeFundamentalMatrix(
      const FeatureMatchList& matched_features,
      Matrix3d& fundamental_matrix) const;
 private:

}; 
