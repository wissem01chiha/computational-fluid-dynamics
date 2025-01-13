

#include <Eigen/Core>

#include "../pose/pose.h"
#include "../util/types.h"


class CameraExtrinsics {
public:
  CameraExtrinsics();
  CameraExtrinsics(const Pose& world_to_camera);

  void setWorldToCamera(const Pose& world_to_camera);
  Pose worldToCamera() const;
  Pose cameraToWorld() const;

  void setRotation(const Matrix3d& rotation);
  void setRotation(double phi, double theta, double psi);
  void Rotate(const Matrix3d& delta);
  void Rotate(double dphi, double dtheta, double dpsi);

  Matrix3d Rotation() const;

  void SetTranslation(const Vector3d& translation);
  void SetTranslation(double wx, double wy, double wz);
  void Translate(const Vector3d& delta);
  void Translate(double dx, double dy, double dz);
  void TranslateX(double dx);
  void TranslateY(double dy);
  void TranslateZ(double dz);
  Vector3d Translation() const;

  /// the extrinsics matrix is 3x4 matrix: [R | t].
  Matrix34d Rt() const;

  /// convert a world frame point into the camera frame.
  void worldToCamera(double wx, double wy, double wz,
                     double* cx, double* cy, double* cz) const;

  // convert a camera frame point into the world frame.
  void cameraToWorld(double cx, double cy, double cz,
                     double* wx, double* wy, double* wz) const;

private:
  Pose world_to_camera_;
}; 
