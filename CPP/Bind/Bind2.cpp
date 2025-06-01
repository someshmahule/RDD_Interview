#include<iostream>
#include<functional>

using namespace std;


class Math{

    public:
    void add(int a,int b){
        cout<<a+b<<"\n";
    }

    void sub(int a,int b){
        cout<<a-b<<"\n";
    }

    void mul(int a, int b){
        cout<<a*b<<"\n";
    }

    void div(int a, int b){
        cout<<a/b<<"\n";
    }
};


int main(){

    Math obj;
    auto a = bind(&Math::add,&obj,2,3);
    a();

    function<void(int,int)> aa = bind(&Math::add, &obj, placeholders::_1, placeholders::_2);
    aa(5,6);
    return 0;
}