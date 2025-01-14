#include "IpTNLP.hpp"

using namespace Ipopt;

class Problem : public ::TNLP {

public:
  Problem() = default;
  virtual ~Problem() = default;

  bool get_nlp_info(Index &n, Index &m, Index &nnz_jac_g, Index &nnz_h_lag,
                    IndexStyleEnum &index_style) override;

  bool get_bounds_info(Index n, Number *x_l, Number *x_u, Index m, Number *g_l,
                       Number *g_u) override;

  bool get_starting_point(Index n, bool init_x, Number *x, bool init_z,
                          Number *z_L, Number *z_U, Index m, bool init_lambda,
                          Number *lambda) override;
  bool eval_f(Index n, const Number *x, bool new_x, Number &obj_value) override;

  bool eval_grad_f(Index n, const Number *x, bool new_x,
                   Number *grad_f) override;

  bool eval_g(Index n, const Number *x, bool new_x, Index m,
              Number *g) override;

  bool eval_jac_g(Index n, const Number *x, bool new_x, Index m, Index nele_jac,
                  Index *iRow, Index *jCol, Number *values) override;
  bool eval_h(Index n, const Number *x, bool new_x, Number obj_factor, Index m,
              const Number *lambda, bool new_lambda, Index nele_hess,
              Index *iRow, Index *jCol, Number *values) override;
  void finalize_solution(SolverReturn status, Index n, const Number *x,
                         const Number *z_L, const Number *z_U, Index m,
                         const Number *g, const Number *lambda,
                         Number obj_value, const IpoptData *ip_data,
                         IpoptCalculatedQuantities *ip_cq) override;

  bool intermediate_callback(AlgorithmMode mode, Index iter, Number obj_value,
                             Number inf_pr, Number inf_du, Number mu,
                             Number d_norm, Number regularization_size,
                             Number alpha_du, Number alpha_pr, Index ls_trials,
                             const IpoptData *ip_data,
                             IpoptCalculatedQuantities *ip_cq) {
    return true;
  }
};

