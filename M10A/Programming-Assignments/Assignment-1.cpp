/* ****************************************************************************************************
Dak Washbrook
This program calculates the number of boxes required to ship X number of widgets to a customer. 
Have your program prompt the user for the number of widgets ordered. The maximum number of widgets
that can be shipped in a box is 16.  Your program should then calculate the number of full boxes that
will be shipped to the customer and the number of widgets in the last box if the number of widgets
isn't evenly divisible by 16.  You can assume the user will enter in a value between 1 and 15,999.
**************************************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

	// Declare the variables for the number of widgets and boxes.
	int widgets, boxes, extra;

	// Prompt user for the number of widgets ordered and store it into the widgets variable.
	cout << "Number of widgets ordered? ";
	cin >> widgets;

	// Error handling if user inputs a number less than 1 or greater than 15999.
	while (widgets > 15999 || widgets < 1) {
		cout << endl << "You have entered an invalid amount of widgets! Please enter a number between 1 and 15,999." << endl << endl;
		cout << "Number of widgets ordered? ";
		cin >> widgets;
	}

	// Check if even amount, divisable by 16.
	if (widgets % 16 == 0) {
		// Find the number of boxes.
		boxes = widgets / 16;
		// Output the number of boxes in the correct format.
		cout << "Number of boxes shipped with " << setfill('0') << setw(2) << widgets << " widget(s): " << setw(3) << boxes << endl;
	}
	else {
		// Find the number of boxes.
		boxes = widgets / 16;

		if (boxes > 0) {
			// Output the number of boxes in the correct format.
			cout << "Number of boxes shipped with " << setfill('0') << setw(2) << "16 widget(s): " << setw(3) << boxes << endl;
		}

		// Find the number of extra widgets.
		extra = widgets % 16;

		// Output the number of extra widgets in the last box in the correct format.
		cout << "Number of boxes shipped with " << setfill('0') << setw(2) << extra << " widget(s): " << setw(3) << "001" << endl;
	}

	return 0;

}
