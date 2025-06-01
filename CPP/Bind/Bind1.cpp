#include<iostream>
#include <functional>


using namespace std;


void add(int a, int b){

    cout<<a;
    cout<<a+b<<"\n";
}

int main(){

    auto call_add = std::bind(add,2,2);
    call_add();
    auto add_2 = std::bind(add,placeholders::_1,5);
    add_2(3);
    return 0;
}