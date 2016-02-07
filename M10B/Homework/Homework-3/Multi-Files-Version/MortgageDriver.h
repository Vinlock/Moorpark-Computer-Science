#pragma once

#include "Mortgage.h"

using namespace std;

// PRIVATE FUNCTIONS

void Mortgage::MonthlyPayment() {
	/* **************************************************
	This function will calculate the monthly payment on
	a home loan.
	************************************************** */
	this->monthlyPayment = (this->loanAmount * this->PeriodInterestRate() * this->Term()) / (this->Term() - Mortgage::ONE);
}

float Mortgage::PeriodInterestRate() {
	/* **************************************************
	The interest rate for a year.
	************************************************** */
	return this->interestRate / Mortgage::NUM_MONTHS;
}

float Mortgage::Term() {
	/* **************************************************
	Calculate the term.
	************************************************** */
	return pow(Mortgage::ONE + this->PeriodInterestRate(), (Mortgage::NUM_MONTHS * this->numYears));
}

void Mortgage::ThrowError(string ERROR) {
	/* **************************************************
	This function will print the error passed into it.
	************************************************** */
	cout << endl << ERROR << endl << endl;
}

float Mortgage::GetMonthInterest(float balance) {
	/* **************************************************
	Calculate one month interest.
	************************************************** */
	return balance * this->PeriodInterestRate();
}

float Mortgage::GetMonthPrincipal(float balance) {
	/* **************************************************
	Calculate one month principal.
	************************************************** */
	return this->monthlyPayment - this->GetMonthInterest(balance);
}




// PUBLIC FUNCTIONS

bool Mortgage::SetLoanAmount(float amount) {
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

bool Mortgage::SetInterestRate(float rate) {
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

bool Mortgage::SetYears(float years) {
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

float Mortgage::GetMonthlyPayment() {
	/* **************************************************
	This function returns the monthlyPayment member
	variable value after calculating it.
	************************************************** */
	this->MonthlyPayment();
	return this->monthlyPayment;
}

void Mortgage::PrintMonthlyPayment() {
	/* **************************************************
	This function prints the monthly payment to the user.
	************************************************** */
	cout.precision(2);      // Set the precision to 2 so that a valid dollar ($) amount is shown to the user.

							// Print the Monthly Payment.
	cout << endl << "Monthly Payment = $" << fixed << this->GetMonthlyPayment() << endl << endl;
}

void Mortgage::PrintStatement() {
	/* **************************************************
	This function prints the monthly payment to the user.
	************************************************** */
	float balance = this->loanAmount;
	int month = 1;
	string cont;

	while (balance > 0.0) {
		cout << "Month\tMonthly Payment\tPrincipal Paid\tInterest Paid\tBalance" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < 20; i++) {
			cout << month << "\t$" << this->GetMonthlyPayment() << "\t$" << this->GetMonthPrincipal(balance);

			/* **********************************
			If statement to correct tab alignment
			********************************** */
			if (this->GetMonthPrincipal(balance) > 1000.0) {
				cout << "\t";
			}
			else {
				cout << "\t\t";
			}

			cout << this->GetMonthInterest(balance);

			/* **********************************
			If statement to correct tab alignment
			********************************** */
			if (this->GetMonthInterest(balance) > 1000.0) {
				cout << "\t";
			}
			else {
				cout << "\t\t";
			}

			cout << balance << endl;

			balance = balance - this->GetMonthPrincipal(balance);
			month++;
		}
		if (balance > 0.0) {
			cout << "Show 20 more..." << endl;
		}
		system("pause");
	}
}

void Mortgage::AskUser() {
	/* **************************************************
	This function quieries the user for the Loan Amount,
	Interest Rate, and Years until Loan maturity.
	************************************************** */

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
