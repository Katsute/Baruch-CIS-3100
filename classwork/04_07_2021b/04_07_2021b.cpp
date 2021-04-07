#include <iostream>
using namespace std;

int main(){
    int num = -99;
    cout << &num; // returns address in memory

    int *addr;
    addr = &num; // assign address to a variable
}