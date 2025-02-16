#include "detail/internal_graph.h"
#ifdef USE_OPENMP
  #include <omp.h>
#endif 

InternalGraph::InternalGraph() {}

InternalGraph::InternalGraph(Model m) {

  this->m_ = std::make_shared<Model>(m);
}

InternalGraph::InternalGraph(std::shared_ptr<Model> m) {

  if(m){
    this->m_ = m;
  }
}

std::vector<std::shared_ptr<Link>> InternalGraph::getRootLinks() {
  return std::vector<std::shared_ptr<Link>>();
}

std::vector<std::shared_ptr<Link>>
InternalGraph::getChildLinks(std::shared_ptr<Link> link) {

  std::vector<std::shared_ptr<Link>> clks;
  // loop over all model joints 
  // check if the link if a parent of tha jonit if so 
  // all joint childs append them (tradionall there once )
  return clks;

}

std::vector<std::shared_ptr<Link>>
InternalGraph::getParentLinks(std::shared_ptr<Link> link) {

  std::vector<std::shared_ptr<Link>> plks;
  // same logic as previous 

  return plks;
}
