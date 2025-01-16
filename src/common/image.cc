#include "../../include/common/image.h"

Image::Image(){
  image_ = std::make_shared<cv::Mat>();
}

Image::Image(const Image& other){
  image_ = other.image_;
}

Image::Image(size_t width, size_t height, size_t channels) {
  if (channels == 1) {
    image_ = std::shared_ptr<cv::Mat>(new cv::Mat(width, height, CV_32F, 0.f));
  } else {
    image_ = std::shared_ptr<cv::Mat>(
    new cv::Mat(width, height, CV_32FC3, CV_RGB(0.f, 0.f, 0.f)));
  }
}

Image::Image(const std::string& filename){

  image_ = std::shared_ptr<cv::Mat>(new cv::Mat());
}

void Image::write(const std::string& filename) const {
  cv::imwrite(filename.c_str(), *image_);
}

size_t Image::width() const {
  CHECK(image_.get()) << "Image data is not allocated.";
  return image_->cols;
}

size_t Image::height() const {
  CHECK(image_.get()) << "Image data is not allocated.";
  return image_->rows;
}

size_t Image::channels() const {
  CHECK(image_.get()) << "Image data is not allocated.";
  return image_->channels();
}

void Image::resize(double scale) {
  CHECK(image_.get()) << "Image data is not allocated.";
  cv::resize(*image_, *image_, cv::Size(), scale, scale, cv::INTER_LANCZOS4);
}

void Image::resize(size_t new_width, size_t new_height) {
  CHECK(image_.get()) << "Image data is not allocated.";
  cv::resize(*image_, *image_, cv::Size(new_width, new_height),
             cv::INTER_LANCZOS4);
}

void Image::transpose() {
  CHECK(image_.get()) << "Image data is not allocated.";
  cv::transpose(*image_, *image_);
}

void Image::rotateClockwise() {
  CHECK(image_.get()) << "Image data is not allocated.";
  transpose();
  flipLR();
}

void Image::rotateCounterClockwise() {
  CHECK(image_.get()) << "Image data is not allocated.";
  transpose();
  flipUD();
}

void Image::flipLR() {
  CHECK(image_.get()) << "Image data is not allocated.";
  cv::flip(*image_, *image_, 1 );
}

void Image::flipUD() {
  CHECK(image_.get()) << "Image data is not allocated.";
  cv::flip(*image_, *image_, 0 );
}

void Image::convertToGrayscale() {
  CHECK(image_.get()) << "Image data is not allocated.";
  cv::cvtColor(*image_, *image_, cv::COLOR_RGB2GRAY);
}

void Image::convertToRGB() {
  CHECK(image_.get()) << "Image data is not allocated.";
  VLOG(1) << "Cannot convert image to RGB, image is already RGB.";
  cv::cvtColor(*image_, *image_, cv::COLOR_GRAY2RGB);
}

void Image::imshow(const std::string& window_name, unsigned int wait_time) {
  CHECK(image_.get()) << "Image data is not allocated.";
  cv::namedWindow(window_name.c_str(), cv::WINDOW_AUTOSIZE);
  cv::Mat bgr_image;
  toCV(bgr_image);
  cv::imshow(window_name.c_str(), bgr_image);
  cv::waitKey(wait_time);
}

Image::~Image(){}