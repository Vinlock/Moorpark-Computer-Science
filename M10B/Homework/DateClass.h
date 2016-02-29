#pragma once
#include <string>
#include <sstream>
#include <iostream>

/* **********************************************************************
	Date Object
********************************************************************** */
class Date {

private:
	// Define Private Variables
	int month;
	int day;
	int year;

	const std::string MONTHS[12] = {
		"January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December"
	};

	int choice;		// User's choice of date format.

	// Enumerator for Months
	enum Months;

	class InvalidDay;		// Invalid Day Exception Class
	class InvalidMonth;		// Invalid Month Exception Class
	class InvalidChoice;	// Invalid Choice Exception Class

public:
	// Print Date
	std::string GetShortDate();		// Get Date Format 12/25/2015
	std::string GetLongDate();		// Get Date Format December 25, 2015
	std::string GetForeignDate();	// Get Date Format 25 December 2015
	void PrintDate();				// Print the Date Format Chosen.

	// Set Variable Functions
	void setMonth(int month);		// Set the private variable 'month'
	void setDay(int day);			// Set the private variable 'day'
	void setYear(int year);			// Set the private variable 'year'
	void setChoice(int choice);		// Set the chosen date format variable 'choice'

	// Ask Functions
	void AskMonth();				// Ask the user for the month. (1-12)
	void AskDay();					// Ask the user for the day. (1-31)
	void AskYear();					// Ask the user for the year.
	void ChooseFormat();			// Ask the user for the date format. (1-3)

};

