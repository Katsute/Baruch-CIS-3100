#include <iostream>
#include <fstream>  // file I/O
using namespace std;

// C++ reads top down, so functions must be declared before main, either directly or with a prototype method.
void voidFunction();
int parameterFunction(int);

int main()
{
	// ifstream // input file
	{
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
	}
	// ofstream // output file
	{
		ofstream outfile;
		outfile.open("file.txt");

		// write (OVERWRITES EXISTING CONTENT)
		outfile << "new string" << "; ";
		outfile << "another string on the same line";

		outfile.close(); // prevent memory leak
	}
	// fstream // file I/O
	{
		fstream iofile;
	}

	voidFunction();
	cout << endl << parameterFunction(1);


	return 0;
}

// declare above functions

void voidFunction() {

}

int parameterFunction(int param) {
	return param;
}
