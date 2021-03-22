#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

void showMenu();

double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);

void calculatorWrite(ofstream&);
void calculatorRead(ifstream&);

string operations = "";

const string file = "Calculations.txt";

int main()
{
    int choice;
    do {
        // ask user for input
        do {
            showMenu();

            cin >> choice;

            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            /*
                The above line is needed to clear the cin buffer.
                (for some reason inputing a string causes the cin to stop
                accepting new inputs, causing an infinite loop)
                see https://stackoverflow.com/a/5864560
            */
        } while (choice < 1 || choice > 5);
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
            add(x, y);
            break;
        case 2:
            subtract(x, y);
            break;
        case 3:
            multiply(x, y);
            break;
        case 4:
            divide(x, y);
            break;
        }
        cout << endl;
    } while (choice != 5); // break case 5

    { // write
        ofstream OUT;
        OUT.open(file);
        calculatorWrite(OUT);
        OUT.close();
    }
    { // read
        ifstream IN;
        IN.open(file);
        calculatorRead(IN);
        IN.close();
    }
    return 0;
}

void showMenu() {
    cout << "My Calculator" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice: (1-5):" << endl;
}

double add(double x, double y) {
    double v = x + y;
    cout << v;
    operations += to_string(x) + " + " + to_string(y) + " = " + to_string(v) + '\n';
    return v;
}

double subtract(double x, double y) {
    double v = x - y;
    cout << v;
    operations += to_string(x) + " - " + to_string(y) + " = " + to_string(v) + '\n';
    return v;
}

double multiply(double x, double y) {
    double v = x * y;
    cout << v;
    operations += to_string(x) + " * " + to_string(y) + " = " + to_string(v) + '\n';
    return v;
}

double divide(double x, double y) {
    double v = NULL;
    if(y != 0){
        v = x / y;
        cout << v;
    }else
        cout << "Divide by zero error";
  
    operations += to_string(x) + " / " + to_string(y) + " = " + (v != NULL ? to_string(v) : "Divide by zero error") + '\n';
    return v;
}

void calculatorWrite(ofstream& OUT) {
    OUT << operations;
}

void calculatorRead(ifstream& IN) {
    string buffer;
    while (getline(IN, buffer))
        cout << buffer << endl;
}