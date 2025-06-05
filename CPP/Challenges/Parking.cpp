#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Level;
class Vehicle;

class Vehicle{

    public:
    string type;
    Vehicle(string t) : type(t){
        
    }
    ~Vehicle(){

    }
};


class ParkingSpot{
    public:
    int id;
    Vehicle* v;
    bool available;

    ParkingSpot(int i,bool avail) : id(i), available(avail){
        cout<<"Parking spot: "<<id<<"created\n";
        v = nullptr;
    }
    ~ParkingSpot(){
        delete v;
        cout<<"Parking spot: "<<id<<"destroyed\n";
    }
    int getID(){
        return id;
    }
    Vehicle* whatParked(){
        return v;
    }
    bool isEmpty(){
        return available;
    }

};


class Level{
    public:
    int id;
    int totalParkingSpots;
    int emptyParkingSpots;
    vector<ParkingSpot*> pAvailable;

    Level(int i, int totalSpots) : id(id), totalParkingSpots(totalSpots){
        cout<<"Level created\n";
        emptyParkingSpots = totalParkingSpots;
        for(int i=0;i<totalParkingSpots;i++){
            pAvailable.emplace_back(new ParkingSpot(i,true));
        }
    }
    ~Level(){
        cout<<"Level destroyed\n";
    }
    ParkingSpot& getParkingSpot(int i){
        for(auto v : pAvailable){
            if(v->id == i){
                return *v;
            }
        }
    }

};

class ParkingLot{

    public:
    int levels;
    vector<Level*> lv;
    ParkingLot(int l): levels(l){
        cout<<"Parking lot created\n";
        for(int i=0;i<levels;i++){
            lv.emplace_back(new Level(i,10));
        }
    }
    ~ParkingLot() {
        cout<<"Parking lot destroyed\n";
    }
    Level& getLevels(int i){
        for(auto v : lv){
            if(v->id == i){
                return *v;
            }
        }
    }
    bool parkVehicle(Vehicle* v){
        bool parked= false;
        for(auto l: lv){
            for(auto ps:l->pAvailable){
                if(ps->available && l->emptyParkingSpots>0){
                    ps->v = v;
                    ps->available = false;
                    l->emptyParkingSpots--;
                    parked = true;
                }
            }
        }
        return parked;
    }
    bool unParkVehicle(Vehicle *v){
        bool unparked = false;
        for(auto l: lv){
            for(auto ps:l->pAvailable){
                if(ps->v == v){
                    ps->v = nullptr;
                    ps->available = true;
                    unparked = true;
                    l->emptyParkingSpots++;
                }
            }
        }
        return unparked;
    }

};


int main(){

    ParkingLot pl(10);
    Vehicle v("Car");
    cout<<"\nParked ??"<<pl.parkVehicle(&v)<<"\n";

    cout<<"\nUnParked ??"<<pl.unParkVehicle(&v)<<"\n";

}

