#pragma once
#include <iostream>
#include <string>

using namespace std;

class Prompt
{
public:
	Prompt();
	string ask(string, bool(*)(string) = Prompt::default);
	static bool default(string = "");
};

