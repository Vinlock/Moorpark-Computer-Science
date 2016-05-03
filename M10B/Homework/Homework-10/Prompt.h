#pragma once
#include <iostream>
#include <string>

using namespace std;

class Prompt {
public:
	string ask(string, bool(*)(string) = Prompt::default);
	static bool default(string = "");
};

