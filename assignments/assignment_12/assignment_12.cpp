#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {

    private:
        string name, department, position;
        int idNumber;

    public:
        // constructor
        Employee(string name, int idNumber, string department, string position) {
            this->name       = name;
            this->idNumber   = idNumber;
            this->department = department;
            this->position   = position;
        };
        // constructor (2 args)
        Employee(string name, int idNumber) : Employee(name, idNumber, "", "") { };
        // default constructor
        Employee() : Employee("", 0, "", "") { };

        // get/set
        string getName() const { return name; };
        void setName(string name) { this->name = name; };

        int getID() const { return idNumber; };
        void setID(int id) { this->idNumber = id; };

        string getDepartment() const { return department; };
        void setDeparment(string department) { this->department = department; };

        string getPosition() const { return position; };
        void setPosition(string position) { this->position = position; };

};

int main() {
    // init array
    Employee employees[3] = {
        Employee("Susan Meyers", 47889, "Accounting", "Vice President"),
        Employee("Mark Jones", 39119, "IT", "Programmer"),
        Employee("Joy Rogers", 81774, "Manufacturing", "Engineer")
    };

    // header
    int col = 15;
    cout 
        << left << setw(col) << "Name"
        << left << setw(col) << "Number"
        << left << setw(col) << "Department"
        << left << setw(col) << "Position" << endl;
    for (int i = 0; i < col*4; i++) cout << '-';
    cout << endl;
    // print array
    for (Employee e : employees)
        cout
            << left << setw(col) << e.getName()
            << left << setw(col) << e.getID()
            << left << setw(col) << e.getDepartment()
            << left << setw(col) << e.getPosition() << endl;
}