//
// Created by cidi on 2022/3/4.
//
#include"../matplotlib_demo/matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main() {
    std::vector<double> x{1,2,2,1},y{1,1,2,2};
    std::vector<double> x1{1,3,3,1},y1{1,1,1,2};

    plt::fill(x,y,{ });
    plt::fill(x1,y1,{ });

    plt::show();
}
