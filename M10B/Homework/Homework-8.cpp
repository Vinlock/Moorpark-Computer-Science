#include <iostream>

using namespace std;

class NumDays {

	const double HOURS_PER_DAY = 8;

private:
	double hours;
	double days;


public:
	NumDays() {

	}
	NumDays(double hours) {
		this->setHours(hours);
	}

	double getHours() {
		return this->hours;
	}

	double getDays() {
		return this->days;
	}

	void setHours(double hours) {
		this->hours = hours;
		this->days = hours / HOURS_PER_DAY;
	}

	NumDays & operator + (const NumDays & x) {
		return NumDays(this->hours + x.hours);
	}

	NumDays & operator - (const NumDays & x) {
		return NumDays(this->hours - x.hours);
	}

	NumDays & operator ++ () {
		return NumDays(this->hours++);
	}

	NumDays & operator -- () {
		return NumDays(this->hours--);
	}
};

int main() {

	double hours1 = 8;
	double hours2 = 12;

	NumDays days1(hours1);
	NumDays days2(hours2);

	cout << days1.getDays() << endl;
	cout << days2.getDays() << endl;

	cout << endl;

	days1++;

	cout << days1.getDays() << endl;

}
