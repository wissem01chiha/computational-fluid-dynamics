

#include <Eigen/Core>
#include "../common/camera_intrinsics.h"
#include "../geometry/pose.h"

class EssentialMatrixSolver {
public:
  EssentialMatrixSolver() {}
  ~EssentialMatrixSolver() {}

  // Compute the essential matrix from a fundamental matrix and camera intrinsics.
  Matrix3d ComputeEssentialMatrix(const Matrix3d& F,
                                  const CameraIntrinsics& intrinsics1,
                                  const CameraIntrinsics& intrinsics2);

  // Compute relative transformation between two cameras from an essential
  // matrix and a list of keypoint matches. Note that the translation of the
  // output relative transformation can only be computed up to a scale factor.
  bool ComputeExtrinsics(const Matrix3d& E,
                         const FeatureMatchList& matches,
                         const CameraIntrinsics& intrinsics1,
                         const CameraIntrinsics& intrinsics2,
                         Pose& relative_pose);

private:
}; 
