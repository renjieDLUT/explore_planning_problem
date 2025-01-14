/*
 * @Author: renjie renjie_dlut2016@163.com
 * @Date: 2024-04-16 19:12:02
 * @LastEditors: renjie renjie_dlut2016@163.com
 * @LastEditTime: 2024-04-17 10:56:30
 * @FilePath: /explore_planning_problem/test/cpp_test/ipopt_test/main.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "IpIpoptApplication.hpp"
#include "problem.h"

int main() {
//   SmartPtr<Problem> problem(new Problem());
//   SmartPtr<IpoptApplication> app = IpoptApplicationFactory();

//   app->Options()->SetNumericValue("tol", 3.82e-6);
//   app->Options()->SetStringValue("mu_strategy", "adaptive");
//   app->Options()->SetStringValue("output_file", "ipopt.out");

//   ApplicationReturnStatus status;
//   status = app->Initialize();
//   status = app->OptimizeTNLP(problem);
//   if (status == Solve_Succeeded) {
//     std::cout << std::endl
//               << std::endl
//               << "*** The problem solved!" << std::endl;
//   } else {
//     std::cout << std::endl << "*** The problem FAILED!" << std::endl;
//   }

  // Create a new instance of your nlp
  //  (use a SmartPtr, not raw)
  SmartPtr<TNLP> mynlp = new Problem();

  // Create a new instance of IpoptApplication
  //  (use a SmartPtr, not raw)
  // We are using the factory, since this allows us to compile this
  // example with an Ipopt Windows DLL
  SmartPtr<IpoptApplication> app = IpoptApplicationFactory();

  // Change some options
  // Note: The following choices are only examples, they might not be
  //       suitable for your optimization problem.
  app->Options()->SetNumericValue("tol", 3.82e-6);
  app->Options()->SetStringValue("mu_strategy", "adaptive");
  app->Options()->SetStringValue("output_file", "ipopt.out");
  app->Options()->SetStringValue("derivative_test", "first-order");
  app->Options()->SetStringValue("hessian_approximation", "limited-memory");
  // app->Options()->SetStringValue("warm_start_init_point", "yes");
  // The following overwrites the default name (ipopt.opt) of the options file
  // app->Options()->SetStringValue("option_file_name", "hs071.opt");

  // Initialize the IpoptApplication and process the options
  ApplicationReturnStatus status;
  status = app->Initialize();
  if (status != Solve_Succeeded) {
    std::cout << std::endl
              << std::endl
              << "*** Error during initialization!" << std::endl;
    return (int)status;
  }

  // Ask Ipopt to solve the problem
  status = app->OptimizeTNLP(mynlp);

  if (status == Solve_Succeeded) {
    std::cout << std::endl
              << std::endl
              << "*** The problem solved!" << std::endl;
  } else {
    std::cout << std::endl
              << std::endl
              << "*** The problem FAILED!" << std::endl;
  }

  // As the SmartPtrs go out of scope, the reference count
  // will be decremented and the objects will automatically
  // be deleted.

  return (int)status;
}