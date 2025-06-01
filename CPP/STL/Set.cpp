#include<iostream>
#include<set>

using namespace std;


int main(){

    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    for(auto v : s){
        cout<<v<<" ";
    }
    s.erase(1);
    for(auto v:s){
        cout<<v<<" ";
    }
    if(s.find(1)!=s.end()){
        cout<<"found";
    }
}