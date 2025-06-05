#include<iostream>
#include<mutex>
#include<thread>


using namespace std;

int count = 0;
mutex mtx1;

void task1(){
    
    for(int i=0;i<100000;i++){
        unique_lock<mutex> ulock(mtx1);
        count+=1;
    }
}

void task2(){
    
    for(int i=0;i<100000;i++){
        scoped_lock slock(mtx1);
        count+=1;
    }
}

void task3(){
    
    unique_lock<mutex> ulock(mtx1);
    for(int i=0;i<100000;i++){
        count+=1;
    }
}

void task4(){
    scoped_lock slock(mtx1);
    for(int i=0;i<100000;i++){
        count+=1;
    }
}

int main(){

    auto start = chrono::high_resolution_clock::now();

    /*thread t1(task1); //inside
    thread t2(task2); // inside 
    t1.join();
    t2.join();*/

    thread t1(task3); //outside
    thread t2(task4); // outside 
    t1.join();
    t2.join();

    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> duration = end - start;
    cout<<"Final count "<<count<<"\n";
    cout<<"Final time "<<duration.count()<<"\n";
    return 0;
}