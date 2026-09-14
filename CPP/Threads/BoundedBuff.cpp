#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>

using namespace std;

const int sz = 3;
vector<int> buffer;
mutex mtx;
condition_variable cv_full, cv_empty;

void producer() {
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv_full.wait(lock, [] { return buffer.size() < sz; });

        buffer.push_back(1);
        cout << "Produced. Buffer size: " << buffer.size() << endl;

        lock.unlock();  // unlock before notify
        cv_empty.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer() {
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv_empty.wait(lock, [] { return !buffer.empty(); });

        buffer.pop_back();
        cout << "Consumed. Buffer size: " << buffer.size() << endl;

        lock.unlock();  // unlock before notify
        cv_full.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main() {

    vector<thread> producers;
    vector<thread> consumers;
    for(int i=0;i<3;i++){
        producers.emplace_back(producer);
    }
    
    for(int i=0;i<3;i++)
    {
        consumers.emplace_back(consumer);
    }

    for(auto& p :producers){
        p.join();
    }

    for(auto& c :consumers){
        c.join();
    }


    return 0;
}
