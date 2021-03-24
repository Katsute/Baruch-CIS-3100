#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 10;

void arrayConversion(int[SIZE], float[SIZE]);

int main(){
    /* 1.
       In main, declare an integer array of size 10 and call it 
       studentID and declare a float array of size 10 and call it 
       studentGPA. The same index in both arrays represent the 
       same student e.g., studentID[2] and studentGPA[2] are ID 
       and GPA for the same student respectively.
    */
    int studentID[SIZE] = {};
    float studentGPA[SIZE] = {};
    /* 2.
       Prompt user to enter all the elements of studentID and 
       studentGPA. Make sure you provide a prompt "Please enter 
       ID for student #: " (where # represents the index + 1 and 
       index starts from 0) and "Please enter grade for student 
       #: ".  Negative numbers should not be allowed. GPA should 
       be less than or equal to 4. In case of an invalid entry 
       the program should ask the user to enter it again.
    */
    for (int i = 0; i < SIZE; i++) {
        int index = i + 1;
        int ID;
        float GPA;
        do {
            cout << "Please enter ID for student " << index << ": " << endl;
            cin >> ID;
        } while (ID <= 0);

        do {
            cout << "Please enter grade for student " << index << ": " << endl;
            cin >> GPA;
        } while (GPA <= 0 || GPA > 4);
        studentID[i] = ID;
        studentGPA[i] = GPA;
    }
    /* 3.
       Create a search loop that prompts the user "Please enter 
       the student ID to search (-1 to exit): " to enter an integer 
       value and the program searches for that value in the studentID 
       array. If student is found then the program should display 
       the GPA of the student as shown: "Student GPA:  x.xx" 
       (where x.xx indicates the GPA of the student from studentGPA
       array in floating point format with two decimal point). 
       If not found the program should display: "Student not found.". 
       The loop should continue prompting the user and asking for 
       student ID to search until the user enters -1.
    */
    int ID = 0;
    do {
        cout << "Please enter the student ID to search (-1 to exit): " << endl;
        cin >> ID;
        if (ID <= -1)
            break;
        else {
            cout << fixed << setprecision(2);
            bool found = false;
            int index = 0;
            for (int sid : studentID) {
                if (sid == ID) {
                    found = true;
                    break;
                }
                index++;
            }
            if (!found)
                cout << "Student not found." << endl;
            else
                cout << "Student GPA: " << studentGPA[index] << endl;
        }
    } while (ID > -1);
    // 4.
    arrayConversion(studentID, studentGPA); 
}

/* 4.
   Create a function called arrayConversion that takes the 
   above-mentioned two arrays as parameters. The function should 
   copy the contents of the two arrays into a two-dimensional 
   array with 2 rows and 10 columns. The two-dimensional array 
   should be declared locally. Your program should also create a 
   function protype for this function and call this function at 
   the end of search loop mentioned in point 3 earlier.
*/
const int ROW = 2;
const int COL = SIZE;

void arrayConversion(int arr1[], float arr2[]) {
    float asFloat[SIZE] = {};
    for (int i = 0; i < SIZE; i++)
        asFloat[i] = arr1[i];

    float arr2dim[ROW][COL] = {};
    for (int r = 0; r < ROW; r++)
        for (int c = 0; c < COL; c++)
            arr2dim[r][c] = (r == 0 ? asFloat : arr2)[c];

    // check
    for (float v : arr2dim[0])
        cout << v << ' ';
    cout << endl;
    for (float v : arr2dim[1])
        cout << v << ' ';
}