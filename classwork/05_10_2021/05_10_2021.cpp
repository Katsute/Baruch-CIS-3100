#include <iostream>
using namespace std;

class Obj {

	private:
		static const int v = 0; // static variable

		int a;
		int *aptr;

	public:
		static int getV(); // static method

		void print(int); // prototype

		Obj();

		Obj(int a) { // issue with copy:
			this->a = a;
			aptr = &a; // copy will use same pointer when it shouldn't
		}

		Obj(const Obj& obj) { // copy constructor
			a = obj.a; // on copy instead create a new address for copied pointers
			aptr = &a;
		}
};

class Other {

	private:
		static int c;

		friend class Obj; // allow 'Obj' class to access private members of 'Other'

		friend void Obj::print(int); // allow 'Obj#print' method to access private members of 'Other'

};

int Obj::getV() {
	return v;
}

void Obj::print(int a) {
	cout << Other::c;
}

int main() {
	cout << Obj::getV(); // access static method

	Obj a;
	Obj b = a; // copy
	
	b = a;
}
