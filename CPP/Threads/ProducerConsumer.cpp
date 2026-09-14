#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>

using namespace std;

mutex mtx;
queue<int> que;
condition_variable cv;
bool finished = false;

void producer(){
 //push

    for(int i =0;i<5;i++){
    {
        lock_guard<mutex> lg(mtx);
        que.push(i);
        cout<<"Produced: "<<i<<"\n";
    }
    cv.notify_one();
    this_thread::sleep_for(chrono::milliseconds(500));
    }
    {
        lock_guard<mutex> lck(mtx);
        finished = true;
    }
    cv.notify_one();
}


void consumer(){
 //pop

    while(true){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[]{ return !que.empty() || finished; });

        while(!que.empty()){
            int val = que.front();
            que.pop();
            cout<<"consumed" << val<<"\n";
        }

        if(finished) break;
    }

}


int main(){

    thread prod(producer);
    thread cons(consumer);

    prod.join();
    cons.join();

}