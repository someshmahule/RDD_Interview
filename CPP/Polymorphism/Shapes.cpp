#include<iostream>
#include<vector>
using namespace std;

class Shapes{
    public:
    Shapes(){cout<<"Shape Created\n";}
    virtual ~Shapes(){cout<<"Shape Destroyed\n";}
    virtual double area() = 0;
};

class Circle : public Shapes{

    public:
    int radius;
    Circle(int r) : radius(r) { cout<<"Circle Created\n";}
    ~Circle() {cout<<"Circle Destroyed\n";}
    double area() override{
        cout<<3.14 * radius *radius<<"\n" ;
    }
};


class Rectangle : public Shapes{
    public:
    int width;
    int height;
    Rectangle(int w, int h):width(w), height(h) {}
    ~Rectangle(){cout<<"Rectangle Destroyed\n";}
    double area() override {
        cout<< width*height<<"\n";
    }
};


class Triangle : public Shapes{
    public:
    int base;
    int height;
    Triangle(int b, int h): base(b), height(h) {cout<<"Triangle Created\n";}
    ~Triangle(){cout<<"Triangle destroyed\n";}
    double area() override {
        cout<<0.5 * base*height<<"\n";
    }

};


int main(){

    vector<Shapes*> vec;
    vec.push_back(new Triangle(2,3));
    vec.push_back(new Rectangle(4,5));
    vec.push_back(new Circle(5));

    for(auto it = vec.begin(); it!=vec.end();it++){
        (*it)->area();
    }

    for(auto it: vec){
        delete it;
    }
    return 0;
}

