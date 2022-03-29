//
// Created by cidi on 2022/3/29.
//

#include "kalman.h"
#include<iostream>

Kalman::Kalman(const MatrixXd& A,const MatrixXd& B,const MatrixXd& H,const MatrixXd& Q, const MatrixXd& R):A_(A),B_(B),H_(H),Q_(Q),R_(R){
    if(A_.rows()!=B_.rows()) throw "error: A_.rows()!=B_.rows()";
    if(A_.rows()!=A_.cols()) throw "error:A_.rows()!=A_.cols()";
    if(B_.cols()!=1) throw "error: B_.cols()!=1";
    if(H_.cols()!=A.rows()) throw "error: H_.cols()!=A.rows()";
    if(Q_.rows()!=Q_.rows()) throw "error: Q_.rows()!=Q_.rows()";
    if(Q_.rows()!=A_.rows()) throw "error: Q_.rows()!=A_.rows()";
    if(R_.rows()!=R_.rows()) throw "error: R_.rows()!=R_.rows()";
    if(R_.rows()!=H_.rows()) throw "error: R_.rows()!=H_.rows()";

    state_.resize(A_.rows(),1);
    P_.resize(A.rows(),A.cols());
    P_.setIdentity();
    I_=P_;
}

void Kalman::Process(const MatrixXd& input,MatrixXd& output){

    output.resize(input.rows(),input.cols());
    output.row(0)=input.row(0);
    state_=input.row(0).transpose();
    MatrixXd state_prediction=state_;
    MatrixXd p=P_;
    MatrixXd measure=state_;
    for(int i=0;i<input.rows()-1;i++){
        Predicition(state_prediction,p);
        measure=input.row(i+1).transpose();
        MatrixXd m=measure.block(2,0,2,1);
        Correction(m,state_prediction,p);
        output.row(i+1)=state_.transpose();
    }
}

void Kalman::Predicition(MatrixXd& state_prediction, MatrixXd& p){
    state_prediction=A_*state_;
    p=A_*P_*A_.transpose()+Q_;
}

void Kalman::Correction(const MatrixXd& measure,const MatrixXd & state_prediction, const MatrixXd& p){

    MatrixXd denominator=H_*p*H_.transpose()+R_;
    MatrixXd numerator = p*H_.transpose();
    MatrixXd K=p*H_.transpose()*denominator.inverse();

    state_=state_prediction+K*(measure-H_*state_prediction);
    P_=(I_-K*H_)*p;
}
double StateEstimate::delta_t =0.5;
MatrixXd StateEstimate::A_;
MatrixXd StateEstimate::B_;
MatrixXd StateEstimate::H_;
MatrixXd StateEstimate::Q_;
MatrixXd StateEstimate::R_;

void StateEstimate::Init() {
    A_.resize(4,4);
    A_<<1, 0, delta_t, 0,
        0, 1,       0, delta_t,
        0, 0,       1, 0,
        0, 0,       0, 1;
    B_=MatrixXd::Ones(4,1);
    H_.resize(2,4);
    H_<<0, 0, 1, 0,
        0, 0, 0, 1;
    Q_.resize(2,2);
    auto g=Matrix<double,4,1>();
    g<<0.5*pow(delta_t,2), 0.5*pow(delta_t,2), delta_t, delta_t;
    Q_=g*g.transpose()*0.5;
    R_.resize(2,2);
    R_<<100, 0,
        0, 100;
}

void StateEstimate::Process(const MatrixXd& input,MatrixXd& output){
    Kalman kalman(A_, B_, H_, Q_, R_);
    kalman.Process(input,output);
}



