#pragma once

#include <memory>
#include "feature.h"

struct FeatureMatch {
  typedef std::shared_ptr<FeatureMatch> Ptr;
  typedef std::shared_ptr<const FeatureMatch> ConstPtr;

  FeatureMatch(){};

  FeatureMatch(const Feature& feature1, const Feature& feature2)
      :feature1_(feature1), feature2_(feature2) {}

  Feature feature1_;
  Feature feature2_;

}; 

struct LightFeatureMatch {

  LightFeatureMatch(int feature_index1, int feature_index2, double distance)
      : feature_index1_(feature_index1),
        feature_index2_(feature_index2),
        distance_(distance) {}

  double distance_;
  int feature_index1_;
  int feature_index2_;

  static bool SortByDistance(const LightFeatureMatch& lhs,
                             const LightFeatureMatch& rhs) {
    return lhs.distance_ < rhs.distance_;
  }
};  

