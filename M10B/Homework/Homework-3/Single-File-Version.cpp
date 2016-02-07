// Dak Washbrook - CS M10B
/* ****************************************************
ASSIGNMENT -------------------------------------------
Design a class that will determine the monthly payment
on a home mortgage. The class should have member
functions for setting the loan amount, interest rate,
and number of years of the loan. It should also have
member functions for returning the monthly payment
amount and the total amount paid to the bank at the
end of the loan period, Implement the class in
complete program.
Input validation: Do not accept negative numbers for
any of the loan values.

CONTINUED ASSIGNMENT --------------------------------
Modify your mortgage program (HW#2) to display the
monthly payment amount and then, list the loan balance
and interest paid for each payment over the term of
the loan (for example 360 payments for 30 years). So
the balance of the loan for the last payment should be
0. Use loops to prevent lists from scrolling off the
screen (about 20 lines on a page). You can use the
Sleep(3000) function to make the program to wait for 3
seconds. Insert comments in the program to document
the program.
*************************************************** */

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Mortgage {

private:

	/* **************************************************
	Class Constants
	************************************************** */
	const float NUM_MONTHS = 12.0;  // Number of months in a year.
	const float ONE = 1.0;          // Const for one.
	const float HUNDRED = 100.0;    // Const for one hundred.

	/* **************************************************
	String Error constants for each possible error.
	************************************************** */
	const string ERR_AMOUNT = "Invalid Amount!", ERR_RATE = "Invalid Interest Rate!", ERR_YEARS = "Invalid Years!";

	/* **************************************************
	Class member variables
	************************************************** */
	float monthlyPayment = 0.0;     // Monthly Payment.
	float loanAmount = 0.0;         // The dollar amount of the loan.
	float interestRate = 0.0;       // The annual interest rate.
	float numYears = 0.0;           // The number of years of the loan.


	void MonthlyPayment() {
		/* **************************************************
		This function will calculate the monthly payment on
		a home loan.
		************************************************** */
		this->monthlyPayment = (this->loanAmount * this->PeriodInterestRate() * this->Term()) / (this->Term() - Mortgage::ONE);
	}

	float PeriodInterestRate() {
		/* **************************************************
		The interest rate for a year.
		************************************************** */
		return this->interestRate / Mortgage::NUM_MONTHS;
	}

	float Term() {
		/* **************************************************
		Calculate the term.
		************************************************** */
		return pow(Mortgage::ONE + this->PeriodInterestRate(), (Mortgage::NUM_MONTHS * this->numYears));
	}

	void ThrowError(const string ERROR) {
		/* **************************************************
		This function will print the error passed into it.
		************************************************** */
		cout << endl << ERROR << endl << endl;
	}

	float GetMonthInterest(float balance) {
		/* **************************************************
		Calculate one month interest.
		************************************************** */
		return balance * this->PeriodInterestRate();
	}

	float GetMonthPrincipal(float balance) {
		/* **************************************************
		Calculate one month principal.
		************************************************** */
		return this->monthlyPayment - this->GetMonthInterest(balance);
	}

public:

	bool SetLoanAmount(float amount) {
		/* **************************************************
		This function sets the loanAmount member variable.
		Throws an error if the value is less than 1.
		************************************************** */
		if (amount < 1) {
			this->ThrowError(ERR_AMOUNT);
			return false;
		}
		else {
			this->loanAmount = amount;
			return true;
		}
	}

	bool SetInterestRate(float rate) {
		/* **************************************************
		This function sets the interestRate member variable.
		Throws an error if the value is less than 1.
		************************************************** */
		if (rate < 1) {
			this->ThrowError(ERR_RATE);
			return false;
		}
		else {
			this->interestRate = rate / Mortgage::HUNDRED;
			return true;
		}
	}

	bool SetYears(float years) {
		/* **************************************************
		This function sets the numYears member variable.
		Throws an error if the value is less than 1.
		************************************************** */
		if (years < 1) {
			this->ThrowError(ERR_YEARS);
			return false;
		}
		else {
			this->numYears = years;
			return true;
		}
	}

	float GetMonthlyPayment() {
		/* **************************************************
		This function returns the monthlyPayment member
		variable value after calculating it.
		************************************************** */
		this->MonthlyPayment();
		return this->monthlyPayment;
	}

	void PrintMonthlyPayment() {
		/* **************************************************
		This function prints the monthly payment to the user.
		************************************************** */
		cout.precision(2);      // Set the precision to 2 so that a valid dollar ($) amount is shown to the user.

		// Print the Monthly Payment.
		cout << endl << "Monthly Payment = $" << fixed << this->GetMonthlyPayment() << endl << endl;
	}

	void PrintStatement() {
		/* **************************************************
		This function prints the monthly payment to the user.
		************************************************** */
		float balance = this->loanAmount;
		int month = 1;
		string cont;

		while (balance > 0.0) {
			cout << "Month\tMonthly Payment\tPrincipal Paid\tInterest Paid\tBalance" << endl;
			cout << "-------------------------------------------------------------------------------" << endl;
			for (int i = 0;  i < 20; i++) {
				cout << month << "\t$" << this->GetMonthlyPayment() << "\t$" << this->GetMonthPrincipal(balance) << "\t\t$" << this->GetMonthInterest(balance) << "\t\t$" << balance << endl;
				balance = balance - this->GetMonthPrincipal(balance);
				month++;
			}
			cout << "Show 20 more..." << endl;
			system("pause");
		}
	}

	void AskUser() {
		/* **************************************************
		First, initialize the floating point values for
		years, rate, and amount. These will store the values
		that the user inputs.
		************************************************** */
		float years = 0.0, rate = 0.0, amount = 0.0;

		/* **************************************************
		This boolean value is purely for error checking.
		good will be false if the user ever inputs an
		unacceptable value. This will cause the do loops to
		loop until good == true.
		************************************************** */
		bool good = true;

		/* **************************************************
		Get and set the Loan Amount. Error checking for if
		the user inputs any value under 1.
		************************************************** */
		do {
			cout << "Loan Amount: $";
			cin >> amount;
			good = this->SetLoanAmount(amount);
		} while (!good);

		/* **************************************************
		Get and set the Interest Rate. Error checking for if
		the user inputs any value under 1.
		************************************************** */
		do {
			cout << "Interest Rate (Percent): %";
			cin >> rate;
			good = this->SetInterestRate(rate);
		} while (!good);

		/* **************************************************
		Get and set the Number of Years. Error checking for
		if the user inputs any value under 1.
		************************************************** */
		do {
			cout << "Number of Years for Loan: ";
			cin >> years;
			good = this->SetYears(years);
		} while (!good);

		/* **************************************************
		Calculate and store the MonthlyPayment
		************************************************** */
		this->MonthlyPayment();
	}

};

int main() {

	/* **************************************************
	Initialize the class under the homeLoan variable.
	************************************************* */
	Mortgage homeLoan;

	homeLoan.AskUser();					// Ask the user for the information.

	homeLoan.PrintMonthlyPayment();		// Print the monthly payment they will pay.

	homeLoan.PrintStatement();			// Print the table of payments.

	return 0;
}
