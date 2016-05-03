#include "StringSearch.h"



StringSearch::StringSearch() {
	this->filename = "";
	this->query = "";
	this->occurences = 0;
}

StringSearch::StringSearch(string filename, string query) {
	this->filename = filename;
	this->query = query;
	this->occurences = 0;
}

void StringSearch::read() {
	this->file.open(this->filename, ios::in);
}

void StringSearch::close() {
	this->file.close();
}

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
	cout << endl << "The queried string occurred: " << this->occurences << " times." << endl;
}

void StringSearch::setFilename(string filename) {
	this->filename = filename;
}

bool StringSearch::exists(string filename) {
	ifstream ifile(filename);
	if (!ifile.good()) {
		cout << endl << "File does not exist. Please try again." << endl << endl;
	}
	return ifile.good();
}

void StringSearch::setQuery(string query) {
	this->query = query;
}