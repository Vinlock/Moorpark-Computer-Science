#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>

using namespace std;

class Palindrome {

private:
	string text;	// String variable to hold the user inputted string of text to test.

public:
	bool Check(string text, unsigned int place = 0) {
		/* ************************************
		This function checks if the text string
		is a Palindrome or not.
		Returns true if it is, false if not.
		************************************ */
		if (place == 0) {
			/*
			If it is the first depth of recursion, filter all
			non-alphabet characters out of the string.
			*/
			for (unsigned int i = 0; i < text.length(); i++) {
				char c = text[i];
				if (!isalpha(c)) {
					text.erase(text.begin() + i);
					i--;
				}
			}
		}
		// Set len to the length of the new string.
		unsigned int len = text.length();
		if (place >= len / 2) {
			/*
			If place is already reached an integer that is greater than
			or equal to half the string length, return true since it is
			a Palindrome.
			*/
			return true;
		}
		else {
			char a = text.at(place);			// Set a to the current string place from the beginning of the string.
			char b = text.at(len - 1 - place);	// Set b to the current string place from the end of the string.
			if (tolower(a) == tolower(b)) {		// Compare a and b.
				if (!Check(text, place + 1)) {	// If a == b, continue recursion.
					return false;				// If any recursion returns false, the rest of the stack will return false.
				}
			}
			else {
				// If a ever does not equal b, this will return false and cause the rest of the stack to return false.
				return false;
			}
		}
	}

	void AskUser() {
		/* ************************************
		This function asks the user to input
		a string to be checked.
		It will continually ask for new strings
		until the user inputs nothing and 
		presses enter.
		************************************ */
		do {
			cout << "Please input a string: ";
			getline(cin, this->text);
			if (this->Check(this->text) && this->text != "") {
				cout << "The string entered is a Palindrome." << endl;
			}
			else if (!this->Check(this->text)) {
				cout << "The string entered is not a Palindrome" << endl;
			}
			else {
				return;
			}
		} while (this->text != "");
	}

};

int main() {

	Palindrome test;	// Initialize the class object.

	test.AskUser();		// Run the AskUser() function to begin the program.

	return 0;
}
