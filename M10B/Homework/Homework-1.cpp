#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/* Declaration of the Structure used to store the different budget variables. */
struct MonthlyBudget {
	double housing;
	double utilities;
	double household_expenses;
	double transportation;
	double food;
	double medical;
	double insurance;
	double entertainment;
	double clothing;
	double misc;
};

MonthlyBudget AskUser();
string Calculate(double budget, double goal);
string Round(double dbl);
void Report(MonthlyBudget budget);

/* Declared Constants for the budget goals. */
const double
HOUSING = 500.0,
UTILITIES = 150.0,
HOUSEHOLD_EXPENSES = 65.0,
TRANSPORTATION = 50.0,
FOOD = 250.00,
MEDICAL = 30.0,
INSURANCE = 100.0,
ENTERTAINMENT = 150.0,
CLOTHING = 75.0,
MISC = 50.0;

const int COLUMNSIZE = 25;

/* Constants for the result strings. */
const string
OVER_BUDGET = "Over Budget by ",
UNDER_BUDGET = "Under Budget by ",
MET_BUDGET = "Met Budget!";

int main() {

	MonthlyBudget budget = AskUser();
	Report(budget);

	return 0;

}

MonthlyBudget AskUser() {
	MonthlyBudget budget;
	cout << "Please enter the amounts spent in each budget category during a month." << endl << endl;

	cout << "Housing: ";
	cin >> budget.housing;

	cout << "Utilities: ";
	cin >> budget.utilities;

	cout << "Household Expenses: ";
	cin >> budget.household_expenses;

	cout << "Transportation: ";
	cin >> budget.transportation;

	cout << "Food: ";
	cin >> budget.food;

	cout << "Medical: ";
	cin >> budget.medical;

	cout << "Insurance: ";
	cin >> budget.insurance;

	cout << "Entertainment: ";
	cin >> budget.entertainment;

	cout << "Clothing: ";
	cin >> budget.clothing;

	cout << "Misc: ";
	cin >> budget.misc;

	return budget;
}

string Calculate(double spent, const double goal) {
	/* This function finds out if the spent amount meets, or is higher/lower, than the goal budget. */
	string result;
	double difference;
	if (spent > goal) {
		difference = spent - goal;
		result.append(OVER_BUDGET);
		result.append(Round(difference));
	}
	else if (spent < goal) {
		difference = goal - spent;
		result.append(UNDER_BUDGET);
		result.append(Round(difference));
	}
	else if (spent == goal) {
		result.append(MET_BUDGET);
	}
	return result;
}

string Round(double dbl) {
	stringstream buffer;
	buffer.precision(2);
	buffer << fixed << dbl;
	return buffer.str();
}

void Report(MonthlyBudget budget) {
	cout << "Results:" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "BUDGET                  OVER/UNDER               " << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "HOUSING                 " << Calculate(budget.housing, HOUSING) << endl;
	cout << "UTILITIES               " << Calculate(budget.utilities, UTILITIES) << endl;
	cout << "HOUSEHOLD EXPENSES      " << Calculate(budget.household_expenses, HOUSEHOLD_EXPENSES) << endl;
	cout << "TRANSPORTATION          " << Calculate(budget.transportation, TRANSPORTATION) << endl;
	cout << "FOOD                    " << Calculate(budget.food, FOOD) << endl;
	cout << "MEDICAL                 " << Calculate(budget.medical, MEDICAL) << endl;
	cout << "INSURANCE               " << Calculate(budget.insurance, INSURANCE) << endl;
	cout << "ENTERTAINMENT           " << Calculate(budget.entertainment, ENTERTAINMENT) << endl;
	cout << "CLOTHING                " << Calculate(budget.clothing, CLOTHING) << endl;
	cout << "MISC                    " << Calculate(budget.misc, MISC) << endl;
}
