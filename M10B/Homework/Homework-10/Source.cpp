#include "StringSearch.h"
#include "Prompt.h"

int main() {
	Prompt prompt;
	StringSearch search;

	search.setFilename(prompt.ask("Enter the filename", StringSearch::exists));
	search.setQuery(prompt.ask("String to search for"));

	search.search();

	return 0;
}