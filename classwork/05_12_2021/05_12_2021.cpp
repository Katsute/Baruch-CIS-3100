#include <iostream>

class Opr {

    public:
        // override what the operator does
        const Opr operator=(const Opr& right) {
            return *this;
        }

        const int operator+(const Opr& right);
        const int operator-(const Opr& right);
        const int operator*(const Opr& right);
        const int operator/(const Opr& right);

        // can not be overloaded:
        // ?:
        // .
        // .*
        // ::
        // sizeof

        // streams

        const std::ostream& operator << (std::ostream& strm);
        const std::istream& operator >> (std::istream& strm);

        // ++ , --

        const Opr operator++(); // opr++
        const Opr operator++(int); // ++opr; int not used, mainly to differentiate methods
        const Opr operator--(); // opr--
        const Opr operator--(int); // --opr; int not used, mainly to differentiate methods

        // []

        const int &operator[](const int x); // for arrays, override return

        // object conversion

        operator int(); // int x = opr;

};

int main() {

}
