/*  get_id
    sleep_for
    sleep_untill
    yield
    hardware_concurrency
*/

#include<iostream>
#include<thread>
#include<string>
#include<atomic>
#include<mutex>

using namespace std;

std::atomic<bool> ready{false};

mutex mtx;

void printThread(string s){

    lock_guard lk(mtx);
    cout<<s<<" "<<this_thread::get_id()<<"\n";
    this_thread::sleep_for(chrono::seconds(1));
    this_thread::sleep_until(chrono::steady_clock::now()+chrono::seconds(2));
    cout<<"Number of cores: "<<thread::hardware_concurrency();
}

void spin_wait(){
    while(!ready){
        this_thread::yield();
    }
    cout<<"Thread unblocked\n";
}

int main(){

    thread t1(printThread,"somesh");
    thread t2(printThread,"mahule");

    thread t3(spin_wait);
    this_thread::sleep_for(chrono::seconds(2));

    ready = true;

    t1.join();
    t2.join();
    t3.join();

}


