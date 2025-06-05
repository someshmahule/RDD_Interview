#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class LRU{
    public:
    list<int> l;
    unordered_map<int,pair<int,list<int>::iterator>> map;
    int capacity;
    LRU(int c): capacity(c){

    }
    ~LRU(){

    }

    void put(int key, int value){
        if(map.find(key) != map.end()){
            l.erase(map[key].second);
        }
        if(l.size() == capacity){
            int pop= l.back();
            l.pop_back();
            map.erase(pop);
        }
        l.push_front(key);
        map[key] = {value, l.begin()};
    }

    int get(int key){
        if(map.find(key) == map.end()) return -1;

        //else key is present
        l.erase(map[key].second);
        l.push_front(key);
        map[key].second = l.begin();
        return map[key].first;        
    }


};

int main(){

    LRU obj(4);
    obj.put(1,2);
    obj.put(2,2);
    obj.put(3,2);
    obj.put(4,2);
    obj.put(5,3);
    obj.put(6,4);
    cout<<obj.get(1)<<"\n";
    cout<<obj.get(2)<<"\n";
    cout<<obj.get(3)<<"\n";
}