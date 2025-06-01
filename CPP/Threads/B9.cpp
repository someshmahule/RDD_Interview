#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

mutex mtx1, mtx2;

void task1(){
    scoped_lock lock(mtx1,mtx2);
    cout<<"t1 locked both\n";
}

void task2(){
    scoped_lock lock(mtx1,mtx2);
    cout<<"t2 locked both\n";
}

int main(){

    thread t1(task1);
    thread t2(task2);

    t1.join();
    t2.join();
    return 0;
}
