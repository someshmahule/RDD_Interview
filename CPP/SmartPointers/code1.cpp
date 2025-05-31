#include <iostream>
#include <memory>
using namespace std;

class Data {
public:
    Data(int val): value(val) { cout << "Data created\n"; }
    ~Data() { cout << "Data destroyed\n"; }
    int value;
};

int main() {
    Data* raw = new Data(42);
    shared_ptr<Data> sp1(raw);
    shared_ptr<Data> sp2(raw);  // 🔴 Bug?

    cout << "Value = " << sp1->value << endl;
    cout << "Value = " << sp2->value << endl;
    return 0;
}
