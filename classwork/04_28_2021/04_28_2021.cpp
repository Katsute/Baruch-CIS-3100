#include <iostream>
#include <fstream>
using namespace std;

struct str {
    
    int id;

};

int main() {
    // read and write to structures
    str s;
    fstream file;
    file.open("file.txt", ios::in | ios::binary);
    file.write(reinterpret_cast<char*>(&s), sizeof(s));

    file.seekg(25L, ios::beg); // set read pos to byte 26
    file.seekp(-10L, ios::cur); // set write pos to 10 bytes before current pos
    file.clear(); // clear eof
    file.seekg(0L, ios::beg); // reset pos to begining of file

    long int rpos = file.tellg(); // get pos of input
    long int wpos = file.tellp(); // get pos of output
}

class ClassName {

    private:
        int id;

    public:
        void method();
        void fin() const; // indicates that variable will not be modified

};