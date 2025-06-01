#include<iostream>
#include<vector>

using namespace std;


class Animal{
    public:
    Animal(){cout<<"Animal created\n";}
    virtual ~Animal() {cout<<"Animal Destroyed\n";}
    virtual void speak(){
        cout<<"Animal Speak\n";
    }
};


class Cat : public Animal{
    public:
    Cat(){cout<<"Cat created\n";}
    ~Cat() {cout<<"Cat destroyed\n";}
    virtual void speak () override {
        cout<<"Cat Meows\n";
    }
};

class Dog: public Animal{

    public:
    Dog(){cout<<"Dog Created\n";}
    ~Dog(){cout<<"Dog Destroyed\n";}
    virtual void speak() override{
        cout<<"Dog barks\n";
    }
};

int main(){

    vector<Animal*> vec;
    vec.push_back(new Cat());
    vec.push_back(new Dog());

    for (auto itr = vec.begin();itr!=vec.end();++itr){
        (*itr)->speak();
    }

    for (auto ptr : vec) {
        delete ptr;
    }
}