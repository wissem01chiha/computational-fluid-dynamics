#include "detail/internal_graph.h"

InternalGraph::InternalGraph() {}

InternalGraph::InternalGraph(Model m) {}

InternalGraph::InternalGraph(std::shared_ptr<Model> m) {}

std::vector<std::shared_ptr<Link>> InternalGraph::getRootLinks() {
  return std::vector<std::shared_ptr<Link>>();
}

std::vector<std::shared_ptr<Link>>
InternalGraph::getChildLinks(std::shared_ptr<Link> link) {
  return std::vector<std::shared_ptr<Link>>();
}

std::vector<std::shared_ptr<Link>>
InternalGraph::getParentLinks(std::shared_ptr<Link> link) {
  return std::vector<std::shared_ptr<Link>>();
}
