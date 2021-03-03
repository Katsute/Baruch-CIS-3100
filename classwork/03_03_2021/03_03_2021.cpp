#include <iostream>
using namespace std;

int main()
{
    // same syntax as Java

    bool condition = true;
    bool value = condition ? true : false; // ternary -> condition ? if true : if false

    // switch case
    switch (1) {
        case 1:
            // run this only
            break; // exit switch
        case 2:
            // run this and below
            ;
        case 3:
            // run this and below
            ;
        default:
            // run if no cases met
            ;
    }

    // incr ++ ; decr --;
    {
        // the difference betwene prefix and postfix is the order
        int val = 0;
        int x = 0;

        x = val++; // same as x = val; val = val + 1;
        // x = 0
        // val = 1

        x--;
        val--;

        x = ++val; // same as val = val + 1; x = val;
        // x = 1
        // val = 1
    }

    // loops
    {
        for (int i = 0; i < 2; i++)
            cout << i;

        int i = -1;
        while (++i < 2) // while true do
            cout << i;
    }
}