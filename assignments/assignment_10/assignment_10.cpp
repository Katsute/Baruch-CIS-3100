#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct Calculation {

    double x, y;
    char opr;

};

const int CALCULATIONS = 3;

const string file = "CalculatorOutput.txt";
void saveCalculations(const Calculation* ptr) {
    ofstream OUT;
    OUT.open(file);

    // write existing content
    ifstream IN;
    IN.open(file);
    string buffer;
    while (getline(IN, buffer))
        cout << buffer;

    // new calculations
    Calculation calc;
    for (int i = 0; i < CALCULATIONS; i++) {
        calc = *(ptr + i);
        OUT << calc.x << calc.opr << calc.y << endl;
    }
    OUT.close();
}

double evaluate(Calculation);

int main() {
    Calculation myCalculationArray[CALCULATIONS] = {};

    bool cont;
    do{
        for(int i = 0; i < CALCULATIONS; i++){
            int pos; // index of opr
            string IN;
            do{
                cout << "Enter calculation: " << endl;
                cin >> IN;
            } while ( // continue while:
                ( // operator pos is not found
                    (pos = IN.find('+')) == string::npos &&
                    (pos = IN.find('-')) == string::npos &&
                    (pos = IN.find('*')) == string::npos &&
                    (pos = IN.find('/')) == string::npos 
                ) ||
                pos == 0 || // no numbers before operator (index 0)
                pos == IN.length() - 1 // no numbers after operator (last index)
            );

            // add to arr
            Calculation calc;
            myCalculationArray[i] = calc = {
                stod(IN.substr(0, pos)), // before opr
                stod(IN.substr(pos + 1)), // after opr
                IN.at(pos) // opr
            };

            // result
            cout << fixed << setprecision(2);
            switch (calc.opr) {
                case '+':
                    cout << calc.x + calc.y;
                    break;
                case '-':
                    cout << calc.x - calc.y;
                    break;
                case '*':
                    cout << calc.x * calc.y;
                    break;
                case '/':
                    if (calc.y == 0)
                        cout << "Divide by zero error";
                    else
                        cout << calc.x / calc.y;
                    break;
            }
            cout << endl;
        }

        saveCalculations(myCalculationArray);

        // continue
        cout << "Continue? (Y/N)" << endl;
        char yn;
        cin >> yn;
        cont = yn == 'Y' || yn == 'y';
    }while(cont);
}