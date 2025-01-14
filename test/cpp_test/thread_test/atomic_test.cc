#include<atomic>
#include<iostream>
class Foo{
    int mAarry[123];
};

class Bar{
    int mInt;
};

int main(){
    std::atomic<Foo> f;
    std::cout<<std::is_trivially_copyable_v<Foo> <<std::endl;

    std::atomic<Bar> b;
    std::cout<<std::is_trivially_copyable_v<Bar> <<" "<<b.is_lock_free()<<std::endl;

}