#include<iostream>
#include<vector>
#include<memory>

using namespace std;

class Shapes{

    public:
    virtual void draw();
    Shapes() {}
    virtual ~Shapes() {}
    void renderScene(vector<unique_ptr<Shapes>>& shapes);
};

void Shapes::draw(){

    cout<<"Drawing a shape";
    
}

void Shapes::renderScene(vector<unique_ptr<Shapes>>& shapes){

    for(auto& shape:shapes){
        shape->draw();
    }

}

class Circle : public Shapes{

    public:
    void draw() override {
        cout<<"Draws a Circle\n";
    }
    ~Circle() {}

};

class Rectangle : public Shapes{

    public:
    void draw() override {
        cout<<"Draws Rectangle\n";
    }
    ~Rectangle() {}
};

class Triangle : public Shapes{

    public:
    void draw() override {cout<<"Draws a Triagle\n";}
    ~Triangle(){}
};


int main()
{

    vector<unique_ptr<Shapes>> vec;
    vec.push_back(make_unique<Circle>());
    vec.push_back(make_unique<Rectangle>());
    vec.push_back(make_unique<Triangle>());

    Shapes* obj = new Shapes();
    obj->renderScene(vec);
    delete obj;

    return 0;
}