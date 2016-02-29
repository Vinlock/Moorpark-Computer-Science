#include "DateClass.h"

/* **********************************************************************
	Enumerator for the valid months.
********************************************************************** */
enum Date::Months {
	JANUARY = 0,
	FEBRUARY = 1,
	MARCH = 2,
	APRIL = 3,
	MAY = 4,
	JUNE = 5,
	JULY = 6,
	AUGUST = 7,
	SEPTEMBER = 8,
	OCTOBER = 9,
	NOVEMBER = 10,
	DECEMBER = 11
};

/* **********************************************************************
	Invalid Day Exception Class.
	Handles the Exception if a day less than 1 or greater than 31 is
	entered.
********************************************************************** */
class Date::InvalidDay {
private:
	std::string errors[2] = {
		"The entered day is too low. Please enter a day between 1 and 31.",
		"The entered day is too high. Please enter a day between 1 and 31."
	};

public:
	InvalidDay(int err_code) {
		std::cout << this->errors[err_code] << std::endl;
	}

};

/* **********************************************************************
	Invalid Month Exception Class.
	Handles the Exception if a month less than 1 or greater than 12 is
	entered.
********************************************************************** */
class Date::InvalidMonth {
private:
	std::string errors[2] = {
		"The entered month is too low. Please enter a month between 1 and 12.",
		"The entered month is too high. Please enter a month between 1 and 12."
	};

public:
	InvalidMonth(int err_code) {
		std::cout << this->errors[err_code] << std::endl;
	}
};

/* **********************************************************************
	Invalid Date Format Choice Exception Class.
	Handeles the Exception if a choice less than 1 or greater than 3 is
	entered.
********************************************************************** */
class Date::InvalidChoice {
private:
	std::string errors[1] = {
		"You have entered an invalid choice. Please enter a choice between 1 and 3."
	};

public:
	InvalidChoice(int err_code) {
		std::cout << this->errors[err_code] << std::endl;
	}
};

/* **********************************************************************
	Returns a string containing the date formatted as "12/25/2015".
********************************************************************** */
std::string Date::GetShortDate() {
	std::stringstream date;
	std::string separator = "/";

	date << this->month << separator << this->day << separator << this->year;

	return date.str();
}

/* **********************************************************************
	Returns a string containing the date formatted as "December 25, 2015"
********************************************************************** */
std::string Date::GetLongDate() {
	std::stringstream date;

	date << this->MONTHS[this->month - 1] << " " << this->day << ", " << this->year;

	return date.str();
}

/* **********************************************************************
	Returns a string containing the date formatted as "25 December 2015"
********************************************************************** */
std::string Date::GetForeignDate() {
	std::stringstream date;

	date << this->day << " " << this->MONTHS[this->month - 1] << " " << this->year;

	return date.str();
}

/* **********************************************************************
	Prints the date in the user chosen date format.
********************************************************************** */
void Date::PrintDate() {
	switch (this->choice) {
	case 1:
		std::cout << this->GetShortDate() << std::endl;
		break;
	case 2:
		std::cout << this->GetLongDate() << std::endl;
		break;
	case 3:
		std::cout << this->GetForeignDate() << std::endl;
		break;
	}
}

/* **********************************************************************
	Mutator function for setting the month. If an invalid month is entered,
	InvalidMonth will be thrown.
********************************************************************** */
void Date::setMonth(int month) {
	int testMonth = month - 1;
	if (testMonth < JANUARY) {
		throw InvalidMonth(0);
	}
	else if (testMonth > DECEMBER) {
		throw InvalidMonth(1);
	}
	else {
		this->month = month;
	}
}

/* **********************************************************************
	Mutator function for setting the day. If an invalid day is entered,
	InvalidDay will be thrown.
********************************************************************** */
void Date::setDay(int day) {
	if (day < 1) {
		throw InvalidDay(0);
	}
	else if (day > 31) {
		throw InvalidDay(1);
	}
	else {
		this->day = day;
	}
}

/* **********************************************************************
	Mutator function for setting the year. No error handling here as
	nearly any number is technically acceptable.
********************************************************************** */
void Date::setYear(int year) {
	this->year = year;
}

/* **********************************************************************
	Mutator function for setting the month. If an invalid month is entered,
	InvalidMonth will be thrown.
********************************************************************** */
void Date::setChoice(int choice) {
	if (choice < 1 || choice > 3) {
		throw InvalidChoice(0);
	}
	else {
		this->choice = choice;
	}
}

void Date::AskMonth() {
	int month;
	while (true) {
		std::cout << "Enter a Month (1 through 12): ";
		std::cin >> month;
		try {
			this->setMonth(month);
		}
		catch (InvalidMonth) {
			continue;
		}
		break;
	}
}

void Date::AskDay() {
	int day;
	while (true) {
		std::cout << "Enter a Day (1 through 31): ";
		std::cin >> day;
		try {
			this->setDay(day);
		}
		catch (InvalidDay) {
			continue;
		}
		break;
	}
}

void Date::AskYear() {
	int year;
	std::cout << "Enter a Year: ";
	std::cin >> year;
	this->setYear(year);
}

void Date::ChooseFormat() {
	int choice;
	std::cout << "Please choose a date format." << std::endl;
	std::cout << "1. 12/25/2015" << std::endl;
	std::cout << "2. December 25, 2015" << std::endl;
	std::cout << "3. 25 December 2015" << std::endl;
	while (true) {
		std::cout << "Choose: ";
		std::cin >> choice;
		try {
			this->setChoice(choice);
		}
		catch (InvalidChoice) {
			continue;
		}
		break;
	}
}

int main() {

	Date date_obj;

	std::cout << "Please follow the instructions given." << std::endl;

	date_obj.AskMonth();
	date_obj.AskDay();
	date_obj.AskYear();
	date_obj.ChooseFormat();
	date_obj.PrintDate();

	return 0;
}