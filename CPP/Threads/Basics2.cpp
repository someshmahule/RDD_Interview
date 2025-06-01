#include<iostream>
#include<thread>

using namespace std;


void say_hi(){
    cout<<"Hey hi";
}

void add(int a, int b){

    cout<<a+b;
}

int main(){

    thread t1(say_hi);
    t1.join();

    thread t2(add,2,3);
    t2.join();
    return 0;
}