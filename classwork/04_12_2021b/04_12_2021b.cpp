#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char ch = 'c';
    cout << isalpha(ch); // is alphabetic
    cout << isalnum(ch); // is alphanumeric
    cout << isdigit(ch); // is digit
    cout << islower(ch); // is lower case
    cout << isprint(ch); // is printable
    cout << ispunct(ch); // is puncuation
    cout << isupper(ch); // is upper case
    cout << isspace(ch); // is whitespace

    cout << toupper(ch); // to upper case

    string str = "string"; // null terminator character array
    char chars[7] = { 's', 't', 'r', 'i', 'n', 'g' , '\0' }; // length is string length + 1 for \0 null delim

    cout << strlen(chars); // return length of string (w/o \0 null delim)
    cout << strcat(chars, chars); // concatenate
    cout << strcpy(chars, chars); // copy second to first
    cout << strstr(chars, chars); // find second in first (returns pointer to first index of match or NULL)
    cout << strcmp(chars, chars); // returns diff (int) based on ascii code
}
