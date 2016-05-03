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
#include "Prompt.h"

int main() {
	// Instantiate the Prompt class
	Prompt prompt;
	
	// Instantiate the String Search class
	StringSearch search;

	// Ask the user for the filename and verify that it exists.
	search.setFilename(prompt.ask("Enter the filename", StringSearch::exists));

	// Ask the user for the string to search for.
	search.setQuery(prompt.ask("String to search for"));

	// Do the search.
	search.search();

	return 0;
}