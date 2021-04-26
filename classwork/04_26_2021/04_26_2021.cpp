#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    fstream IO;
    IO.open("file.txt", ios::in | ios::out);

    // ios::app - append
    // ios::ate - go to end of file
    // ios::binary - written in pure binary // write/read using binary values instead of char/string/num
    // ios::in - input
    // ios::out - output
    // ios::trunc - replace existing

    bool valid = !!IO || !IO.fail();

    // always pass by ref

    // error testing:
    // ios::eofbit - end of file
    // ios::failbit - failed
    // ios::hardfail - failed w/o recovery
    // ios::badbid - invalid operation
    // ios::goodbit - no bits set

    // member functions
    // eof() - end of file
    // fail() - either T: failbit or F: hardbit
    // bad() - badbit
    // good() - goodbit
    // clear() - clear flags

    string ln;
    getline(IO, ln, '\t'); // delim

    char ch;
    IO.get(ch);
    IO.put(ch);

    // read/write
    IO.read(&ch, sizeof(ch)); // read to char up to certain index
    IO.write(&ch, sizeof(ch)); // write to file up to index in char

    int num = 0;
    IO.read(reinterpret_cast<char*>&num, sizeof(num)); // read and cast from binary
    IO.write(reinterpret_cast<char*>&num);// write binary to file
}
