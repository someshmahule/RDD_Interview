#include<iostream>
#include<unordered_map>
#include<mutex>
#include<thread>

using namespace std;


 
template<typename T>
class KVS{
    unordered_map<T,T> map;
    mutex mtx;
    public:
    KVS(){
        cout<<"KVS created\n";
    }

    void put(T key, T value){
        scoped_lock lock(mtx);
        map[key] = value;
    }

    T get(T key){
        scoped_lock lock(mtx);
        if(map.find(key)!= map.end()){
            return map[key];
        }
        else{
            return -1;
        }
    }

    void remove(T key){
        scoped_lock lock(mtx);
        map.erase(key);
    }

    void print(){
        cout<<"Print KVS\n";
        for(auto& mm :map){
            scoped_lock lock(mtx);
            cout<<mm.first<<" "<<mm.second << endl;
        }
    }

    ~KVS(){
        cout<<"KVS destroyed\n";
    }
};


int main(){

    KVS<int> obj;
    thread t1(&KVS<int>::print, &obj);
    obj.put(1,1);
    obj.put(2,2);
    cout<<"Get:"<<obj.get(1)<<"\n";
    obj.print();
    t1.join();

}