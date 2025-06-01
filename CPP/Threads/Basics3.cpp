#include<iostream>
#include<thread>

using namespace std;

void back_ground(){

    this_thread::sleep_for(chrono::seconds(1));
    cout<<"Detached thread\n";
}

int main(){

    thread t(back_ground);
    t.detach();
    cout<<"Main thread done\n";
    this_thread::sleep_for(chrono::seconds(2));
    return 0;
}