#include<iostream>
using namespace std;

template<typename T>
class Stack{
    int indx;
    public:
    T* arr;
    Stack(){
        indx = -1;
        arr = new T[100];
    }
    ~Stack(){
        delete [] arr;
    }
    void push(const T& value){
        indx++;
        arr[indx]=value;
    }

    T top(){
        T t = arr[indx];
        return t;
    }

    void pop(){
        indx--;
    }

    bool isEmpty(){
        if(indx==0){
            return true;
        }
        return false;
    }

    int size(){
        return indx+1;
    }
};

int main(){

    Stack<int> s;
    s.push(1);
    s.push(2);
    cout<<s.top()<<"\n";
    s.push(3);
    cout<<s.top()<<"\n";
    s.pop();
    cout<<s.top()<<"\n";

    Stack<string> ss;
    ss.push("Hi");
    ss.push("How");
    cout<<ss.top()<<"\n";
    ss.push("Are");
    cout<<ss.top()<<"\n";
    ss.pop();
    cout<<ss.top()<<"\n";
    cout<<ss.size();
    return 0;

}

