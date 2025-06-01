#include<iostream>
#include <thread>

using namespace std;

void say_hello(){
    cout<<"Hello from thread\n";
}

int main(){

    std::thread t(say_hello);
    t.join();
    return 0;
}