#include <iostream>
using namespace std;

class TwoSum {
public:
    static const int SIZE = 5;
    int arr[SIZE];
    void printArr();
};

void TwoSum::printArr() {
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    TwoSum obj;
    for (int i = 0; i < TwoSum::SIZE; i++) {
        obj.arr[i] = i;
    }
    obj.printArr();
    return 0;
}