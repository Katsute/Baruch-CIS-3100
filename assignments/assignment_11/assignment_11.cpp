#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct Calculation {

    double x, y;
    char opr;
    double result;

};

const int CALCULATIONS = 3;

const string file = "CalculatorOutput.txt";
void saveCalculations(const Calculation* ptr) {
    fstream IO;
    IO.open(file, ios::app | ios::binary);
    // append new calculations
    Calculation calc;
    for (int i = 0; i < CALCULATIONS; i++) {
        calc = *(ptr + i);
        IO.write(reinterpret_cast<char*>(&calc), sizeof(calc));
    }
    IO.close();
}

bool isNumber(const string str) {
    const int LEN = str.length();

    if (
        LEN == 0 || // if empty
        str == "." // or is only decimal (weird edge case)
    )
        return false;

    bool containsDec = false;
    for (int i = 0; i < LEN; i++) {
        char ch = str.at(i);
        if (ch == '-' && i > 0) // if negative sign is not first
            return false;
        else if (ch == '.')
            if (containsDec) // if contains more than one decimal
                return false;
            else
                containsDec = true;
        else if (ch != '-' && ch != '.' && !isdigit(ch)) // if not digit or - or .
            return false;
    }
    return true;
}

string trim(const string str) {
    string out = "";
    for (char ch : str)
        if (ch != ' ' && ch != '\t') // remove whitespace
            out += ch;
    return out;
}

// notable issue: calculations with negative inputs may not work correctly
//                because the negative sign is treated as a minus symbol
int main() {
    Calculation myCalculationArray[CALCULATIONS] = {};

    bool cont;
    do {
        for (int i = 0; i < CALCULATIONS; i++) {
            int pos; // index of opr
            string n1, n2; // before/after opr
            string IN;
            do {
                cout << "Enter calculation: " << endl;
                getline(cin, IN);
                cin.clear();
            } while ( // continue while:
                ( // operator pos is not found
                    (pos = IN.find('+')) == string::npos &&
                    (pos = IN.find('-')) == string::npos &&
                    (pos = IN.find('*')) == string::npos &&
                    (pos = IN.find('/')) == string::npos
                ) ||
                !isNumber(n1 = trim(IN.substr(0, pos))) || // str before opr is not number
                !isNumber(n2 = trim(IN.substr(pos + 1))) // str after opr is not number
            );

            // add to arr
            Calculation calc;
            myCalculationArray[i] = calc = {
                stod(n1), // before opr
                stod(n2), // after opr
                IN.at(pos) // opr
            };

            // result
            cout << fixed << setprecision(2);
            switch (calc.opr) {
                case '+':
                    cout << (calc.result = calc.x + calc.y);
                    break;
                case '-':
                    cout << (calc.result = calc.x - calc.y);
                    break;
                case '*':
                    cout << (calc.result = calc.x * calc.y);
                    break;
                case '/':
                    if (calc.y == 0) 
                        cout << "Divide by zero error";
                    else
                        cout << (calc.result = calc.x / calc.y);
                    break;
            }
            myCalculationArray[i].result = calc.result;
            cout << endl;
        }

        saveCalculations(myCalculationArray);

        // continue
        cout << "Continue? (Y/N)" << endl;
        char yn;
        cin >> yn;
        cin.ignore();
        cont = yn == 'Y' || yn == 'y';
    } while (cont);

    cout << "Read calculations? (Y/N)" << endl;
    char yn;
    cin >> yn;
    if (yn != 'Y' && yn != 'y')
        return 0;

    Calculation buffer;
    fstream IO;
    IO.open(file, ios::in | ios::binary);
    int n = 1;
    while (!IO.eof()){
        IO.read(reinterpret_cast<char*>(&buffer), sizeof(buffer));
        if (IO.eof()) break; // break if this line is EOF
        cout << n++ << ". " << buffer.x << ' ' << buffer.opr << ' ' << buffer.y << " = " << buffer.result << endl;
    }
}