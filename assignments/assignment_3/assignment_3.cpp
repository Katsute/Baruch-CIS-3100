#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // menu
    cout << "My Calculator" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Quit" << endl;
    // choice
    cout << "Enter your choice: (1-5):" << endl;
    short i;
    cin >> i;

    // nums (assignment requires that we ask for these regardless of the choice)
    float x, y;
    cout << "Enter the first number:" << endl;
    cin >> x;
    cout << "Enter the second number:" << endl;
    cin >> y;

    // fixed places
    cout << fixed << setprecision(2);
    // switch case
    switch (i) {
        case 1:
            cout << x + y;
            break;
        case 2:
            cout << x - y;
            break;
        case 3:
            cout << x * y;
            break;
        case 4:
            /*
                This cannot be a ternary because it would require x/y to
                be casted as a string and that prevents #setprecision from
                working properly.
            */
            if (y == 0)
                cout << "Divide by zero error";
            else
                cout << x / y;
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid entry";
            break;
    }
    return 0;
}
