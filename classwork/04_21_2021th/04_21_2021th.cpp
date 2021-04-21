#include <iostream>
#include <string>
using namespace std;
// Write the structure declaration here to hold the movie data.
struct Movie {

    string name, director, producer;
    int year;

};

int main()
{
    // define the structure variable here.
    Movie movie = {};

    cout << "Enter the following data about your\n";
    cout << "favorite movie.\n";
    cout << "name: ";
    // Write a statement here that lets the user enter the
    // name of a favorite movie. Store the name in the
    // structure variable.
    getline(cin, movie.name);

    cout << "Director: ";
    // Write a statement here that lets the user enter the
    // name of the movie's director. Store the name in the
    // structure variable.
    getline(cin, movie.director);

    cout << "Producer: ";
    // Write a statement here that lets the user enter the
    // name of the movie's producer. Store the name in the
    // structure variable.
    getline(cin, movie.producer);

    cout << "Year of release: ";
    // Write a statement here that lets the user enter the
    // year the movie was released. Store the year in the
    // structure variable.
    cin >> movie.year;

    cout << "Here is data on your favorite movie:\n";
    // Write statements here that display the data.
    // just entered into the structure variable.
    cout <<
        "Movie: " << movie.name << endl <<
        "Director: " << movie.director << endl <<
        "Producer: " << movie.producer << endl <<
        "Year of release: " << movie.year << endl;

    return 0;
}