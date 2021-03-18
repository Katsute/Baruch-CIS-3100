#include <iostream>
#include <iomanip> // setw()
#include <string>
using namespace std;

int main()
{
    // generally follow same order of operations & syntax as Java
    cout << pow(2, 2) << "\n\n";  // power needs no math import

    // number hierarchy (largest to smallest)
    long double ld = 10.2;
    double d = 10.2;
    float f = 10.2;
    unsigned long ul = -10.2; // wraps around to max long value
    long l = 10.2;
    unsigned int ui = -10.2; // wraps around to max int value
    int i = 10.2;

    // converts to int
    char c = 10.2;
    short s = 10.2;
    unsigned short us = -10.2;

    // values exceeding maximum size will wrap around to negatives (or max in case of unsigned)

    cout << ld << endl << d << endl << f << endl << ul << endl << l << endl << ui << endl << i 
        << endl << c << endl << s << endl << us;

    // type casting

    cout << endl << static_cast<int>(d); // preferred method of casting

    cout << endl << int(d); // older casting methods
    cout << endl << (int) d; // returns null if can not be cast

    // multiple assignments
    int x, y, z;

    x = y = z = 5; // processes from right to left
    x = (y = (z = 5)); // all variables equals 5

    cout << endl << x << ',' << y << ',' << z;

    // stream manipulators
    cout << endl << setw(4) << "50" << "45"; // set minimum width to use for columns
    cout << endl << setprecision(4) << fixed << 50.0; // set amount of places to display (doesn't work for ints)
    cout << endl << setw(5) << right << "50"; // left or right justified

    // cin full line
    string ln;
    cout << endl;
    getline(cin, ln);
    cout << ln;

    // cin char
    char ch;
    cout << endl;
    cin >> ch; // ignores whitespace
    cout << '[' << ch << ']' << endl;
    cin.get(ch); // allows all characters
    cout << '[' << ch << ']' << endl;

    return 0;
}