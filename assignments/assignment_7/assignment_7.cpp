#include <iostream>
using namespace std;

void swap(int&, int&);
void bubbleSort(int[], int);

const int ROW = 5, COL = 9;

void flatten(int[ROW][COL], int[ROW*COL]);
void expand(int[ROW * COL], int[ROW][COL]);

int main(){
	int myArray[ROW][COL] = {};

	// populate
	int buffer;
	for(int row = 0; row < ROW; row++){
		for(int col = 0; col < COL; col++){
			cout << "[" << row << "][" << col << "]: ";
			cin >> buffer;
			myArray[row][col] = buffer;
		}
	}

	// search for min 
	int min = INT_MAX;
	for(int row = 0; row < ROW; row++)
		for(int col = 0; col < COL; col++)
			if(myArray[row][col] < min)
				min = myArray[row][col];
	cout << "Minimum value: " << min << endl;

	// sort
	int arr1dim[ROW * COL] = {};
	flatten(myArray, arr1dim); // flatten for sorting
	bubbleSort(arr1dim, ROW * COL); // osrt
	expand(arr1dim, myArray); // restore grid

	// display
	for (int row = 0; row < ROW; row++) {
		cout << "[";
		for (int col = 0; col < COL; col++) {
			cout << myArray[row][col];
			if(col < COL - 1)
				cout << ", ";
		}
		cout << "]" << endl;
	}
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int arr[], int size) {
	for(int maxElement = size - 1; maxElement > 0; maxElement--)
		for(int index = 0; index < maxElement; index++)
			if(arr[index] > arr[index + 1])
				swap(arr[index], arr[index + 1]);
}

// convert 2dim arr to single dim arr
void flatten(int arr[ROW][COL], int newArr[ROW * COL]) {
	int index = 0;
	for(int row = 0; row < ROW; row++)
		for(int col = 0; col < COL; col++)
			newArr[index++] = arr[row][col];
}

// convert single dim arr to 2dim arr
void expand(int arr[ROW * COL], int newArr[ROW][COL]){
	int index = 0;
	for (int row = 0; row < ROW; row++)
		for (int col = 0; col < COL; col++)
			newArr[row][col] = arr[index++];
}