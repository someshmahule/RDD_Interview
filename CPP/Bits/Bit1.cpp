#include<iostream>
#include<cstdint>

using namespace std;


int main(){

    uint32_t num = 0x12345678;
    uint8_t* ptr = reinterpret_cast<uint8_t*>(&num);

    for(int i=0;i<4;i++){
        printf("Byte %d: 0x%02X",i,ptr[i]);
    }


}