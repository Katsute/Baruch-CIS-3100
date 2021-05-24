#include <iostream>
using namespace std;

/*
    Create a class called Money that holds three variables: dollars, quarters and cents.
*/
class Money {

    private:
        int dollars;
        int quarters;
        int cents;

    public:
        /*
            Create a constructor that takes in a whole number value (representing cents) as a 
            default argument and stores the value in each of the variable by converting it. 
            Conversion formulas are here: 25 cents is 1 quarter and 4 quarters is 1 dollar. 
            For example, if value is 54 then it should save 2 in the quarters, 4 in cents and 
            0 in dollars. If the value is 324 then it should save 3 in dollars, 0 in quarters 
            and 24 in cents. Decimal values are not allowed. (Hint: cents should never be more 
            than 24 and quarters no more than 3 ).
        */
        Money(const int cents) {
            this->cents = cents % 100 % 25; // get rem of 100 then rem of 25 for cents < 25 #
            quarters = cents % 100 / 25; // get rem of 100 then div/25 for quarter #
            dollars = cents / 100; // int div only returns full dollars
        };
        /*
            Create a copy constructor.
        */
        Money(const Money& copy) {
            dollars = copy.dollars;
            quarters = copy.quarters;
            cents = copy.cents;
        }
        /*
            Overload the assignment, addition and subtraction operators that allow assignment, 
            addition and subtraction of two Money objects (respectively). This should allow 
            statements like: a = b + c; (where a, b and c are Money objects)
        */
        Money operator=(const Money& right) {
            dollars = right.dollars;
            quarters = right.quarters;
            cents = right.cents;
            return right;
        }
        Money operator+(const Money& right) {
            return Money( // convert all to cents
                ((dollars + right.dollars) * 100) +
                ((quarters + right.quarters) * 25) +
                (cents + right.cents)
            );
        }
        Money operator-(const Money& right) {
            return Money( // convert all to cents
                ((dollars - right.dollars) * 100) +
                ((quarters - right.quarters) * 25) +
                (cents - right.cents)
            );
        }
        /*
            Overload the assignment operator that allows assigning a whole number value to a 
            Money object. This should allow statements like: x = 76; (where x is a Money object). 
            Similarly, overload addition and subtraction operators that allow addition and 
            subtraction of a whole number value to a Money objects (respectively). This should 
            allow statements like: y + 100; (where y is a Money objects)
        */

        // simply convert to Money class then use existing operator methods
        Money operator=(const int& right) {
            return operator=(Money(right));
        }
        Money operator+(const int& right) {
            return operator+(Money(right));
        }
        Money operator-(const int& right) {
            return operator-(Money(right));
        }
        /*
            Overload the prefix and postfix operators for both ++ and --. These should add 
            or subtract one cent to the Money object.
        */
        Money operator++() { // postfix
            return operator=(operator+(1)); // add 1 to Money then assign itself to that new value
        }
        Money operator++(int prefix) {
            return operator=(operator+(1)); // add 1 to Money then assign itself to that new value
        }
        Money operator--() { // postfix
            return operator=(operator-(1)); // sub 1 from Money then assign itself to that new value
        }
        Money operator--(int prefix) {
            return operator=(operator-(1)); // sub 1 from Money then assign itself to that new value
        }

        friend ostream& operator<<(ostream&, const Money&);

        /*
            Overload both the greater than and less than operators (> and <). These should compare 
            the two money objects and return true and false. For example, if (a > b) should be true 
            if a is greater than b (in terms of their value).
        */
        bool operator>(const Money& right) {
            int thisv = (dollars * 100) + (quarters * 25) + cents;
            int rightv = (right.dollars * 100) + (right.quarters * 25) + right.cents;
            return thisv > rightv;
        }
        bool operator<(const Money& right) {
            int thisv = (dollars * 100) + (quarters * 25) + cents;
            int rightv = (right.dollars * 100) + (right.quarters * 25) + right.cents;
            return thisv < rightv;
        }

};

/*
    Overload the cout’s << operator so that the contents of a Money object can be displayed.
    Use proper formatting such as: "1 dollar, 2 quarters and 13 cents" or "4 dollars,
    1 quarter and 0 cents". (Pay attention about the plurals so it is "1 dollar" not "1 dollars")
*/
ostream& operator<<(ostream& stream, const Money& money) {
    stream << money.dollars << " dollar";
    if (money.dollars == 1)
        stream << " ";
    else
        stream << "s ";

    stream << money.quarters << " quarter";
    if (money.quarters == 1)
        stream << " ";
    else
        stream << "s ";

    stream << money.cents << " cent";
    if (money.cents == 1)
        stream << " ";
    else
        stream << "s ";

    return stream;
}

/*
    Overload the cin’s >> operator so that the contents of a Money object can be obtained
    from the user. Allow prompts: "Enter dollars: ", "Enter quarters: " and "Enter cents:
    ". If user entered more than 4 quarters or more then 25 cents than convert them using
    the conversion formula.
*/
istream& operator<< (istream& stream, Money& money) {
    int dollars, quarters, cents;
    cout << "Enter dollars: ";
    stream >> dollars;
    cout << endl << "Enter quarters: ";
    stream >> quarters;
    cout << endl << "Enter cents: ";
    stream >> cents;
    cout << endl;
    money = Money((dollars * 100) + (quarters * 25) + cents);
    return stream;
}

/*
    Demonstrate the class in a program.
*/
int main()
{
    Money aMoney = Money(135);
    Money bMoney = 127;
    cout << aMoney << endl;
    cout << bMoney << endl;
    cout << "__________" << endl;
    cout << aMoney + bMoney << endl;
    cout << aMoney - bMoney << endl;
    cout << aMoney + 100 << endl;
    cout << aMoney - 100 << endl;
    cout << "__________" << endl;
    cout << aMoney++ << endl;
    cout << aMoney << endl;
    cout << aMoney-- << endl;
    cout << aMoney << endl;

    // doesn't seem to be working

    // Money cMoney = NULL;
    // cin >> &cMoney;
    // cout << cMoney;
}
