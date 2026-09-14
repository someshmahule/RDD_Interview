#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<shared_mutex>

using namespace std;

template<typename T>
class BoundedBlockQue{
    public:
    BoundedBlockQue<T>(int s) : sz(s){ }
    queue<T> q;
    condition_variable cv_full, cv_empty;
    mutex mtx;
    int sz;

    void dequeue(){
        unique_lock<mutex> lock(mtx);
        cv_full.wait(lock,[this]{ return !q.empty() ;});
        q.pop();
        cout<<"dequed "<<q.size();
        lock.unlock(); 
        cv_empty.notify_one();

    }

    void enqueue(T x){
        unique_lock<mutex> lock(mtx);
        cv_empty.wait(lock,[this]{return q.size() < sz ; });
        q.push(x);
        cout<<"enqued "<<q.size();
        lock.unlock(); 
        cv_full.notify_one();

    }

    int size(){
        unique_lock<mutex> lock(mtx);
        return q.size();
    }
};

int main(){

    BoundedBlockQue<int> bbq(4);
    vector<thread> v;
    for(int i=0;i<10;i++){
        if (i%2 ==0) {
            v.emplace_back([&bbq,i]{
                bbq.enqueue(i);
            });
        }
        else{
            v.emplace_back([&bbq]{
                bbq.dequeue();
            });
        }
    }

    for(auto& vv:v){
        vv.join();
    }

}