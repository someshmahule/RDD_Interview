#include<iostream>
#include<mutex>
#include<thread>
#include<atomic>

using namespace std;

atomic<int> counter = 0;

void task1(){
    for(int i =0;i<1000000;i++){
        counter++;
    }
}

void task2(){

    for(int i=0;i<1000000;i++){
        counter++;
    }
}

int main(){

    thread t1(task1);
    thread t2(task2);
    t1.join();
    t2.join();

    cout<<"final count: "<<counter<<"\n";
    return 0;
}