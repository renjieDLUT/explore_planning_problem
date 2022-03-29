//
// Created by cidi on 2022/3/29.
//

#ifndef EXPLORE_PLANNING_PROBLEM_KALMAN_H
#define EXPLORE_PLANNING_PROBLEM_KALMAN_H
#include<Eigen/Core>
#include<Eigen/Dense>
using namespace Eigen;

class Kalman {
public:
    Kalman()=delete;
    Kalman(const MatrixXd& A,const MatrixXd& B,const MatrixXd& H,const MatrixXd& Q, const MatrixXd& R);
    void Process(const MatrixXd& input,MatrixXd& output);
private:
    void Predicition(MatrixXd& state_prediction, MatrixXd& p);
    void Correction(const MatrixXd& measure,const MatrixXd & state_prediction, const MatrixXd& p);
    MatrixXd A_, B_, H_, Q_, R_;
    MatrixXd state_, P_, I_;
};

class StateEstimate{
public:
    StateEstimate()=delete;
    static void Init();
    static void Process(const MatrixXd& input,MatrixXd& output );
private:
    static MatrixXd A_, B_, H_, Q_, R_;
    static double  delta_t;
};


#endif //EXPLORE_PLANNING_PROBLEM_KALMAN_H
