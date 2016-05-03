/* ***************************************************************************************
* CS M10B - Object-Oriented C++ - CRN 30110 - Dak Washbrook
* =======================================================================================
* Write a program that asks the user for a file name and a string to search for. The
* program should search the file for every occurrence of a specified string. When the
* string is found, the line that contains it should be displayed. After all the
* occurrences have been located, the program should report the number of times the string
* appeared in the file.
*************************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* **********************************************************
StringSearch class declarations.

* See StringSearch.cpp for class definitions.
*********************************************************** */

class StringSearch {
private:
	string filename;
	string query;
	fstream file;
	int occurences;

	void read();

public:
	StringSearch();
	StringSearch(string, string);
	void search();
	void setFilename(string);
	void setQuery(string);
	static bool exists(string);
};
