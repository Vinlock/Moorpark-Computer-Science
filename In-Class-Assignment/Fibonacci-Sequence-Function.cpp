/* This program outputs the Fibonacci Sequence 10 times after 1 1.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void fib(int& int1, int& int2);

int main() {

	int fib1 = 1, fib2 = 1;

	for (int i = 0; i <= 10; i++) {
		fib(fib1, fib2);
		cout << fib2 << " ";
	}

	return 0;
}

void fib(int& int1, int& int2) {
	int var = int1 + int2;
	int1 = int2;
	int2 = var;
}
