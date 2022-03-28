//
// Created by cidi on 2022/3/27.
//
#include<gtest/gtest.h>
#include"sort.h"

class SortTest: public ::testing::Test{
public:
    virtual  void SetUp() override{
        data=std::move(std::vector<double>{2,1,3,5,4});
        expected_result=std::move(std::vector<double>{1,2,3,4,5});
    }
    virtual  void TearDown(){}

protected:
    std::vector<double> data;
    std::vector<double> expected_result;
};


TEST_F(SortTest,bubble){
    bubble_sort(data);
    ASSERT_EQ(expected_result,data);
}
TEST_F(SortTest, insert){
    insert_sort(data);
    ASSERT_EQ(expected_result,data);
}

TEST_F(SortTest,merge){
    merge_sort(data,0,data.size()-1);
    ASSERT_EQ(expected_result,data);
}

TEST_F(SortTest,heap){
    heap_sort(data);
    ASSERT_EQ(expected_result,data);
}
TEST_F(SortTest,quick){
    quick_sort(data,0,data.size()-1);
    ASSERT_EQ(expected_result,data);
}

int main(int argc,char** argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}