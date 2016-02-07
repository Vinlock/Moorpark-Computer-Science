#pragma once

#define Mortgage_h

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
	const string ERR_AMOUNT = "Invalid Amount!";
	const string ERR_RATE = "Invalid Interest Rate!";
	const string ERR_YEARS = "Invalid Years!";

	/* **************************************************
	Class Member Variables
	************************************************** */
	float monthlyPayment = 0.0;     // Monthly Payment.
	float loanAmount = 0.0;         // The dollar amount of the loan.
	float interestRate = 0.0;       // The annual interest rate.
	float numYears = 0.0;           // The number of years of the loan.

	/* **************************************************
	Private Member Functions
	************************************************** */
	void MonthlyPayment();

	float PeriodInterestRate();

	float Term();

	void ThrowError(const string ERROR);

	float GetMonthInterest(float balance);

	float GetMonthPrincipal(float balance);

public:

	/* **************************************************
	Public Member Functions
	************************************************** */
	bool SetLoanAmount(float amount);

	bool SetInterestRate(float rate);

	bool SetYears(float years);

	float GetMonthlyPayment();

	void PrintMonthlyPayment();

	void PrintStatement();

	void AskUser();

};
