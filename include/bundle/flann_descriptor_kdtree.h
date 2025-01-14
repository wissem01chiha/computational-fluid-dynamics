
#include <memory.h>
#include <flann/flann.h>


#include "../util/types.h"


class FlannDescriptorKDTree {
 public:
  FlannDescriptorKDTree();
  ~FlannDescriptorKDTree();

  void AddDescriptor(Descriptor& descriptor);
  void AddDescriptors(std::vector<Descriptor>& descriptors);

  // Queries the kd tree for the nearest neighbor of 'query'. Returns whether or
  // not a nearest neighbor was found, and if it was found, the index and
  // distance to the nearest neighbor. Index is based on the order in which
  // descriptors were added with AddDescriptor() and AddDescriptors().
  bool NearestNeighbor(Descriptor& query, int& nn_index, double& nn_distance);

 private:

  std::shared_ptr< flann::Index<flann::L2<double> > > index_;
};
