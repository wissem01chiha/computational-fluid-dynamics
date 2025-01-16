#pragma once

#include <memory>
#include <flann/flann.h>
#include "../util/types.h"

class DescriptorKDTree {
public:
  DescriptorKDTree();
  void addDescriptor(Descriptor& descriptor);
  void addDescriptors(std::vector<Descriptor>& descriptors);
  bool nearestNeighbor(Descriptor& query, int& nn_index, double& nn_distance);
  ~DescriptorKDTree();
private:
  std::shared_ptr<flann::Index<flann::L2<double>>> index_;
};
