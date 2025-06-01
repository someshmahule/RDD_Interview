#include<iostream>

using namespace std;

class Buffer{
    public:
    int size;
    int* buf;

    //constructor
    Buffer(int s): size(s){
        cout<<"Constructor called\n";
        buf = new int[size];

        //fill the buffer
        for(int i=0;i<size;i++){
            buf[i] = i;
        }
    }

    //Destructor
    ~Buffer(){
        cout<<"Destructor called\n";
        delete [] buf;
    }

    //copy constructor
    Buffer(Buffer& other):size(other.size){
        cout<<"Copy constructor called\n";
        buf = new int[size];

        //copy the content
        for(int i=0;i<size;i++){
            buf[i] = other.buf[i];
        }
    }

    //Copy Assignment
    Buffer& operator=(Buffer& other) {
        if(this == &other) return *this;

        delete[] buf;

        size = other.size;
        buf = new int[size];

        for(int i=0;i<size;i++){
            buf[i] = other.buf[i];
        }
        return *this;
    }

    //Move constructor
    Buffer(Buffer&& other)noexcept :size(other.size), buf(other.buf){
        other.size = 0;
        other.buf = nullptr;
        cout<<"Move constructor called\n";
    }

    //Move assignment
    Buffer& operator=(Buffer&& other) noexcept{
        if(this == &other) return *this;
        delete[] buf;
        size = other.size;
        buf = other.buf;

        other.size =0;
        other.buf = nullptr;
        cout<<"Move operator called\n";

        return *this;
    }

    void print(){
        for(int i=0;i<size;i++)
        {
            cout<<buf[i]<<" ";
        }
        cout<<"\n";
    }
};

int main(){

    Buffer b1(5); //constructor
    Buffer b2 = b1; //copy constructor
    b2.print();
    Buffer b3(5);
    b3 = b1; 
    b3.print();
    Buffer b4 = std::move(b3);
    b4.print();
    Buffer b5(6);
    b5 = std::move(b4);

    b5.print();
}
