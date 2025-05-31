#include<iostream>

using namespace std;

class DynamicArray{

    public:
    int size;
    int * arr;
    DynamicArray(int s): size(s) {
        arr = new int[s];

        for(int i=0;i<s;i++){
            arr[i] = i;
        }

    }
    ~DynamicArray(){
        cout<<"Deleting ";
        delete [] arr;
    }
    DynamicArray(DynamicArray& darr){
        size = darr.size;
        arr = darr.arr;
    }
    void print(){
        for(int i = 0; i < size; i++){
            cout<<*(arr+i)<<" ";
        }
    }
};

int main(){

    DynamicArray arr1(5);
    DynamicArray arr2 = arr1;

    arr1.print();
    arr2.print();

}