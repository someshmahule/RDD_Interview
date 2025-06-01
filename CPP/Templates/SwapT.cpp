#include<iostream>

using namespace std;

template<typename T>
void swapValues(T* a, T* b){
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){

    int a = 2;
    int b = 3;
    swapValues(&a,&b);
    cout<<a <<" "<<b<<"\n";

    string aa = "Hi";
    string bb = "Hola";
    swapValues(&aa,&bb);
    cout<<aa <<" "<<bb;
    return 0;
}