#pragma once

#include <lamtram/softmax-base.h>
#include <cnn/model.h>

namespace cnn {
  class ClassFactoredSoftmaxBuilder;
}

namespace lamtram {


// An interface to a class that takes a vector as input
// (potentially batched) and calculates a probability distribution
// over words
class SoftmaxClass : public SoftmaxBase {

public:
  SoftmaxClass(const std::string & sig, int input_size, const DictPtr & vocab, cnn::Model & mod);
  ~SoftmaxClass() { };

  // Create a new graph
  virtual void NewGraph(cnn::ComputationGraph & cg) override;

  // Calculate training loss for one word
  virtual cnn::expr::Expression CalcLoss(cnn::expr::Expression & in, cnn::expr::Expression & prior, const Sentence & ngram, bool train) override;
  // Calculate training loss for multiple words
  virtual cnn::expr::Expression CalcLoss(cnn::expr::Expression & in, cnn::expr::Expression & prior, const std::vector<Sentence> & ngrams, bool train) override;
  
  // Calculate the full probability distribution
  virtual cnn::expr::Expression CalcProb(cnn::expr::Expression & in, cnn::expr::Expression & prior, const Sentence & ctxt, bool train) override;
  virtual cnn::expr::Expression CalcProb(cnn::expr::Expression & in, cnn::expr::Expression & prior, const std::vector<Sentence> & ctxt, bool train) override;
  virtual cnn::expr::Expression CalcLogProb(cnn::expr::Expression & in, cnn::expr::Expression & prior, const Sentence & ctxt, bool train) override;
  virtual cnn::expr::Expression CalcLogProb(cnn::expr::Expression & in, cnn::expr::Expression & prior, const std::vector<Sentence> & ctxt, bool train) override;

protected:
  std::shared_ptr<cnn::ClassFactoredSoftmaxBuilder> cfsm_builder_;

};

}
