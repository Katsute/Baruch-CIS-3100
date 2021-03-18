#include <iostream>
#include <cstdlib> // rand
using namespace std;

int main()
{
    cin.ignore(); // skip
    cout << "passed";
    cin.ignore(10, '\n'); // skip until 10 characters or newline
    cout << "passed" << endl;

    // string & concatenation
    string str = "string";
    int size = str.length();
    str += " concat";

    /*
        math (requires import)
        #include <cmath>

        generally same method names as Java
    */

    // randoms
    int seed;

    cin >> seed;
    srand(seed); // randomly seed (by default always uses same seed)
    cout << rand(); // rand between 0 and max int

    // relational operators: >, <, >=, <=, ==, !=
    bool b = 1 > 10;

    // if statment
    if (true)
        cout << "true";
    else
        cout << "false";
    if (1) // 1 is true and 0 is false
        cout << "true";
    else
        cout << "false";

    return 0;
}