#include <iostream>
using namespace std;

void arr(int[], int);

void tarr(int[][2], int);

int main()
{
	char chars[] = "chars"; // init char array with string
	cout << chars << endl;
	// char array length is one higher than string length, \0 (NUL) is added to end of all char arrays

	// for each loop
	cout << '_' << endl;
	for (char ch : chars)
		cout << ch << endl;
	cout << '_' << endl;

	// 2 dimensional array
	int tdarr[10][10];
}

// by default arrays are passed by reference
void arr(int arr[], int size) { // generally safer to also pass size into function arg

}

void tarr(int arr[][2], int size) { // in case of multi-dim arrays, all subsequent arrays must have a size

}