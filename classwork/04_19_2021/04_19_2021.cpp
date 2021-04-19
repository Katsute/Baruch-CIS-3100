#include <iostream>
#include <cstdlib> // for char array
#include <string> // for string object
using namespace std;

int main()
{
    // parse cstring as number (char array)
    int iNum = atoi("1");
    long lNum = atol("1");
    double dNum = atof("1");
    // invalid returns either null or 0

    // parse string as number (string object)
    int iNum2 = stoi("1");
    long lNum2 = stol("1");
    unsigned long ulNum = stoul("1");
    long long llNum = stoll("1");
    unsigned long long ullNum = stoull("1");
    float fNum = stof("1");
    double dNum2 = stod("1");
    long double ldNum = stold("1");

    // number to string
    to_string(1);
    to_string(1L);
    to_string(1.0);
    to_string(1.f);

    // cin to string
    string str;
    cin >> str; // ! cin terminates at first whitespace character

    string newstr("new string");
    string startstr("first", 3); // initialize first 3 chars
    string posstr("position", 3, 2); // initialize first 3 chars starting at 2nd char
    string repstr('a', 5); // initialize as 5 of same character

    // string methods
    /*
        assign, copy, data
        append, clear, erase, insert, replace, swap
        capacity, empty, length, resize, size
        find, front, back, at, substr
        compare
    */
}
