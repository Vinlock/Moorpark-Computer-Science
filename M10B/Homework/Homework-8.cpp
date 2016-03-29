#include <iostream>
#include <stdio.h>

using namespace std;

/**
* Class Definition of NumDays
*/
class NumDays {

	const double HOURS_PER_DAY = 8.0;

private:
	int hours = 0;
	double days = 0.0;


public:
	/**
	* Default Constructor
	*/
	NumDays();
	
	/**
	* Hours initilizing Constructor.
	*
	* @param int hours;
	*/
	NumDays(int hours);

	/**
	* Getter for hours
	* 
	* @return int
	*/
	int getHours();

	/**
	* Getter for days
	* 
	* @return double
	*/
	double getDays();

	/**
	* Setter for setting hours and recalculating days.
	* 
	* @param int hours
	* @return void
	*/
	void setHours(int hours);

	/**
	* Addition Operator Overload
	* 
	* @param NumDays& x
	* @return NumDays
	*/
	NumDays operator+(NumDays& x);

	/**
	* Subtraction Operator Overload
	* 
	* @param NumDays& x
	* @return NumDays
	*/
	NumDays operator-(NumDays& x);

	/**
	* Storing Operator Overload
	*
	* @param const NumDays&
	* @return void
	*/
	void operator=(const NumDays&);

	/**
	* Prefix increment operator overload.
	*
	* @return NumDays
	*/
	NumDays& operator++();

	/**
	* Postfix increment operator overload.
	*
	* @return NumDays
	*/
	NumDays operator++(int);

	/**
	* Prefix decrement operator overload.
	*
	* @return NumDays
	*/
	NumDays& operator--();

	/**
	* Postfix decrement operator overload.
	*
	* @return NumDays
	*/
	NumDays operator--(int);

	/**
	* Prints the hours and days. "1 days == 8 hours"
	*
	* @return void
	*/
	void printObject() {
		cout << endl << this->getDays() << " days == " << this->getHours() << " hours" << endl << endl;
	}

};

NumDays::NumDays() {}

NumDays::NumDays(int hours) {
	this->setHours(hours);
}

int NumDays::getHours() {
	return this->hours;
}

double NumDays::getDays() {
	return this->days;
}

void NumDays::setHours(int hours) {
	this->hours = hours;
	this->days = hours / NumDays::HOURS_PER_DAY;
}

NumDays NumDays::operator+(NumDays& x) {
	return NumDays(this->hours + x.hours);
}

NumDays NumDays::operator-(NumDays& x) {
	return NumDays(this->hours - x.hours);
}

void NumDays::operator=(const NumDays& x) {
	this->setHours(x.hours);
}

NumDays& NumDays::operator++() {
	this->hours++;
	this->setHours(this->hours);
	return *this;
}

NumDays NumDays::operator++(int) {
	this->setHours(++this->hours);
	return *this;
}

NumDays& NumDays::operator--() {
	this->hours--;
	this->setHours(this->hours);
	return *this;
}

NumDays NumDays::operator--(int) {
	this->setHours(--this->hours);
	return *this;
}

int main() {

	while (true) {
		int hours;

		cout << "Set hours: ";
		cin >> hours;

		NumDays days1(hours);

		days1.printObject();

		while (true) {
			int selection;

			cout << "Select One: " << endl;
			cout << "1. Prefix Increment Object." << endl;
			cout << "2. Postfix increment Object." << endl;
			cout << "3. Prefix Decrement Object." << endl;
			cout << "4. Postfix Decrement Object." << endl;
			cout << "5. Add another object to this one." << endl;
			cout << "6. Subtract another object from this one" << endl;
			cout << "7. Stop" << endl;
			cout << "Select -> ";
			cin >> selection;

			int newHours;
			NumDays newObject;

			switch (selection) {
			case 1:
				++days1;
				break;
			case 2:
				days1++;
				break;
			case 3:
				--days1;
				break;
			case 4:
				days1--;
				break;
			case 5:
				cout << "Set new object's hours: ";
				cin >> newHours;
				newObject.setHours(newHours);
				days1 = days1 + newObject;
				break;
			case 6:
				cout << "Set new object's hours: ";
				cin >> newHours;
				newObject.setHours(newHours);
				days1 = days1 - newObject;
				break;
			case 7:
				goto end;
			}
			days1.printObject();
			continue;

		end:
			break;
		}

		int choice;

		cout << "Would you like to go again?" << endl;
		cout << "1. Yes" << endl;
		cout << "2. No" << endl;
		cin >> choice;

		if (choice == 2) {
			break;
		}
		else if (choice == 1) {
			continue;
		}
	}

}
