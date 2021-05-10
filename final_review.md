## Memory

Pointers must be of the same datatype as the value.

```cpp
int var = 0;
cout << &num; // returns the address in memory

int *addr; // represents an address for that datatype
addr = &num; // assign address from address of variable

int* nptr = nullptr; // initialize a pointer with address 0
```

### Arrays

```cpp
int values[] = {0, 1, 2};

cout << *values; // returns address of first in array

int *valptr = values;
cout << valptr[1]; // returns value of next item in array
cout << *(valptr + 1);

cout << valptr++;
```

## Strings

```cpp
#include <cstdlib> // for char array
#include <string> // for string object
```

```cpp
// cast to number (char array)
int iNum = atoi("1");
long lNum = atol("1");
double dNum = atof("1");
```

```cpp
// cast to number (string object)
int iNum = stoi("1");
long lNum = stol("1");
unsigned long ulNum = stoul("1");
long long llNum = stoll("1");
unsigned long long ullNum = stoull("1");
float fNum = stof("1");
double dNum = stod("1");
long double ldNum = stold("1");
```

```cpp
// number to string
to_string(1);
to_string(1L);
to_string(1.0);
to_string(1.f);
```

```cpp
string str("new string"); // initialize string
string start_str("first", 3); // initialize first 3 ('fir')
string pos_str("position", 3, 2); // initialize first 3 at pos ('sit')

string repstr('a', 5); // initialize repeated char
```

Additional methods:
 - assign
 - copy
 - data
 - append
 - clear
 - erase
 - insert
 - replace
 - swap
 - capacity
 - empty
 - length
 - resize
 - size
 - find
 - front
 - back
 - at
 - substr
 - compare

## Structure

```cpp
struct Structure {

    int a;
    float b;

}

Structure var = {1, 1}; // initialize structure in same order
```

## IOStream

Streams are always passed by reference

```cpp
#include <iostream>
#include <fstream>
```

```cpp
fstream IO;
IO.open("file.txt", ios::in | ios::out);
```

Open modifiers:
 - `ios::app` - append
 - `ios::ate` - go to end of file
 - `ios:binnary` - write in binary
 - `ios::in` - input
 - `ios::out` - output
 - `ios::trunc` - overwrite

```cpp
// check read success
bool valid = !!IO;
bool value = !IO.fail();
```

Error modifiers:
 - `ios::eofbit` - end of file
 - `ios::failbit` - failed
 - `ios::hardfail` - failed w/o recovery
 - `ios::badbit` - invalid operation
 - `ios::goodbit` - no bits set

Member functions:
 - `eof()` - if end of file
 - `fail()` - if T: failbit or F: hardbit
 - `bad()` - if badbit
 - `good()` - if goodbit
 - `clear()` - clear flags

```cpp
getline(IO, ln, '\t'); // get line upto delim

char ch;
IO.get(ch); // get next char
IO.put(ch); // write next char

IO.read(&ch, sizeof(ch)); // get next up to size
IO.write(&ch, sizeof(ch)); // write next up to size

int num = 0;
IO.read(reinterpret_cast<char*>&num, sizeof(num)); // read and cast from binary
IO.write(reinterpret_cast<char*>&num);// write binary to file
```

```cpp
file.seekg(25L, ios::beg); // set read pos to byte 26
file.seekp(-10L, ios::cur); // set write pos to 10 bytes before current pos
file.clear(); // clear eof
file.seekg(0L, ios::beg); // reset pos to begining of file
```

```cpp
long int rpos = file.tellg(); // get pos of input
long int wpos = file.tellp(); // get pos of output
```

## Classes

```cpp
class ClassName {

    private:
        int id;

    public:
        void method();
        void fin() const; // indicates that variable will not be modified

};
```

### Header
Contains type declarations
```cpp
// square.h
#ifndef SQUARE_H
#define SQUARE_H

class Square {

	private:
		double s;

	public:
		void setSize(double);

};

#endif
```

### Declarations
Contains implementations
```cpp
// square.cpp
#include "Square.h"; // load header declarations

void Square::setSize(double x) {
	s = x;
}
```

### Constructor
```cpp
class Rectangle {

    private:
        double w, h;

    public:
        // default constructor
        Rectangle() : Rectangle(0, 0) { /* additional code */ } // delegation (aka super))
        Rectangle(double); // overloading
        Rectangle(double, double);
        ~Rectangle(); // destructor, runs right before cleared from memory; no args or return allowed

};

Rectangle::Rectangle(double w) {
    this->w = w;
    this->h = 0;
}

Rectangle r(10, 5); // initialization via constructor

Rectangle rs[1] = {Rectangle()}; // initialization in array

Rectangle rs[1] = {1}; // initialization by literal (only if one param)
```