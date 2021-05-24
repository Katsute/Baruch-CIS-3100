#include <iostream>
using namespace std;

/*
    Create a structure called Courses that holds the name of a course
    (call the variable courseName) and a variable that holds the score
    (out of 100) for that course (call this variable score).
*/
struct Courses {
    string courseName;
    int score;

    Courses& operator[](int s) {

    }
};

/*
    Create a class called Student. It should include a variable studentName 
    and a pointer to Courses called ptrCourses. This pointer is used to 
    dynamically create an array of Courses objects for each student. The size 
    of this array should be based on how many courses the student has taken. 
    Store the number of courses for each student as a member variable numCourses. 
    Spaces are permitted in course name and student name. Student class should 
    also have a studentID variable that is automatically generated in ascending 
    order for each student. The studentID should have a format of 5 digits i.e., 
    the first studentID must start with 10000 (which goes up to a maximum of 99999).
    All variables in the class must be private and all functions must be public.
*/

static int id = 0;

class Student {

    private:
        string studentName;
        Courses& ptrCourses;
        int numCourses;

        int studentId;

    public:
        Student(string studentName, const int numCourses) {
            this->studentName = studentName;
            this->numCourses = numCourses;
            this->ptrCourses = Courses[numCourses];
            static int no = 10000;
            studentId = no++;
        }

};

/*
    Create a program that declares an array of Student class of size 10. 
    The user should enter all the details of each student in the array. 
    For each student, the user should enter the studentName and then the 
    course details (course name and score) for as many courses as needed. 
    The program should ask for the number of courses taken by the student. 
    The program should always prompt the user and ask if more courses need 
    to be added for the student. Once the data entry is complete the program 
    should find the top three scores and show student name, course name and 
    the score for each of the top three scores.
*/
int main()
{
    Student student[10] = {};

    for (int i = 0; i < 10; i++) {
        // student loop
        int cno;
        cout << "Courses#:";
        cin >> cno;
        cout << endl;
        for (int x = 0; x < cno; x++) { // use may ask for more -> replace with do-while loop
            // courses loop

        }
    }

    // for each student, iterate through courses & keep top 3 scores
}

