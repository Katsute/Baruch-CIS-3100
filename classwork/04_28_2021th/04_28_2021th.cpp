#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Movie {
	string name, director, producer;

	int year;
};

int main() {
	// define the structure variable here.
	Movie myMovie = {};

	cout << "Enter the following data about your\n";
	cout << "favorite movie.\n";
	cout << "name: ";

	// Write a statement here that lets the user enter the
	// name of a favorite movie. Store the name in the
	// structure variable.
	getline(cin, myMovie.name);
	cout << "Director: ";

	// Write a statement here that lets the user enter the
	// name of the movie's director. Store the name in the
	// structure variable.
	getline(cin, myMovie.director);
	cout << "Producer: ";

	// Write a statement here that lets the user enter the
	// name of the movie's producer. Store the name in the
	// structure variable.
	getline(cin, myMovie.producer);
	cout << "Year of release: ";

	// Write a statement here that lets the user enter the
	// year the movie was released. Store the year in the
	// structure variable.
	cin >> myMovie.year;
	cout << "Here is data on your favorite movie:\n";

	// Update the program and store the structure variable 
	// myMovie in a file and then read it back to a structure 
	// and display its contents in console output.
	fstream IO;
	IO.open("movie.txt", ios::in | ios::binary);
	IO.write(reinterpret_cast<char*>(&myMovie), sizeof(myMovie));
	IO.close();

	IO.open("movie.txt", ios::out | ios::binary);
	IO.read(reinterpret_cast<char*>(&myMovie), sizeof(myMovie));
	IO.close();

	// Write statements here that display the data
	// just entered into the structure variable.
	cout << myMovie.name << ", " << myMovie.director << ", ";
	cout << myMovie.producer << ", " << myMovie.year << endl;

	return 0;
}