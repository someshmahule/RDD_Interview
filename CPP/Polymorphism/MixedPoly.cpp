#include<iostream>

using namespace std;


class MathOp{

    public:
    MathOp(){}
    virtual ~MathOp(){}
    virtual double compute(double a, double b){}
};

class AddOp : public MathOp{
    public:
    AddOp(){}
    ~AddOp(){}
    double compute(double a, double b) override {
        cout<<a+b<<"\n";
    }
    double compute(int a){
        cout<<a*a<<"\n";
    }

};

class MultiplyOp : public MathOp{
    public:
    MultiplyOp(){}
    ~MultiplyOp(){}
    double compute(double a, double b) override {
        cout<<a*b<<"\n";
    }
    double compute(int a){
        cout<<a*a<<"\n";
    }
};

int main(){

    MathOp* add = new AddOp();
    MathOp* mul = new MultiplyOp();
    
    add->compute(1,2);
    mul->compute(2,3);
    // To call compute(int), cast to the derived type or use derived pointers
    static_cast<AddOp*>(add)->compute(2);
    static_cast<MultiplyOp*>(mul)->compute(3);

}


