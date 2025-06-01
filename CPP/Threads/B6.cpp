#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

mutex mtx;

void printWithLock(){

    unique_lock<mutex> lock(mtx);
    cout<<"Lock acquired\n";

    lock.unlock();

    cout<<"Lock unlocked\n";

    this_thread::sleep_for(chrono::seconds(1));
    lock.lock();
    cout<<"Relocked\n";

}

int main(){

    thread t1(printWithLock);
    thread t2(printWithLock);

    t1.join();
    t2.join();

    return 0;

}