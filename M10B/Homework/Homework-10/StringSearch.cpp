/* ***************************************************************************************
* CS M10B - Object-Oriented C++ - CRN 30110 - Dak Washbrook
* =======================================================================================
* Write a program that asks the user for a file name and a string to search for. The
* program should search the file for every occurrence of a specified string. When the
* string is found, the line that contains it should be displayed. After all the
* occurrences have been located, the program should report the number of times the string
* appeared in the file.
*************************************************************************************** */

#include "StringSearch.h"


/* **********************************************************
Prompt class definitions
*********************************************************** */

/* **********************************************************
* Default Constructor - Defaults member variables.
*********************************************************** */
StringSearch::StringSearch() {
	this->filename = "";
	this->query = "";
	this->occurences = 0;
}

/* **********************************************************
* Non-Default Constructor - StringSearch(filename, query)
	This function defaults the member variables to the
	arguments passed. With the exception of occurences,
	which starts at 0.
*********************************************************** */
StringSearch::StringSearch(string filename, string query) {
	this->filename = filename;
	this->query = query;
	this->occurences = 0;
}

/* **********************************************************
* read() - This function opens the file into the file
	member variable. Allowing the object to use the file.
*********************************************************** */
void StringSearch::read() {
	this->file.open(this->filename, ios::in);
}

/* **********************************************************
* search() - This function searches the file for the
	requested query string. It tracks the number of
	occurences and outputs the lines and the line numbers
	that the string occurs on.
*********************************************************** */
void StringSearch::search() {
	this->read();
	cout << endl;
	int lineNum = 1;
	for (string line; !file.eof(); getline(this->file, line)) {
		if (line.find(this->query) != string::npos) {
			if (this->occurences == 0) {
				cout << "Lines containing the queried string:" << endl;
			}
			cout << "Line " << lineNum << ": " << line << endl;
			this->occurences++;
		}
		lineNum++;
	}
	cout << endl << "The queried string occurred in " << this->occurences << " lines of the file." << endl << endl;
}

/* **********************************************************
* setFilename(filename) - This function sets the filename member
	variable to the passed string argument.
*********************************************************** */
void StringSearch::setFilename(string filename) {
	this->filename = filename;
}

/* **********************************************************
* exists() [static] - This function checks if a file exists.
	It is used as a verification filter in the Prompt class.
*********************************************************** */
bool StringSearch::exists(string filename) {
	ifstream ifile(filename);
	if (!ifile.good()) {
		cout << endl << "File does not exist. Please try again." << endl << endl;
	}
	return ifile.good();
}

/* **********************************************************
* setQuery(query) - This function sets the query member
	variable to the passed string argument.
*********************************************************** */
void StringSearch::setQuery(string query) {
	this->query = query;
}