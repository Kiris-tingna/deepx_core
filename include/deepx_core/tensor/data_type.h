// Copyright 2019 the deepx authors.
// Author: Yafei Zhang (kimmyzhang@tencent.com)
//

#pragma once
#include <deepx_core/tensor/csr_matrix.h>
#include <deepx_core/tensor/ll_math.h>
#include <deepx_core/tensor/ll_tensor.h>
#include <deepx_core/tensor/sparse_row_grad.h>
#include <deepx_core/tensor/sparse_row_matrix.h>
#include <deepx_core/tensor/sparse_row_param.h>
#include <deepx_core/tensor/sparse_vector_grad.h>
#include <deepx_core/tensor/sparse_vector_param.h>
#include <deepx_core/tensor/tensor.h>
#include <cstdint>
#include <string>

namespace deepx_core {

/************************************************************************/
/* DataTypeT */
/************************************************************************/
template <typename T, typename I, int TOKEN>
class DataTypeT {
 public:
  using float_t = T;
  using int_t = I;
  using tsr_t = Tensor<float_t>;
  using srm_t = SparseRowMatrix<float_t, int_t>;
  using csr_t = CSRMatrix<float_t, int_t>;
  using tsri_t = Tensor<int_t>;
  using tsrs_t = Tensor<std::string>;
  using srp_t = SparseRowParam<float_t, int_t>;
  using svp_t = SparseVectorParam<float_t, int_t>;
  using srg_t = SparseRowGrad<float_t, int_t>;
  using svg_t = SparseVectorGrad<float_t, int_t>;
  using ll_math_t = LLMath<float_t>;
  using ll_tensor_t = LLTensor<float_t>;
  using ll_sparse_tensor_t = LLSparseTensor<float_t, int_t>;
  using ll_optimizer_t = LLOptimizer<float_t, int_t>;
  static constexpr int DATA_TYPE_TOKEN = TOKEN;
};

template <typename T, typename I, int TOKEN>
constexpr int DataTypeT<T, I, TOKEN>::DATA_TYPE_TOKEN;

using DataTypeS = DataTypeT<float, uint64_t, 1>;
using DataTypeD = DataTypeT<double, uint64_t, 2>;
#if HAVE_FLOAT64 == 1
using DataType = DataTypeD;
#else
using DataType = DataTypeS;
#endif

}  // namespace deepx_core