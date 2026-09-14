#include<iostream>
#include<thread>
#include<shared_mutex>
#include<unordered_map>
#include<mutex>
#include<vector>

using namespace std;

template<typename X,typename Y>
class ThreadSafeCache{

    public:
    shared_mutex smtx;
    unordered_map<X, Y> umap;
    void getX(X k){
        shared_lock<shared_mutex> slock(smtx);
        if (umap.find(k) != umap.end())
            cout<< "k: "<<k<<"v: "<<umap[k] << "\n";
        else{
            cout<<"k:"<<-1<<"\n";
        }
    }

    void insert(X k,Y v){

        unique_lock<shared_mutex> ulock(smtx);
        umap.insert({k, v});

    }
};


int main(){

    ThreadSafeCache<int,int> tsc;
    vector<thread> vec;
    for(int i=0;i<10;i++){
        if (i%2 ==0 ) {
            vec.emplace_back([&tsc,i]{
                tsc.insert(i,i+100);
            });
        }
        else{
            vec.emplace_back([&tsc,i]{
                tsc.getX(i-1);
            });
        } 
    }
    for (auto& t : vec) {
        t.join();
    }
    return 0;
}