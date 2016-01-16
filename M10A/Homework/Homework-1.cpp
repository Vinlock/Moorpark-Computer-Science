// This program gives you the square of the integer entered.
#include <iostream>
using namespace std;

int main()
{
	// Declare that the numberEntered will be an integer
	int numberEntered;
	int square;

	// Get the number
	cout << "Enter the number that you would like to have squared: ";
	cin >> numberEntered;

	// Square the number
	square = numberEntered * numberEntered;

	// Display the square
	cout << "The square of " << numberEntered << " is " << square << endl;

	return 0;
}
