#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <stack>
#include <vector>
#include <queue>
#include <list>
#include <thread>
#include <mutex>

struct Value{
    Value(int x){
        this->x = x;
    }
    int x = 0;

    ~Value(){
        std::cout<<"deleted x"<<x;
    }
};

thread_local Value x {42};


void foo(){
    std::cout<<"foo()";
    x.x =30;
    
}

int main(){
    foo();
    std::thread w1(foo);
    std::thread w2(foo);
    w1.join();
    w2.join();
    return 0;
}