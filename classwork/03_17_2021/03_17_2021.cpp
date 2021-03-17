#include <iostream>
using namespace std;

int garr[5]; // default init 0

int main()
{
    // array
    int tests[5]; // fixed length // default init NULL

    const int SIZE = 5;
    int test5[SIZE]; // fixed length via constant

    int nums[7] = { 1, 2, 3, 4 }; // init with less only and rest use default

    nums[0]++; // num[0] = num[0] + 1;

    // exit
    exit(EXIT_SUCCESS);
    exit(EXIT_FAILURE);
}
