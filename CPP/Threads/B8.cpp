#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

mutex mtx1, mtx2;

void task1(){
    unique_lock<mutex> l1(mtx1);
    cout<<"t1 locked l1";
    unique_lock<mutex> l2(mtx2);
}

void task2(){
    unique_lock<mutex> l1(mtx2);
    cout<<"t1 locked l1";
    unique_lock<mutex> l2(mtx1);
}

int main(){

    thread t1(task1);
    thread t2(task2);

    t1.join();
    t2.join();
    return 0;
}
