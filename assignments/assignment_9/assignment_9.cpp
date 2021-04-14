#include <iostream>
#include <cctype>
using namespace std;

int validatePassword(string str);

int main() {
	string pwd;
	bool valid = false;
	do {
		cout << "Enter password: ";
		cin >> pwd;
		switch (validatePassword(pwd)) {
			case 0:
				valid = true;
				break;
			case 1:
				cout << "Password is too short" << endl;
				break;
			case 2:
				cout << "Password is missing an uppercase or lowercase character" << endl;
				break;
			case 3:
				cout << "Password is missing a number" << endl;
				break;
		}
	} while (!valid);
}

int validatePassword(const string str) {
	if (str.length() < 8)
		return 1;

	bool containsUpper = false;
	bool containsLower = false;
	bool containsDigit = false;
	for (char ch : str) // for each char in str
		if (isupper(ch))
			containsUpper = true;
		else if (islower(ch))
			containsLower = true;
		else if (isdigit(ch))
			containsDigit = true;
		else if (containsUpper && containsLower && containsDigit)
			break; // skip if checks passed

	if (!containsUpper || !containsLower)
		return 2;
	else if (!containsDigit)
		return 3;
	else
		return 0;
}