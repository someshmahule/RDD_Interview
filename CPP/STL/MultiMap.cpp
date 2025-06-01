#include<iostream>
#include<map>

using namespace std;

int main(){

    multimap<string,int> mm;

    mm.insert({"somesh",1});
    mm.insert({"mahule",1});
    mm.insert({"somesh",1});

    for(auto m: mm){
        cout<<m.first<<" "<<m.second<<"\n";
    }
    return 0;
}