

#include <vector>


template <typename DataType>
struct RansacModel {
  RansacModel() {}
  virtual ~RansacModel() {}

  // ----- Define these remaining methods in a derived struct! ----- //
  virtual double Error() const = 0;
  virtual bool IsGoodFit(const DataType& data_point,
                         double error_tolerance) const = 0;
};  //\struct RansacModel

// Derive from this class when defining a specific RANSAC problem!
template <typename DataType, typename ModelType>
class RansacProblem {
 public:
  RansacProblem();
  virtual ~RansacProblem() { }

  virtual inline void SetModel(const ModelType& model);
  virtual inline void SetData(
      const std::vector<DataType>& data);
  virtual inline void SetInliers(
      const std::vector<DataType>& inliers);

  virtual inline void SetSolutionFound(bool solution_found);
  virtual inline bool SolutionFound();
  virtual inline const ModelType& Model() const;
  virtual inline const std::vector<DataType>& Inliers() const;

  // ----- Define these remaining methods in a derived class! ----- //
  virtual std::vector<DataType> SampleData(unsigned int num_samples) = 0;
  virtual std::vector<DataType> RemainingData(
      unsigned int num_sampled_previously) const = 0;
  virtual ModelType FitModel(const std::vector<DataType>& input_data) const = 0;

 protected:
  std::vector<DataType> data_;
  std::vector<DataType> inliers_;
  ModelType model_;
  bool solution_found_;

 private:

};  

// -------------------- Implementation -------------------- //

template <typename DataType, typename ModelType>
RansacProblem<DataType, ModelType>::RansacProblem()
    : model_(ModelType()), solution_found_(false) {}

template <typename DataType, typename ModelType>
void RansacProblem<DataType, ModelType>::SetModel(const ModelType& model) {
  model_ = model;
}

template <typename DataType, typename ModelType>
void RansacProblem<DataType, ModelType>::SetData(
    const std::vector<DataType>& data) {
  data_ = data;
}

template <typename DataType, typename ModelType>
void RansacProblem<DataType, ModelType>::SetInliers(
    const std::vector<DataType>& inliers) {
  inliers_ = inliers;
}

template <typename DataType, typename ModelType>
void RansacProblem<DataType, ModelType>::SetSolutionFound(bool solution_found) {
  solution_found_ = solution_found;
}

template <typename DataType, typename ModelType>
bool RansacProblem<DataType, ModelType>::SolutionFound() {
  return solution_found_;
}

template <typename DataType, typename ModelType>
const ModelType& RansacProblem<DataType, ModelType>::Model() const {
  return model_;
}

template <typename DataType, typename ModelType>
const std::vector<DataType>& RansacProblem<DataType, ModelType>::Inliers()
    const {
  return inliers_;
}