#include<iostream>

using namespace std;


class TravelStrategy{
    public:
    TravelStrategy(){}
    virtual ~TravelStrategy(){}
    virtual void travel(string start, string end) = 0;
};

class DrivingStrategy : public TravelStrategy{
    public:
    string name;
    DrivingStrategy() : name("Driving "){}
    ~DrivingStrategy(){}
    void travel(string start, string end) override{
        cout<<"Use "<<name<<" from "<<start<<" "<<end<<"\n";
    }
};

class PublicTransitStrategy : public TravelStrategy{
    public:
    string name;
    PublicTransitStrategy() : name("Public Transit "){}
    ~PublicTransitStrategy(){}
    void travel(string start, string end) override{
        cout<<"Use "<<name<<" from "<<start<<" "<<end<<"\n";
    }
};

class BicycleStrategy : public TravelStrategy{
    public:
    string name;
    BicycleStrategy() : name("Bicycle") {}
    ~BicycleStrategy(){}
    void travel(string start, string end) override{
        cout<<"Use "<<name<<" from "<<start<<" "<<end<<"\n";
    }
};

class WalkingStrategy : public TravelStrategy{
    public:
    string name;
    WalkingStrategy() : name("Walking"){}
    ~WalkingStrategy(){}
    void travel(string start, string end) override{
        cout<<"Use "<<name<<" from "<<start<<" "<<end<<"\n";
    }
};

class RoutePlanner{
    public:
    TravelStrategy* tss;
    RoutePlanner(TravelStrategy* ts){
        tss = ts;
    }
    ~RoutePlanner() {}
    void setStrategy(TravelStrategy* ts){
        tss = ts;
    }
    void planRoute(string start, string end){
        tss->travel(start,end);
    }

};


int main() {

    RoutePlanner planner(new DrivingStrategy());
    planner.planRoute("Home", "Office");

    planner.setStrategy(new WalkingStrategy());
    planner.planRoute("Home", "Park");

}