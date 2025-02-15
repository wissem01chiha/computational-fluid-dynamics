#ifndef INCLUDE_TINYURDF_DETAIL_INTERNAL_GRAPH_H_
#define INCLUDE_TINYURDF_DETAIL_INTERNAL_GRAPH_H_

#include "core/model.h"

class InternalGraph {
 public:
  InternalGraph();
  InternalGraph(Model m);
  InternalGraph(std::shared_ptr<Model> m);
  std::vector<std::shared_ptr<Link>> getRootLinks();
  std::vector<std::shared_ptr<Link>> getChildLinks(std::shared_ptr<Link> link);
  std::vector<std::shared_ptr<Link>> getParentLinks(std::shared_ptr<Link> link);
 private:
 std::shared_ptr<Model> m_;
};
#endif // INCLUDE_TINYURDF_DETAIL_INTERNAL_GRAPH_H_