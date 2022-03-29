//
// Created by cidi on 2022/3/29.
//

#include"kalman.h"
#include<gtest/gtest.h>
#include"util/plot/matplotlibcpp.h"
class StateEstimateTest: public testing::Test{
public:
    virtual void SetUp() override{
        srand((unsigned int)time(0));
        data.resize(100,4);
        for(int i=0;i<data.rows();i++){
            data.row(i)<<0, 0, rand()%10*0.1+1, rand()%10*0.1+1;
        }
    }
    virtual  void TearDown(){}

    void PlotVx(){
        std::vector<double> x, y1, y2;
        for(int i=0;i<result.rows();i++){
            x.push_back(i);
            y1.push_back(result(i,2));
            y2.push_back(data(i,2));
        }
        matplotlibcpp::plot(x,y1,"r--");
        matplotlibcpp::plot(x,y2,"g--");
        matplotlibcpp::show();
    }
protected:
    Eigen::MatrixXd data;
    Eigen::MatrixXd result;
};

TEST_F(StateEstimateTest,normal){
    StateEstimate::Process(data,result);
    PlotVx();
}

int main(){
    StateEstimate::Init();
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}