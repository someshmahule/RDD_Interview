#include<memory>
#include<iostream>
using namespace std;

class MyClass{
    public:
    MyClass(){ cout<<"Constructor called\n";}
    ~MyClass(){ cout<<"Destructor called\n";}
    void greet() { cout<<"Hello HEllo\n";}
};

int main(){

    unique_ptr<MyClass> ptr = make_unique<MyClass>();
    ptr->greet();

}