#include <iostream> // import lib/file
using namespace std; // static import

// generally follows Java coding conventions.
int main()
{
    /*
        same data types as Java
        same naming conditions as Java
    */
    double hours, rate, pay;

    // << insert into stream (sys.out)
    cout << "How many hours did you work? "; // sys out
    // >> write from stream (sys.in)
    cin >> hours; // sys in, auto parses num

    cout << "How much do you get paid per hour? "; // sys out
    cin >> rate; // sys in

    pay = hours * rate;

    cout << "You have earned $" << pay << endl; // str concat + endline
    return 0;
}
