#include <iostream>
using namespace std;

// prototype
void incr(int);
void decr(int&);
void staincr();
void def(int a = 0);

// pass by value
void incr(int v) {
	cout << ++v << endl;
}

// pass by reference
void decr(int& v) { // can also be (int &v)
	cout << --v << endl;
}


// global constants

const int pi = 3.14;

// static

void staincr() {
	static int sn; // will retain value across all function calls
	cout << ++sn << endl;
}

// default args, must be placed after nondef args
// can also be set in prototype
void def(int a = 0) {
	cout << a << endl;
}

int main()
{
	{
		int val = 5;
		incr(val);
		cout << val << endl;
	}
	cout << "----" << endl;
	{
		int val = 5;
		decr(val);
		cout << val << endl;
	}
	cout << "----" << endl;
	staincr();
	staincr();
	cout << "----" << endl;
	def();

	return 0;
}


