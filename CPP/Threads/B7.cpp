#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

mutex mtx;

void printTryLock(int id){

    unique_lock<mutex> lock(mtx,try_to_lock);
    
    if(lock.owns_lock()){
        cout<<"Lock Acquired "<<id<<"\n";
    }
    else{
        cout<<"Couldnt acquire lock "<<id<<"\n";
    }
}


int main(){

    mtx.lock();
    thread t1(printTryLock,1);
    thread t2(printTryLock,2);
    //this_thread::sleep_for(chrono::seconds(1));
    mtx.unlock();
    t1.join();
    t2.join();
    return 0;
}