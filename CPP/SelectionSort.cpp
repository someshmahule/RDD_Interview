#include<iostream>
using namespace std;

class SelectionSort {
    public:
        int SIZE;
        int* arr;
        void createArray();
        void printArray();
        void doSort();
};

void SelectionSort::createArray(){

    cout<<"Enter size of the Array\n";
    cin>>SIZE;
    arr = new int[SIZE];
    for(int i=0;i<SIZE;i++)
    {
        int ele;
        cout << "Enter element: \n";
        cin >> ele;
        *(arr+i) = ele; 
    }
}

void SelectionSort::printArray(){

    for(int i =0;i<SIZE;i++)
    {
        cout<< *(arr+i) << "\n";
    }
}

void SelectionSort::doSort(){

    for(int i=0;i<SIZE;i++){
        int local_min = 1000;
        int min_index = i;
        for(int j=i;j<SIZE;j++){
            if(*(arr+j) < local_min){
                local_min = *(arr+j);
                min_index = j;
            }
        }
        int tmp = *(arr+i);
        *(arr+i) = *(arr+min_index);
        *(arr+min_index)  = tmp;
    }
}

int main(){

    SelectionSort obj;
    obj.createArray();
    obj.doSort();
    obj.printArray();
    return 0;
}