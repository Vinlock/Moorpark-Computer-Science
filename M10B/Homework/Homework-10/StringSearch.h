#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

class StringSearch
{
private:
	string filename;
	string query;
	fstream file;
	int occurences;

	void read();
	void close();

public:
	StringSearch();
	StringSearch(string, string);
	void search();
	void setFilename(string);
	void setQuery(string);
	static bool exists(string);
};
