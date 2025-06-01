#include<iostream>
#include<vector>

using namespace std;


void processVector(vector<int>* v){

    auto itr = v->begin();
    while(itr!=v->end()){
        if(*itr % 2 == 1){
            itr = v->erase(itr);
        }
        else {
            *itr*=2;
            itr++;
        }
    }
}

int main(){

    vector<int> vec = {1,2,3,4,5};
    processVector(&vec);
    for(auto v : vec){
        cout<<v<<" ";
    }
}
