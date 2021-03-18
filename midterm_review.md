# TOC

- [File Structure](#file-structure)
- [Console I/O](#console-io)
  - [Stream Manipulators](#stream-manipulators)
  - [Stream](#stream)
- [Variables](#variables)
  - [Datatypes](#datatypes)
  - [Casting](#casting)
  - [Multiple Assignment](#multiple-assignment)
  - [String](#string)
  - [Random](#random)
  - [Boolean](#boolean)
  - [Incrementals](#incrementals)
  - [Constants](#constants)
- [Control Structures](#control-structures)
  - [Switch Case](#switch-case)
  - [Loops](#loops)
- [File I/O](#file-io)
- [Functions](#functions)
  - [Static Variables](#static-variables)
  - [Defaults](#defaults)
- [Memory](#memory)

## File Structure

```cpp
#include <iostream> // import
using namespace std; // static import

int main(){

    return 0;
}
```

## Console I/O

```cpp
int number;
cin >> x; // casts to declaration type

cout << "number: " << x << endl;
```

### Stream Manipulators

```cpp
cout << set(4); // set minimum width for columns
cout << setprecision(4); // set amount of places to display (not ints);
cout << right; // set alignment
```

### Stream

```cpp
string ln;
getline(cin, ln); // read full line

char ch;
cin >> ch; // ignores whitespace
cin.get(ch); // allows all characters

cin.ignore(); // skip input
cin.ignore(10, '\n'); // skip next 10 or until newline
```

## Variables

### Datatypes

```cpp
long double ld = 10.2;
double d = 10.2;
float f = 10.2;
unsigned long ul = -10.2; // unsigned accepts only positives; negatives wraps around to max value
long l = 10.2;
unsigned int ui = -10.2; // wraps aroung to max int
int i = 10.2; // truncates decimals

char c = 10.2;
short s = 10.2;
unsigned short us = -10.2; // wraps around
```

### Casting

```cpp
double x = 10.2;
int i;
i = static_cast<int>(d); // preferred
i = int(d);
i = (int) d;
```

### Multiple Assignment
```cpp
int x, y, z;
x = y = z = 5; // process from left to right
x = (y = (z = 5));
```

### String

```cpp
#include <string>

...

string str = "string";
int size = str.length(); // length
str += "concat"; // concatenation
```

### Random

```cpp
#include <cmath>

...

srand(seed); // set seed (by default same seed is used)
cout << rand();
```

### Boolean

```cpp
bool t = true;
bool f = false;
// operators: > < >= <= == !=

bool value = condition ? true : false; // ternary operator
```

### Incrementals

```cpp
// the difference betwene prefix and postfix is the order
int val = 0;
int x = 0;

x = val++; // same as x = val; val = val + 1;
// x = 0
// val = 1

x--;
val--;

x = ++val; // same as val = val + 1; x = val;
// x = 1
// val = 1
```

### Constants

```cpp
const double pi = 3.14;
```

## Control Structures

### Switch Case

```cpp
switch (1) {
    case 1:
        // run this only
        break; // exit switch
    case 2:
        // run this and below
        ;
    case 3:
        // run this and below
        ;
    default:
        // run if no cases met
        ;
}
```

### Loops

```cpp
for (int i = 0; i < 2; i++)
    cout << i;

int i = -1;
while (++i < 2) // while true do
    cout << i;

// do-while, execute at least once while condition
i = 0;
do
    cout << i;
while (++i < 1);
```

## File I/O

**IN**
```cpp
#include <fstream>

...

ifstream infile;
infile.open("file.txt");

// check file existance (infile as a bool)
cout << (infile ? "file exists!" : "file doesn't exist") << endl;
cout << (infile.fail() ? "file doesn't exist" : "file exists!") << endl;

// read word by word
string buffer;
while (infile >> buffer)
    cout << buffer << ' ';

infile.close(); // prevent memory leak
```

**OUT**
```cpp
#include <fstream>

...

ofstream outfile;
outfile.open("file.txt");

// write (OVERWRITES EXISTING CONTENT)
outfile << "new string" << "; ";
outfile << "another string on the same line";

outfile.close(); // prevent memory leak
```

**I/O**
```cpp
#include <fstream>

...

fstream iofile;
```

## Functions

```cpp
// function or prototype must be declared before the main in order to be used
void voidFunction();
int parameterFunction(int);

...

void Function(){

}


int parameterFunction(int param){
    return param;
}
```

### Static Variables

```cpp
void staticincr(){
    static int i; // will retain its value across multple calls
    cout << ++i;
}
```

### Defaults

```cpp
void def(int a = 0){ // default values, must be after all non-default values
    cout << a;
}
```

## Memory

```cpp
// be default pass by value
void incr(int v){
    cout << ++v;
}

// pass by reference with &
void incr(int& v){
    cout << ++v;
}

void incr(int &v){
    cout << ++v;
}
```