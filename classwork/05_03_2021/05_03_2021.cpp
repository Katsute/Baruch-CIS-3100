#include <iostream>
#include "Square.h"; // include header file to get method declarations
using namespace std;

class Rectangle {

    private:
        int width;
        int height;

    public:
        Rectangle(); // constructor

        int setWidth(int);
        int getWidth();

        int getHeight() const // inline declaration
            { return height; };

};

Rectangle::Rectangle() {
    width = 0;
    height = 0;
}

int Rectangle::setWidth(int w) { // prototype declaration
    return width = w;
}

int Rectangle::getWidth() {
    return width;
}

int main() {
    Rectangle r;
    r.setWidth(2);
    cout << r.getWidth();

    Square s;
    s.setSize(1);
}