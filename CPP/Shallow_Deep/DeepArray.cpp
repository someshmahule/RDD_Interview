#include<iostream>

using namespace std;

class DynamicArray{

    public:
    int size;
    int* arr;

    //Constructor 
    DynamicArray(int s): size(s) {
        cout<<"Constructor called\n";
        arr = new int[s];
        for(int i =0;i<size; i++){
            arr[i] = i;
        }
    }

    //Copy Constructor
    DynamicArray(DynamicArray& darr): size(darr.size) {
        cout<<"Copy constructor called\n";
        arr = new int[darr.size];
        for (int i=0;i<darr.size;i++){
            arr[i] = darr.arr[i];
        }
    }

    //Destructor
    ~DynamicArray(){
        cout<<"Destructor called\n";
        delete [] arr;
    }

    //Copy Assignment operator
    DynamicArray& operator=(DynamicArray& darr){
        if(this == &darr) return *this;
        delete[] arr;
        
        size = darr.size;
        arr = new int[darr.size];
        for (int i = 0; i < size; ++i) {
            arr[i] = darr.arr[i];
        }
        cout << "Copy assignment operator called\n";
        return *this;

    }

    //Move Constructor
    DynamicArray(DynamicArray&& darr) noexcept : size(darr.size), arr(darr.arr){
        darr.arr= nullptr;
        darr.size = 0;
        cout<<"Move constructor called\n";
    }

    //Move Assignement
    DynamicArray& operator=(DynamicArray&& darr) noexcept {
        cout<<"Move assignment operator called\n";
        if(this == &darr) return *this;

        delete[] arr;
        size = darr.size;
        arr = darr.arr;
        darr.arr = nullptr;
        darr.size = 0;

        return *this;
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

};

int main() {
    DynamicArray arr1(5);      // constructor
    DynamicArray arr2 = arr1;  // copy constructor
    DynamicArray arr3(3);      

    arr3 = arr1;               // copy assignment

    DynamicArray arr4 = std::move(arr1);  // move constructor
    DynamicArray arr5(2);
    arr5 = std::move(arr2);               // move assignment

    arr3.print();
    arr4.print();
    arr5.print();

    return 0;
}
