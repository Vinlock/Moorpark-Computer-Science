#include "Prompt.h"


Prompt::Prompt()
{
}


string Prompt::ask(string question, bool(*verify)(string)) {
	string answer;
	do {
		cout << question << ": ";
		getline(cin, answer);
	} while (!verify(answer));
	return answer;
}

bool Prompt::default(string any) {
	return true;
}
