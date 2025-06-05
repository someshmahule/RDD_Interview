#include<iostream>

template<typename T>
class MyUniquePtr {
    // Your implementation
    T* myptr;
    public:
    MyUniquePtr(T* ptr){
        myptr = ptr;
    }
    MyUniquePtr(MyUniquePtr& ptr) = delete; //delete copy constructor
    MyUniquePtr& operator=(MyUniquePtr& ) = delete; //delete copy assignment

    MyUniquePtr(MyUniquePtr&& other) noexcept
        : myptr(other.myptr) {
        other.myptr = nullptr;
    }
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        if (this != &other) {
            delete myptr;
            myptr = other.myptr;
            other.myptr = nullptr;
        }
        return *this;
    }
    T* operator->() {
        return myptr;
    }

    bool operator!(){
        return myptr == nullptr;
    }

    T& operator*(){
        return *myptr;
    }

    ~MyUniquePtr() {
        delete myptr;
    }

    T* release(){

        T* tmp = myptr;
        myptr = nullptr;
        return tmp;
    }

    T* reset(T* ptr = nullptr){
        delete myptr;
        myptr = ptr;
    }
};

struct Test {
    void hello() { std::cout << "Hello!\n"; }
};

int main() {
    MyUniquePtr<Test> ptr(new Test());
    ptr->hello();

    MyUniquePtr<Test> ptr2 = std::move(ptr);
    if (!ptr2) std::cout << "ptr is now null\n";

    return 0;
}
