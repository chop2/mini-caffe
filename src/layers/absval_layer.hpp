#ifndef CAFFE_ABSVAL_LAYER_HPP_
#define CAFFE_ABSVAL_LAYER_HPP_

#include <vector>

#include "./neuron_layer.hpp"
#include "../proto/caffe.pb.h"

namespace caffe {

/**
 * @brief Computes @f$ y = |x| @f$
 *
 * @param bottom input Blob vector (length 1)
 *   -# @f$ (N \times C \times H \times W) @f$
 *      the inputs @f$ x @f$
 * @param top output Blob vector (length 1)
 *   -# @f$ (N \times C \times H \times W) @f$
 *      the computed outputs @f$ y = |x| @f$
 */
class AbsValLayer : public NeuronLayer {
 public:
  explicit AbsValLayer(const LayerParameter& param)
      : NeuronLayer(param) {}
  virtual void LayerSetUp(const vector<Blob*>& bottom,
      const vector<Blob*>& top);

  virtual inline const char* type() const { return "AbsVal"; }
  virtual inline int ExactNumBottomBlobs() const { return 1; }
  virtual inline int ExactNumTopBlobs() const { return 1; }

 protected:
  /// @copydoc AbsValLayer
  virtual void Forward_cpu(const vector<Blob*>& bottom,
                           const vector<Blob*>& top);
  virtual void Forward_gpu(const vector<Blob*>& bottom,
                           const vector<Blob*>& top);
};

}  // namespace caffe

#endif  // CAFFE_ABSVAL_LAYER_HPP_
