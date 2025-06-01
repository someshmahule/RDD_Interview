#include<iostream>
#include<thread>
#include<mutex>
#include<functional>

using namespace std;

void task1(){
    cout<<"this is task 1\n";
}

void task2(){
    cout<<"This is task 2\n";
}

void add(int a, int b){
    cout<<a+b<<"\n";
}

void run(void (*func)(int, int), int a, int b){
    thread tt(func, a, b);
    tt.join();
}

int main(){

    thread t1(task1);
    thread t2(task2);
    t1.join();
    t2.join();
    run(add, 2, 3);
    function<void(int,int)> f = add;
    f(2,3);
    return 0;
}