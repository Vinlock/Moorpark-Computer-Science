// Dak Washbrook - Intro to C++
// Programming Assignment 1
// This program displays a menu to the user, prompting them for input. Depending on the input it will generate mathmateical tables (addition, subtraction, multiplication, and division) starting and ending at the user chosen numbers.

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> 

using namespace std;

int main() {

	// Declare the variables for the table and the two integers that the user will choose.
	int userChosenTable = 0, integer1, integer2;

	// Declare the variable for the arithmatic sign.
	char type;

	// Constants for the Highest and Lowest Menu Choices
	const int MENU_TERMINATE_CHOICE = 5;
	const int MENU_LOWEST_CHOICE = 1;

	// Constants for the Highest and Lowest possible user inputted integers.
	const int INTEGER_HIGHEST_CHOICE = 12;
	const int INTEGER_LOWEST_CHOICE = 1;

	// Begin do loop to run once and check if 5 was entered.
	do {
		// Output Menu.
		cout << endl << "1) Print Addition Table" << endl << "2) Print Subtraction Table" << endl << "3) Print Multiplication Table" << endl << "4) Print Division Table" << endl << "5) End Program" << endl
			<< endl;
		// Do loop for a menu choice. Loop if an invalid choice is entered.
		do {
			// Prompt User to enter a choice from the menu.
			cout << "Enter Choice: ";
			// Fill 'userChosenTable' with their choice.
			cin >> userChosenTable;

			// If user enters an invalid choice then alert the user. Or if the choice is the terminate choice then clear and terminate.
			if (userChosenTable > MENU_TERMINATE_CHOICE || userChosenTable < MENU_LOWEST_CHOICE) {
				cout << endl << "Invalid Entry!" << endl << endl;
			}
			else if (userChosenTable == MENU_TERMINATE_CHOICE) {
				system("CLS");
			}

		} while (userChosenTable > MENU_TERMINATE_CHOICE || userChosenTable < MENU_LOWEST_CHOICE);

		// While 'userChoseTable' is not 5, prompt user for 2 integers.
		while (userChosenTable != MENU_TERMINATE_CHOICE) {

			// Do loop to prompt user for first integer.
			do {
				cout << "Enter an integer between 1 and 12 inclusive: ";
				cin >> integer1;

				// If user enters an invalid choice then alert the user.
				if (integer1 < INTEGER_LOWEST_CHOICE || integer1 > INTEGER_HIGHEST_CHOICE) {
					cout << endl << "Invalid Entry!" << endl << endl;
				}

			} while (integer1 > INTEGER_HIGHEST_CHOICE || integer1 < INTEGER_LOWEST_CHOICE);

			// Do loop to prompt user for second integer.
			do {
				cout << "Enter another integer between " << integer1 << " and 12 inclusive: ";
				cin >> integer2;

				// If user enters an invalid choice then alert the user.
				if (integer2 > INTEGER_HIGHEST_CHOICE || integer2 < integer1) {
					cout << endl << "Invalid Entry!" << endl << endl;
				}
			} while (integer2 > INTEGER_HIGHEST_CHOICE || integer2 < integer1);

			cout << endl;

			// Depending on user's menu choice, output the corresponding arithmetic symbol.
			switch (userChosenTable) {
			case 1: type = '+';
				break;
			case 2: type = '-';
				break;
			case 3: type = '*';
				break;
			case 4: type = '/';
				break;
			}

			// Output the arithmetic symbol in the table.
			cout << endl << setw(2) << type << " ";

			// Print all numbers between 'integer1' and 'integer2' for the top row.
			for (int top = integer1; top <= integer2; top++) {
				cout << setw(4) << top;
			}

			cout << endl;

			// Output the start of the second row separator.
			cout << "---";

			// Output the correct amount of dashes to evenly separate the top row from the table.
			for (int dash = 1; dash <= ((integer2 - integer1) * 4); dash = dash + 4) {
				cout << "-----";
			}

			cout << endl;

			// Generate the Table
			for (int i = integer1; i <= integer2; i++) {
				cout << setw(2) << i << "|";

				for (int j = integer1; j <= integer2; j++) {

					// Switch and Case to generate the correct table depending on what menu choice was chosen by the user.
					switch (userChosenTable) {
					case 1: cout << setw(4) << i + j;
						break;
					case 2: cout << setw(4) << i - j;
						break;
					case 3: cout << setw(4) << i * j;
						break;
					case 4: cout << setw(4) << i / j;
					}

				}

				cout << endl;

			}

			break;

		}
		if (userChosenTable != 5) {
			// Prompt user to press 'Enter' to continue back to the menu.
			cout << endl << "Press 'Enter' to go back to the menu..." << endl;
			cin.get();
			cin.ignore();
			system("CLS");
		}
	} while (userChosenTable != MENU_TERMINATE_CHOICE);

	// Once the user terminates the program. Alert the user that the program has been terminated and end program.
	if (userChosenTable == MENU_TERMINATE_CHOICE) {
		cout << "Program Terminated" << endl;
	}

	return 0;
}
