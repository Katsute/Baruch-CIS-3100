#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int choice;
    do {
        // ask user for input
        do {
            cout << "My Calculator" << endl;
            cout << "1. Addition" << endl;
            cout << "2. Subtraction" << endl;
            cout << "3. Multiplication" << endl;
            cout << "4. Division" << endl;
            cout << "5. Quit" << endl;
            cout << "Enter your choice: (1-5):" << endl;

            cin >> choice;

            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            /*
                The above line is needed to clear the cin buffer.
                (for some reason inputing a string causes the cin to stop
                accepting new inputs, causing an infinite loop)

                see https://stackoverflow.com/a/5864560
            */
        } while (choice < 1 || choice > 5); // input validation not needed b/c null is 0
        // ^ continue until integer input and between 1-5

        if (choice == 5)
            break; // exit case 5

        // number input
        bool validCIN = false;
        float x, y;
        do {
            cout << "Enter the first number:" << endl;
            cin >> x;
            validCIN = cin.good(); // if cin is an int

            cin.clear(); // clear bad cin (explained above)
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while (!validCIN);
        // ^ continue until float input

        do {
            cout << "Enter the second number:" << endl;
            cin >> y;
            validCIN = cin.good(); // if cin is an int

            cin.clear(); // clear bad cin (explained above)
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while (!validCIN);
        // ^ continue until float input

        cout << fixed << setprecision(2); // cap two places
        // calculate
        switch (choice) {
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
                if (y == 0)
                    cout << "Divide by zero error";
                else
                    cout << x / y;
                break;
        }
        cout << endl;
    } while (choice != 5); // break case 5
    return 0;
}
