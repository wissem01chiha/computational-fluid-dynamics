
#include "flann_descriptor_kdtree.h"


FlannDescriptorKDTree::FlannDescriptorKDTree() {}

FlannDescriptorKDTree::~FlannDescriptorKDTree() {
  // Free memory from descriptors in the kd tree.
  if (index_ != nullptr) {
    for (size_t ii = 0; ii < index_->size(); ++ii) {
      double* descriptor = index_->getPoint(ii);
      delete[] descriptor;
    }
  }
}

// Add descriptors to the index.
void FlannDescriptorKDTree::AddDescriptor(Descriptor& descriptor) {

  // Copy the input descriptor into FLANN's Matrix type.
  const size_t cols = descriptor.size();
  flann::Matrix<double> flann_descriptor(new double[cols], 1, cols);
  for (size_t ii = 0; ii < cols; ++ii) {
    flann_descriptor[0][ii] = descriptor(ii);
  }

  // If this is the first point in the index, create the index and exit.
  if (index_ == nullptr) {
    // Single kd-tree. No approximation.
    const int kNumRandomizedKDTrees = 1;
    index_.reset(new flann::Index<flann::L2<double> >(
        flann_descriptor, flann::KDTreeIndexParams(kNumRandomizedKDTrees)));
    index_->buildIndex();
    return;
  }

  // If the index is already created, add the data point to the index. Rebuild
  // every time the index doubles in size to occasionally rebalance the kd tree.
  const int kRebuildThreshold = 2;
  index_->addPoints(flann_descriptor, kRebuildThreshold);
}

// Add descriptors to the index.
void FlannDescriptorKDTree::AddDescriptors(
    std::vector<Descriptor>& descriptors) {
  for (auto& descriptor : descriptors) {
    AddDescriptor(descriptor);
  }
}

// Queries the kd tree for the nearest neighbor of 'query'.
bool FlannDescriptorKDTree::NearestNeighbor(Descriptor& query, int& nn_index,
                                            double& nn_distance) {
  if (index_ == nullptr) {
    VLOG(1) << "Index has not been built. Descriptors must be added before "
               "querying the kd tree";
    return false;
  }

  // Convert the input descriptor to the FLANN format. We can use Eigen's memory
  // here, since we will have our answer before leaving function scope.
  flann::Matrix<double> flann_query(query.data(), 1, index_->veclen());

  // Search the kd tree for the nearest neighbor to the query.
  std::vector< std::vector<int> > query_match_indices;
  std::vector< std::vector<double> > query_distances;

  const int kOneNearestNeighbor = 1;
  int num_neighbors_found = index_->knnSearch(
      flann_query, query_match_indices, query_distances, kOneNearestNeighbor,
      flann::SearchParams(flann::FLANN_CHECKS_UNLIMITED) /* no approx */);

  // If we found a nearest neighbor, assign output.
  if (num_neighbors_found > 0) {
    nn_index = query_match_indices[0][0];
    nn_distance = query_distances[0][0];
  }

  return num_neighbors_found > 0;
}

