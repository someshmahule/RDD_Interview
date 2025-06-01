#include<iostream>

using namespace std;


class Vehicle{
    public:
    Vehicle(){}
    virtual ~Vehicle(){
        cout<<"Vehicle destroyed\n";
    }
    virtual void start() = 0;
    virtual void stop() = 0;
};


/*class Car : public Vehicle {
    public:
    Car() {}
    ~Car() {cout<<"Car destroyed\n";}
    void start() override {
        cout<<"Car started\n";
    }
    void stop() override {
        cout<<"Car stopped\n";
    }
};*/

/*class Bike : public Vehicle {
    public:
    Bike() {}
    ~Bike() {
        cout<<"Bike destroyed\n";
    }
    void start() override {
        cout<<"Bike started\n";
    }
    void stop() override {
        cout<<"Bike Stopped\n";
    }
};*/

class FourWheeler : public Vehicle{
    public:
    int ac;
    FourWheeler():ac(0){}
    virtual ~FourWheeler() {
        cout<<"Fourwheeler destroyed\n";
    }
    virtual void turnOnAC() = 0;

};

class SUV: public FourWheeler {
    public:
    SUV() {}
    ~SUV() { cout<<"SUV destroyed\n";
    }
    void start() override {
        cout<<"SUV started\n";
    }
    void stop() override {
        cout<<"SUV stopped\n";
    }
    void turnOnAC() override {
        cout<<"AC "<< ac;
    }


};

class Sedan : public FourWheeler {
    public:
    Sedan() {}
    ~Sedan() {
        cout<<"Sedan Destroyed\n";
    }
    void start() override {
        cout<<"Sedan Started\n";
    }
    void stop() override {
        cout<<"Sedan Stopped\n";
    }
    void turnOnAC() override {
        cout<<"AC "<< ac;
    }
};

void operateVehicle(Vehicle* v){
    if(dynamic_cast<FourWheeler*>(v)){
        dynamic_cast<FourWheeler*>(v)->turnOnAC();
    }
    v->start();
    v->stop();

}

enum VehicleType{
    SedanType,
    SUVType
};

class VehicleFactory{
    public:
    static Vehicle* createVechicle(VehicleType type){
        switch (type)
        {
        case SedanType:
            return new Sedan();
            break;
        case SUVType:
            return new SUV();
        default:
            break;
        }
    }
};

int main(){

    /*Vehicle* car = new Car();
    car->start();
    car->stop();
    delete car;

    Vehicle* bike = new Bike();
    bike->start();
    bike->stop();
    delete bike;*/

    Vehicle* tesla = VehicleFactory::createVechicle(VehicleType::SedanType) ;
    Vehicle* qualis = VehicleFactory::createVechicle(VehicleType::SUVType) ;
    operateVehicle(tesla);
    operateVehicle(qualis);
    delete tesla;
    delete qualis;
}
