#include<iostream>
#include<mutex>
#include<thread>
#include<queue>

using namespace std;

class ThreadSafeQ{

    public:
    queue<int> q;
    mutex mtx;
    void push(int val){
        lock_guard<mutex> lock(mtx);
        q.push(val);
        cout<<"pushed "<<val<<"\n";
    }

    bool pop(int& res){
        lock_guard<mutex> lock(mtx);
        if(q.empty()) return false;
        res = q.front();
        q.pop();
        
        return true;
    }

};

ThreadSafeQ* q;

void producer(){
    for(int i=0;i<10;i++){
        q->push(i);
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void consumer(){
    int val;
    for(int i=0;i<10;i++){
        while(!q->pop(val)){
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        cout<<"pop "<<val<<"\n";
    }

}


int main(){

    q = new ThreadSafeQ();

    thread prod(producer);
    thread cons(consumer);

    prod.join();
    cons.join();

}