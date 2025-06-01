#include<iostream>

using namespace std;

template<typename T>
class Queue{
    int st;
    int end;
    T* arr;
    public:
    Queue(){
        arr = new T[100];
        st = 0;
        end = 0;

    }
    ~Queue(){
        delete [] arr;
    }
    void enqueue(T ele){
        if((end - st) >= 0){
            arr[end] = ele;
            end = (end+1) % 100;
        }
        else{
            cout<<"Queue overflow\n";
        }
    }

    T dequeue(){
        T ret;
        if((end - st) != 0){
            ret = arr[st];
            st = (st+1) % 100;
        }
        else{
            cout<<"Queue Empty\n";
        }
    }

    T front(){
        return arr[st];
    }

    bool isEmpty(){
        if((end - st) == 0){
            return true;
        }
        else{
            return false;
        }
    }
};

int main (){
    Queue<int> q1;
    q1.enqueue(1);
    q1.enqueue(2);
    cout<<q1.front()<<"\n";
    q1.dequeue();
    cout<<q1.front()<<"\n";
    cout<<q1.isEmpty()<<"\n";
    q1.dequeue();
    q1.dequeue();
    cout<<q1.isEmpty()<<"\n";
    return 0;
}