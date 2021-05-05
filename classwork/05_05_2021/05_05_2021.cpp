#include <iostream>
using namespace std;

class Rectangle {

    private:
        double w, h;

    public:
        Rectangle() : Rectangle(0, 0) { /* additional code */ } // delegation (use another constructor)
        Rectangle(double); // overloading
        Rectangle(double, double);
        ~Rectangle(); // destructor, runs right before cleared from memory; no args or return allowed

};

Rectangle::Rectangle(double w) {
    this->w = w;
    this->h = 0;
}

Rectangle::Rectangle(double w = 0, double h = 0) { // default args (only one constructor allowed)
    this->w = w;
    this->h = h;
}

Rectangle::~Rectangle() { // destructor (only one allowed)
    // remove dynamically allocated addresses here (use delete)
}

int main() {
    Rectangle r(10, 5); // constructor

    // init class array
    Rectangle rs[3] = {
        Rectangle(1, 2), Rectangle(3, 4), Rectangle(5, 6)
    };

    // declare using single arg constructor
    Rectangle rs2[3] = { 1, Rectangle(1, 0), Rectangle(1, 0) };
}