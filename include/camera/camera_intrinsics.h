

#pragma once 

#include <Eigen/Dense>

using Eigen::Matrix3d;
using Eigen::Vector3d;

class CameraIntrinsics {
public:
  CameraIntrinsics();
  CameraIntrinsics(const Matrix3d& K, int image_width, int image_height);
  CameraIntrinsics(int image_left, int image_top, int image_width,
                   int image_height, double f_u, double f_v, double c_u,
                   double c_v, double k1, double k2, double k3, double k4,
                   double k5);
  void SetImageLeft(int image_left);
  void SetImageTop(int image_top);
  void SetImageWidth(int image_width);
  void SetImageHeight(int image_height);
  void SetFU(double f_u);
  void SetFV(double f_v);
  void SetCU(double c_u);
  void SetCV(double c_v);
  void SetK(double k1, double k2, double k3, double k4, double k5);
  void SetK1(double k1);
  void SetK2(double k2);
  void SetK3(double k3);
  void SetK4(double k4);
  void SetK5(double k5);
  void SetHorizontalFOV(double horizontal_fov);
  void SetVerticalFOV(double vertical_fov);
  int ImageLeft() const;
  int ImageTop() const;
  int ImageWidth() const;
  int ImageHeight() const;
  double f_u() const;
  double f_v() const;
  double c_u() const;
  double c_v() const;
  double k1() const;
  double k2() const;
  double k3() const;
  double k4() const;
  double k5() const;
  double HorizontalFOV() const;
  double VerticalFOV() const;

  Matrix3d K() const;
  Matrix3d Kinv() const;

  bool PointInImage(double u, double v) const;
  bool CameraToImage(double cx, double cy, double cz, double *u_distorted,
                     double *v_distorted) const;
  bool DirectionToImage(double u_normalized, double v_normalized,
                        double *u_distorted, double *v_distorted) const;
  void ImageToDirection(double u_distorted, double v_distorted,
                        double *u_normalized, double *v_normalized) const;
  void Distort(double u, double v, double *u_distorted,
               double *v_distorted) const;
  void Undistort(double u_distorted, double v_distorted, double *u, double *v,
                 int iterations = 10) const;

private:
  int image_left_;
  int image_top_;
  int image_width_;
  int image_height_;
  double f_u_;
  double f_v_;
  double c_u_;
  double c_v_;
  double k1_;
  double k2_;
  double k3_;
  double k4_;
  double k5_;
  double horizontal_fov_;
  double vertical_fov_;
}; 
#endif
