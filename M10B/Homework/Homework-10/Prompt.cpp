/* ***************************************************************************************
* CS M10B - Object-Oriented C++ - CRN 30110 - Dak Washbrook
* =======================================================================================
* Write a program that asks the user for a file name and a string to search for. The
* program should search the file for every occurrence of a specified string. When the
* string is found, the line that contains it should be displayed. After all the
* occurrences have been located, the program should report the number of times the string
* appeared in the file.
*************************************************************************************** */

#include "Prompt.h"

/* **********************************************************
Prompt class definitions
*********************************************************** */

/* **********************************************************
* string ask(question, verify) - This function accepts a
string as input and optionally a second parameter
bool static function to verify if the passed string is
okay or not.
*********************************************************** */
string Prompt::ask(string question, bool(*verify)(string)) {
	string answer;
	do {
		cout << question << ": ";
		getline(cin, answer);
	} while (!verify(answer));
	return answer;
}


/* **********************************************************
* bool default(any) - This function is just a default bool
function that always returns true. This allows there to
be no second parameter passed to the ask function if
verification is not needed.
*********************************************************** */
bool Prompt::default(string any) {
	return true;
}