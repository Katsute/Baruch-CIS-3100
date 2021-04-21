#include <iostream>
using namespace std;

int main()
{
    Structure var = { 1, 1 }; // init structure (must be in same order)
    // ^ passed by value

    cout << (& var)->a; // access address of structure variable with arrow (struct only)

}

struct Structure { // abstract object

    int a;
    float b;

};