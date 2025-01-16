#pragma once

#include <ceres/rotation.h>
#include <eigen3/Eigen/Core>
#include <glog/logging.h>

#include "../geometry/point_3d.h"
#include "../matching/feature.h"



  static ceres::CostFunction* Create() {
    static const int kNumResiduals = 9;
    static const int kNumRotationParameters = 9;
    return new ceres::AutoDiffCostFunction<
        SO3Error,
        kNumResiduals,
        kNumRotationParameters>(
            new SO3Error());
  }



#if 0
// Geometric error is the distance in image space between a point x, and a
// projected point PX, where X is a 3D homogeneous point (4x1), P is a camera
// projection matrix (3x4), and x is the corresponding image-space point
// expressed in homogeneous coordinates (3x1). The geometric error can be
// expressed as sum_i d(x_i, PX_i)^2, where d( , ) is the Euclidean distance
// metric.
struct GeometricError {
  // We are trying to adjust our camera projection matrix, P, to satisfy
  // x - PX = 0. Input is a 2D point in image space ('x'), and a 3D point in
  // world space ('X').
  Feature x_;
  Point3D X_;
  GeometricError(const Feature& x, const Point3D& X) : x_(x), X_(X) {}

  // Residual is 2-dimensional, P is 12-dimensional (number of elements in a
  // camera projection matrix).
  template <typename T>
  bool operator()(const T* const P, T* geometric_error) const {

    // Matrix multiplication: x - PX. Assume homogeneous coordinates are 1.0.
    // Matrix P is stored in column-major order.
    T scale = P[2] * X_.X() + P[5] * X_.Y() + P[8] * X_.Z() + P[11];
    geometric_error[0] =
       x_.u_ - (P[0] * X_.X() + P[3] * X_.Y() + P[6] * X_.Z() + P[9]) / scale;
    geometric_error[1] =
       x_.v_ - (P[1] * X_.X() + P[4] * X_.Y() + P[7] * X_.Z() + P[10]) / scale;

    return true;
  }

  // Factory method.
  static ceres::CostFunction* Create(const Feature& x, const Point3D& X) {
    static const int kNumResiduals = 2;
    static const int kNumCameraParameters = 12;
    return new ceres::AutoDiffCostFunction<GeometricError,
           kNumResiduals,
           kNumCameraParameters>(new GeometricError(x, X));
  }
};  //\struct GeometricError

#endif


// Geometric error is defined as the image-space  geometric distance between
// an image point x, and a projected 3D landmark X projected according to
// x = K [R | t] X, where K and [R | t] are camera intrinsic and extrinsic
// parameter matrices, respectively. K is held constant during the optimization,
// and only the camera pose matrix [R | t] is optimized over.
//
// For speed and accuracy, we optimize over an axis-angle parameterization of R
// rather than the 9 variables in a rotation matrix, in addition,
// for readability/cleanliness, we optimize over c, the camera center in world
// space, rather than t. These are related by c = -R'*t.
struct GeometricError {
  // Inputs are the image space point x and the intrinsics matrix K.
  // Optimization variables are just the camera extrinsics matrix [R | t],
  // expressed as an axis-angle rotation and a 3D translation vector, and
  // as the camera origin expressed in world frame coordinates, c.
  Feature x_;
  Point3D X_;
  Matrix3d K_;
  GeometricError(const Feature& x, const Point3D& X, const Matrix3d& K)
    : x_(x), X_(X), K_(K) {}

  template <typename T>
  bool operator()(const T* const rotation, const T* const translation,
                  T* geometric_error) const {
    // Normally one would compute x = K * [R | t] X. Instead we have an
    // axis-angle version of R, and the camera position c. To put the
    // point X in camera frame, we need to compute R*X+t. Note that t = -R'*c,
    // so R*X+t = R*(X+R'*t) = R*(X-c). Hence we can first subtract out the given
    // camera position, and then perform the axis-angle rotation.

    // Remove camera translation.
    T origin_point[3];
    origin_point[0] = X_.X() - translation[0];
    origin_point[1] = X_.Y() - translation[1];
    origin_point[2] = X_.Z() - translation[2];

    // Rotate point to camera frame.
    T cam_point[3];
    ceres::AngleAxisRotatePoint(rotation, origin_point, cam_point);

    // Get normalized pixel projection.
    const T& depth = cam_point[2];
    const T normalized_point[2] = {cam_point[0] / depth, cam_point[1] / depth};

    // Project normalized point into image using intrinsic parameters.
    const T u = K_(0, 0) * normalized_point[0] +
                K_(0, 1) * normalized_point[1] + K_(0, 2);
    const T v = K_(1, 1) * normalized_point[1] + K_(1, 2);

    // Error is computed in image space.
    geometric_error[0] = x_.u_ - u;
    geometric_error[1] = x_.v_ - v;

    return true;
  }

  // Factory method.
  static ceres::CostFunction* Create(const Feature& x, const Point3D& X,
				     const Matrix3d& K) {
    // 2 residuals: image space u and v coordinates.
    static const int kNumResiduals = 2;

    // 3 parameters, axis-angle representation.
    static const int kNumRotationParameters = 3;

    // 3 parameters for camera translation.
    static const int kNumTranslationParameters = 3;

    return new ceres::AutoDiffCostFunction<GeometricError,
           kNumResiduals,
           kNumRotationParameters,
	   kNumTranslationParameters>(new GeometricError(x, X, K));
  }
};  //\GeometricError


// Bundle adjustment error is similar to geometric error, but the position of
// the 3D point is also optimized. The error is defined as the image-space
// geometric distance between an image point x, and a projected 3D landmark X
// projected according to x = K [R | t] X, where K and [R | t] are camera
// intrinsic and extrinsic parameter matrices, respectively. K is held constant
// during the optimization, and only the camera pose matrix [R | t] is optimized
// over.
//
// For speed, we optimize over an axis-angle parameterization of R (3
// varibales), rather than the 9 variables in a rotation matrix, in addition,
// for readability/cleanliness, we optimize over c, the camera center in world
// space, rather than t. These are related by c = -R'*t.
struct BundleAdjustmentError {
  // Inputs are the image space point x and the intrinsics matrix K.
  // Optimization variables are the 3D landmark position X, and the camera
  // extrinsics matrix [R | t], expressed as an axis-angle rotation and a 3D
  // translation vector, and as the camera origin expressed in world frame
  // coordinates, c.
  Feature x_;
  Matrix3d K_;
  BundleAdjustmentError(const Feature& x, const Matrix3d& K) : x_(x), K_(K) {}

  template <typename T>
  bool operator()(const T* const rotation, const T* const translation,
                  const T* const point, T* bundle_adjustment_error) const {
    // Normally one would compute x = K * [R | t] X. Instead we have an
    // axis-angle version of R, and the camera position c. To put the
    // point X in camera frame, we need to compute R*X+t. Note that t = -R'*c,
    // so R*X+t = R*(X+R'*t) = R*(X-c). Hence we can first subtract out the given
    // camera position, and then perform the axis-angle rotation.

    // Remove camera translation.
    T origin_point[3];
    origin_point[0] = point[0] - translation[0];
    origin_point[1] = point[1] - translation[1];
    origin_point[2] = point[2] - translation[2];

    // Rotate point to camera frame.
    T cam_point[3];
    ceres::AngleAxisRotatePoint(rotation, origin_point, cam_point);

    // Get normalized pixel projection.
    const T& depth = cam_point[2];
    const T normalized_point[2] = {cam_point[0] / depth, cam_point[1] / depth};

    // Project normalized point into image using intrinsic parameters.
    const T u = K_(0, 0) * normalized_point[0] +
                K_(0, 1) * normalized_point[1] + K_(0, 2);
    const T v = K_(1, 1) * normalized_point[1] + K_(1, 2);

    // Error is computed in image space.
    bundle_adjustment_error[0] = x_.u_ - u;
    bundle_adjustment_error[1] = x_.v_ - v;

    return true;
  }

  // Factory method.
  static ceres::CostFunction* Create(const Feature& x, const Matrix3d& K) {
    // 2 residuals: image space u and v coordinates.
    static const int kNumResiduals = 2;

    // 3 parameters, axis-angle representation.
    static const int kNumRotationParameters = 3;

    // 3 parameters for camera translation.
    static const int kNumTranslationParameters = 3;

    // 3 landmark position parameters: world space x, y, z.
    static const int kNumLandmarkParameters = 3;

    return new ceres::AutoDiffCostFunction<BundleAdjustmentError,
           kNumResiduals,
           kNumRotationParameters,
           kNumTranslationParameters,
           kNumLandmarkParameters>(new BundleAdjustmentError(x, K));
  }
};  //\BundleAdjustmentError

