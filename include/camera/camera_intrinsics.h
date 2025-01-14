#pragma once 

#include <eigen3/Eigen/Dense>

class CameraIntrinsics {
public:
  CameraIntrinsics();
  CameraIntrinsics(const Eigen::Matrix3d& K, int image_width, int image_height);
  CameraIntrinsics(int image_left, int image_top, int image_width,
                   int image_height, double f_u, double f_v, double c_u,
                   double c_v, double k1, double k2, double k3, double k4,
                   double k5);
  void setImageLeft(int image_left);
  void setImageTop(int image_top);
  void setImageWidth(int image_width);
  void setImageHeight(int image_height);
  void setFU(double f_u);
  void setFV(double f_v);
  void setCU(double c_u);
  void setCV(double c_v);
  void setK(double k1, double k2, double k3, double k4, double k5);
  void setK1(double k1);
  void setK2(double k2);
  void setK3(double k3);
  void setK4(double k4);
  void setK5(double k5);
  void setHorizontalFOV(double horizontal_fov);
  void setVerticalFOV(double vertical_fov);
  
  int imageLeft() const;
  int imageTop() const;
  int imageWidth() const;
  int imageHeight() const;

  double getFU() const;
  double getFV() const;
  double getCU() const;
  double getCV() const;
  double getK1() const;
  double getK2() const;
  double getK3() const;
  double getK4() const;
  double getK5() const;
  double getHorizontalFOV() const;
  double getVerticalFOV() const;

  Eigen::Matrix3d K() const;
  Eigen::Matrix3d Kinv() const;

  bool pointInImage(double u, double v) const;
  bool cameraToImage(double cx, double cy, double cz, double *u_distorted,
                     double *v_distorted) const;
  bool directionToImage(double u_normalized, double v_normalized,
                        double *u_distorted, double *v_distorted) const;
  void imageToDirection(double u_distorted, double v_distorted,
                        double *u_normalized, double *v_normalized) const;
  void distort(double u, double v, double *u_distorted,
               double *v_distorted) const;
  void undistort(double u_distorted, double v_distorted, double *u, double *v,
                 int iterations = 10) const;
private:
  int image_left_;
  int image_top_;
  int image_width_;
  int image_height_;
  double fu, fv;
  double cu, cv;
  double k1, k2, k3, k4, k5;
  double horizontal_fov_;
  double vertical_fov_;
}; 