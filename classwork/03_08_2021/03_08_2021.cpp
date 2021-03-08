#include <iostream>
using namespace std;

int main()
{
    // while, execute while condition
    while (false)
        cout << "don't execute";

    // do-while, execute at least once while condition
    do
        cout << "execute once" << endl;
    while (false);

    // for, execute with counter condition
    for (int i = 0; i < 2; i++)
        cout << i;
}
