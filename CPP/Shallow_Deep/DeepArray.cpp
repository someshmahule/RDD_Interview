#include<iostream>

using namespace std;

class DynamicArray{

    public:
    int size;
    int* arr;
    DynamicArray(int s): size(s) {
        arr = new int[s];
        for(int i =0;i<size; i++){
            arr[i] = i;
        }
    }
    DynamicArray(DynamicArray& darr): size(darr.size) {
        arr = new int[darr.size];
        for (int i=0;i<darr.size;i++){
            arr[i] = darr.arr[i];
        }
    }
    ~DynamicArray(){
        delete [] arr;
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

};

int main(){

    DynamicArray arr1(5);
    DynamicArray arr2 = arr1;

    arr1.print();
    arr2.print();
    return 0;
}