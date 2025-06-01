#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

template<typename T>
class Frequency{

    public:
    vector<T>* arr;
    unordered_map<T,int> map;
    Frequency(vector<T>& buf){
        arr = &buf;
    }
    unordered_map<T,int> countFrequency(){
        cout<<"Size of array "<<arr->size()<<"\n";
        for(auto v : *arr){
            if(map.find(v)!=map.end())
            {
                map[v]+=1;
            }
            else{
                map[v] = 1;
            }
        }
        return map;
    }
    
};

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    Frequency<int> f(v);
    unordered_map<int,int> m = f.countFrequency();
    for(auto& num : m){
        cout<< num.first <<" "<<num.second<<" \n";
    }

    vector<string> s;
    s.push_back("somesh");
    s.push_back("somesh");
    s.push_back("mahule");
    s.push_back("mahule");
    Frequency<string> ff(s);
    unordered_map<string,int> smap = ff.countFrequency();
    for(auto& num: smap){
        cout<< num.first << " "<<num.second<<"\n";
    }
}