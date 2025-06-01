#include<iostream>
#include<map>

using namespace std;


int main(){

    map<string,int> m;
    m["somesh"] = 1;
    m["mahule"] = 1;

    m.erase("somesh");
    for(auto p : m){
        cout<<p.first<<" "<<p.second<<"\n";
    }
    
}