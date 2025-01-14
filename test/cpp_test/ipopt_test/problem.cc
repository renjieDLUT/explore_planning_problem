/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-04-16 18:15:23
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-04-17 10:57:05
 * @FilePath: /explore_planning_problem/test/cpp_test/ipopt_test/problem.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "problem.h"
#include <assert.h>
#include <iostream>

bool Problem::get_nlp_info(Index &n, Index &m, Index &nnz_jac_g,
                           Index &nnz_h_lag, IndexStyleEnum &index_style) {
  n = 4;
  m = 2;
  nnz_jac_g = 8;
  nnz_h_lag = 10;
  index_style = TNLP::C_STYLE;

  return true;
}

bool Problem::get_bounds_info(Index n, Number *x_l, Number *x_u, Index m,
                              Number *g_l, Number *g_u) {
  assert(n == 4);
  assert(m == 2);

  for (int i = 0; i < n; ++i) {
    x_l[i] = 1.0;
    x_u[i] = 5.0;
  }

  g_l[0] = 25.0;
  g_u[0] = 2e19;

  g_l[1] = 40.;
  g_u[1] = 40.;

  return true;
}

bool Problem::get_starting_point(Index n, bool init_x, Number *x, bool init_z,
                                 Number *z_L, Number *z_U, Index m,
                                 bool init_lambda, Number *lambda) {
  assert(init_x == true);
  assert(init_z == false);
  assert(init_lambda == false);

  // initialize to the given starting point
  x[0] = 1.0;
  x[1] = 5.0;
  x[2] = 5.0;
  x[3] = 1.0;

  return true;
}

bool Problem::eval_f(Index n, const Number *x, bool new_x, Number &obj_value) {
  assert(n == 4);
  obj_value = x[0] * x[3] * (x[0] + x[1] + x[2]) + x[2];
  return true;
}

bool Problem::eval_grad_f(Index n, const Number *x, bool new_x,
                          Number *grad_f) {
  grad_f[0] = x[3] * (x[0] + x[1] + x[2]) + x[0] * x[3];
  grad_f[1] = x[0] * x[3];
  grad_f[2] = x[0] * x[3] + 1;
  grad_f[3] = x[0] * (x[0] + x[1] + x[2]);
  return true;
}

bool Problem::eval_g(Index n, const Number *x, bool new_x, Index m, Number *g) {

   assert(n == 4);
   assert(m == 2);
  g[0] = x[0] * x[1] * x[2] * x[3];

  g[1] = 0.0;

  for (int i = 0; i < n; ++i) {
    g[1] += (x[i] * x[i]);
  }
  return true;
}

bool Problem::eval_jac_g(Index n, const Number *x, bool new_x, Index m,
                         Index nele_jac, Index *iRow, Index *jCol,
                         Number *values) {
  assert(n == 4);
  assert(m == 2);

  if (values == NULL) {
    // return the structure of the Jacobian

    // this particular Jacobian is dense
    iRow[0] = 0;
    jCol[0] = 0;
    iRow[1] = 0;
    jCol[1] = 1;
    iRow[2] = 0;
    jCol[2] = 2;
    iRow[3] = 0;
    jCol[3] = 3;
    iRow[4] = 1;
    jCol[4] = 0;
    iRow[5] = 1;
    jCol[5] = 1;
    iRow[6] = 1;
    jCol[6] = 2;
    iRow[7] = 1;
    jCol[7] = 3;
  } else {
    // return the values of the Jacobian of the constraints

    values[0] = x[1] * x[2] * x[3]; // 0,0
    values[1] = x[0] * x[2] * x[3]; // 0,1
    values[2] = x[0] * x[1] * x[3]; // 0,2
    values[3] = x[0] * x[1] * x[2]; // 0,3

    values[4] = 2 * x[0]; // 1,0
    values[5] = 2 * x[1]; // 1,1
    values[6] = 2 * x[2]; // 1,2
    values[7] = 2 * x[3]; // 1,3
  }

  return true;
}

bool Problem::eval_h(Index n, const Number *x, bool new_x, Number obj_factor,
                     Index m, const Number *lambda, bool new_lambda,
                     Index nele_hess, Index *iRow, Index *jCol,
                     Number *values) {

  assert(n == 4);
  assert(m == 2);

  if (values == NULL) {
    // return the structure. This is a symmetric matrix, fill the lower left
    // triangle only.

    // the hessian for this problem is actually dense
    Index idx = 0;
    for (Index row = 0; row < 4; row++) {
      for (Index col = 0; col <= row; col++) {
        iRow[idx] = row;
        jCol[idx] = col;
        idx++;
      }
    }

    assert(idx == nele_hess);
  } else {
    // return the values. This is a symmetric matrix, fill the lower left
    // triangle only

    // fill the objective portion
    values[0] = obj_factor * (2 * x[3]); // 0,0

    values[1] = obj_factor * (x[3]); // 1,0
    values[2] = 0.;                  // 1,1

    values[3] = obj_factor * (x[3]); // 2,0
    values[4] = 0.;                  // 2,1
    values[5] = 0.;                  // 2,2

    values[6] = obj_factor * (2 * x[0] + x[1] + x[2]); // 3,0
    values[7] = obj_factor * (x[0]);                   // 3,1
    values[8] = obj_factor * (x[0]);                   // 3,2
    values[9] = 0.;                                    // 3,3

    // add the portion for the first constraint
    values[1] += lambda[0] * (x[2] * x[3]); // 1,0

    values[3] += lambda[0] * (x[1] * x[3]); // 2,0
    values[4] += lambda[0] * (x[0] * x[3]); // 2,1

    values[6] += lambda[0] * (x[1] * x[2]); // 3,0
    values[7] += lambda[0] * (x[0] * x[2]); // 3,1
    values[8] += lambda[0] * (x[0] * x[1]); // 3,2

    // add the portion for the second constraint
    values[0] += lambda[1] * 2; // 0,0

    values[2] += lambda[1] * 2; // 1,1

    values[5] += lambda[1] * 2; // 2,2

    values[9] += lambda[1] * 2; // 3,3
  }

  return true;
}
void Problem::finalize_solution(
   SolverReturn               status,
   Index                      n,
   const Number*              x,
   const Number*              z_L,
   const Number*              z_U,
   Index                      m,
   const Number*              g,
   const Number*              lambda,
   Number                     obj_value,
   const IpoptData*           ip_data,
   IpoptCalculatedQuantities* ip_cq
)
{
   // here is where we would store the solution to variables, or write to a file, etc
   // so we could use the solution.

   // For this example, we write the solution to the console
   std::cout << std::endl << std::endl << "Solution of the primal variables, x" << std::endl;
   for( Index i = 0; i < n; i++ )
   {
      std::cout << "x[" << i << "] = " << x[i] << std::endl;
   }

   std::cout << std::endl << std::endl << "Solution of the bound multipliers, z_L and z_U" << std::endl;
   for( Index i = 0; i < n; i++ )
   {
      std::cout << "z_L[" << i << "] = " << z_L[i] << std::endl;
   }
   for( Index i = 0; i < n; i++ )
   {
      std::cout << "z_U[" << i << "] = " << z_U[i] << std::endl;
   }

   std::cout << std::endl << std::endl << "Objective value" << std::endl;
   std::cout << "f(x*) = " << obj_value << std::endl;

   std::cout << std::endl << "Final value of the constraints:" << std::endl;
   for( Index i = 0; i < m; i++ )
   {
      std::cout << "g(" << i << ") = " << g[i] << std::endl;
   }

     std::cout << std::endl << "Lambda:" << std::endl;
   for( Index i = 0; i < m; i++ )
   {
      std::cout << "Lambda(" << i << ") = " << lambda[i] << std::endl;
   }
}


// [TNLP_intermediate_callback]
// bool Problem::intermediate_callback(
//    AlgorithmMode              mode,
//    Index                      iter,
//    Number                     obj_value,
//    Number                     inf_pr,
//    Number                     inf_du,
//    Number                     mu,
//    Number                     d_norm,
//    Number                     regularization_size,
//    Number                     alpha_du,
//    Number                     alpha_pr,
//    Index                      ls_trials,
//    const IpoptData*           ip_data,
//    IpoptCalculatedQuantities* ip_cq
// )
// {
//    if( !printiterate_ )
//    {
//       return true;
//    }

//    Number x[4];
//    Number x_L_viol[4];
//    Number x_U_viol[4];
//    Number z_L[4];
//    Number z_U[4];
//    Number compl_x_L[4];
//    Number compl_x_U[4];
//    Number grad_lag_x[4];

//    Number g[2];
//    Number lambda[2];
//    Number constraint_violation[2];
//    Number compl_g[2];

//    bool have_iter = get_curr_iterate(ip_data, ip_cq, false, 4, x, z_L, z_U, 2, g, lambda);
//    bool have_viol = get_curr_violations(ip_data, ip_cq, false, 4, x_L_viol, x_U_viol, compl_x_L, compl_x_U, grad_lag_x, 2, constraint_violation, compl_g);

//    printf("Current iterate:\n");
//    printf("  %-12s %-12s %-12s %-12s %-12s %-12s %-12s\n", "x", "z_L", "z_U", "bound_viol", "compl_x_L", "compl_x_U", "grad_lag_x");
//    for( int i = 0; i < 4; ++i )
//    {
//       if( have_iter )
//       {
//          printf("  %-12g %-12g %-12g", x[i], z_L[i], z_U[i]);
//       }
//       else
//       {
//          printf("  %-12s %-12s %-12s", "n/a", "n/a", "n/a");
//       }
//       if( have_viol )
//       {
//          printf(" %-12g %-12g %-12g %-12g\n", x_L_viol[i] > x_U_viol[i] ? x_L_viol[i] : x_U_viol[i], compl_x_L[i], compl_x_U[i], grad_lag_x[i]);
//       }
//       else
//       {
//          printf(" %-12s %-12s %-12s %-12s\n", "n/a", "n/a", "n/a", "n/a");
//       }
//    }

//    printf("  %-12s %-12s %-12s %-12s\n", "g(x)", "lambda", "constr_viol", "compl_g");
//    for( int i = 0; i < 2; ++i )
//    {
//       if( have_iter )
//       {
//          printf("  %-12g %-12g", g[i], lambda[i]);
//       }
//       else
//       {
//          printf("  %-12s %-12s", "n/a", "n/a");
//       }
//       if( have_viol )
//       {
//          printf(" %-12g %-12g\n", constraint_violation[i], compl_g[i]);
//       }
//       else
//       {
//          printf(" %-12s %-12s\n", "n/a", "n/a");
//       }
//    }

//    return true;
// }
// [TNLP_intermediate_callback]
