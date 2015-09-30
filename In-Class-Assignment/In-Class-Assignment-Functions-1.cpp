// This program asks the user if they want to find the lowest of three numbers or if a number is prime or not.
// Dak Washbrook

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> 
#include <math.h>

using namespace std;

// Prototype lowestValue function.
int lowestValue(int num1, int num2, int num3);

// Prototype isPrime function;
bool isPrime(int num);

int main() {

	// Declare Constants for TERMINATE, Choice for first function, and Choice for Finding if prime.
	const int TERMINATE = 3, LOWEST_CHOICE = 1, PRIME_CHOICE = 2;

	// Declare all integer variables that will be used.
	int choice, val1, val2, val3, primeTest;


	do {
		// Output menu to user.
		cout << "Choose One." << endl << "1) Find Lowest Value of three numbers." << endl << "2) Find if Prime Number." << endl << "3) END PROGRAM" << endl;
		do {
			// Prompt user to choose one.
			cout << endl << "Enter Choice: ";
			cin >> choice; // Store user choice into 'choice'

			// Error Handling
			if (choice < LOWEST_CHOICE || choice > TERMINATE) {
				cout << "Invalid Input" << endl << endl;
			}
			// Clear if Terminated
			else if (choice == TERMINATE) {
				system("CLS");
			}
		} while (choice < LOWEST_CHOICE || choice > TERMINATE);

		// If one of the non-terminate choices were chosen, prompt for input and run functions.
		if (choice == PRIME_CHOICE || choice == LOWEST_CHOICE) {
			// If First Choice, prompt for three integers and then find the lowest value.
			if (choice == 1) {
				cout << "Enter First Integer: ";
				cin >> val1;
				cout << endl;
				cout << "Enter Second Integer: ";
				cin >> val2;
				cout << endl;
				cout << "Enter Third Integer: ";
				cin >> val3;
				cout << endl << endl << "The Lowest Number of those three values are: " << lowestValue(val1, val2, val3);
			}
			// If Second Choice, prompt for an integer, find if its a prime number.
			else if (choice == 2) {
				cout << "Enter an Integer: ";
				cin >> primeTest;
				if (isPrime(primeTest)) {
					cout << primeTest << " is a Prime Number.";
				}
				else {
					cout << primeTest << " is NOT a Prime Number.";
				}
			}
			// Prompt user to press 'Enter' to continue back to the menu.
			cout << endl << "Press 'Enter' to go back to the menu..." << endl;
			cin.get();
			cin.ignore();
			system("CLS");
		}
	} while (choice != TERMINATE);

		if (choice == TERMINATE) {
			cout << "Program Terminated" << endl;
		}

	return 0;
}

int lowestValue(int num1, int num2, int num3) {
	// Check if num1 is lowest.
	if (num1 < num2 && num1 < num3) {
		return num1;
	}
	// Check if num2 is lowest.
	else if (num2 < num1 && num2 < num3) {
		return num2;
	}
	// Check if num3 is lowest.
	else if (num3 < num1 && num3 < num2) {
		return num3;
	}
}

bool isPrime(int num)
{
	if (num <= 1) {
		return false;
	}
	else if (num == 2) {
		return true;
	}
	else if (num % 2 == 0) {
		return false;
	}
	else
	{
		bool prime = true;
		int divisor = 3;
		double num_d = static_cast<double>(num);
		int upperLimit = static_cast<int>(sqrt(num_d) + 1);

		while (divisor <= upperLimit)
		{
			if (num % divisor == 0)
				prime = false;
			divisor += 2;
		}
		return prime;
	}
}
