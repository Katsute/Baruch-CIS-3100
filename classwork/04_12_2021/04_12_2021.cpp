#include <iostream>
using namespace std;

int main(){
	int num;
	int* ptr = &num; // &num refers to the address for that variable, *ptr points to the address in memory

	int* nptr = nullptr; // instantiate a null pointer to address 0

	// array address refers to the first number in the array (there are no arrays in memory)

	int vals[] = { 4, 7, 11 };
	cout << *vals; // returns 4 (the first element)

	int* valptr = vals;
	cout << valptr[1]; // returns 7 (the element at index 1); standard array syntax

	// array addresses are ordered, so you can increase to get next value up to the size
	cout << *(valptr + 1); // returns 7 (pointer points to first element, +1 points to next element)

	// pointer arithmetic
	
	valptr--; // -1, points to 4 (first element)
	valptr++; // +1, points to 7 (next element)

	valptr += 1;
	valptr -= 1;

	// pointer must corrospond to same datatype, int*, double*, float*
}
