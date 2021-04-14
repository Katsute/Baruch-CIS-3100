#include <iostream>
using namespace std;

void cs(double*);

int* newInt();

int main(){
	int value = 10;
	int* const ptr = &value; // constant pointer (cannot be reassigned)

	double* dptr = nullptr;
	dptr = new double; // allocate new address in memory for datatype

	// use delete for dynamic memory only

	delete dptr; // delete allocated memory (pointer will point to nonexistent address)

	int arr[10];
	delete[] arr; // delete array allocation
}

// constant pointer (cannot be reassigned)
void cs(const double *ptr) { }

// return pointer, must not be a pointer to a variable inside the function (address is cleared after function) unless static
int* newInt() {
	return new int;
}