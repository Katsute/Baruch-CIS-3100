#include <iostream>
using namespace std;

int main()
{
    int length, width, area;

    cout << "This program calculates the area of a ";
    cout << "rectangle.\n";
    cout << "What is the length and width of the rectangle? ";
    cin >> length >> width; // input space/newline separated
    // cout << "What is the length of the rectangle? ";
    // cin >> length;
    // cout << "What is the width of the rectangle? ";
    // cin >> width;
    area = length * width;
    cout << "The area of the rectangle is " << area << ".\n";
    return 0;
}