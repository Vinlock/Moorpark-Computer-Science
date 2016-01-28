//
//  main.cpp
//  HW3
//
//  Created by Vinlock on 1/28/16.
//  Copyright © 2016 PvP All Day. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Mortgage {
    
private:
    
    const float NUM_MONTHS = 12.0;  // Number of months in a year.
    const float ONE = 1.0;          // Const for one.
    const float HUNDRED = 100.0;    // Const for one hundred.
    const string ERROR = "Invalid Entry!";
    
    float monthlyPayment = 0.0;     // Monthly Payment.
    float loanAmount = 0.0;         // The dollar amount of the loan.
    float interestRate = 0.0;       // The annual interest rate.
    float numYears = 0.0;           // The number of years of the loan.
    
    
    void payment() {
        // This function will calculate the monthly payment on a home loan.
        // Required Set: loanAmount, interestRate, numYears.
        this->monthlyPayment = (this->loanAmount * (this->interestRate / Mortgage::NUM_MONTHS) * this->term()) / (this->term() - Mortgage::ONE);
    }
    
    float term() {
        // Required Set: interestRate, numYears.
        return pow(Mortgage::ONE + (this->interestRate / Mortgage::NUM_MONTHS), (Mortgage::NUM_MONTHS * this->numYears));
    }
    
    void throwError() {
        cout << endl << Mortgage::ERROR << endl << endl;
    }
    
public:
    bool setLoanAmount(float amount) {
        if (amount < 1) {
            this->throwError();
            return false;
        }
        else {
            this->loanAmount = amount;
            return true;
        }
    }
    bool setInterestRate(float rate) {
        if (rate < 1) {
            this->throwError();
            return false;
        }
        else {
            this->interestRate = rate / Mortgage::HUNDRED;
            return true;
        }
    }
    bool setYears(float years) {
        if (years < 1) {
            this->throwError();
            return false;
        }
        else {
            this->numYears = years;
            return true;
        }
    }
    float getMonthlyPayment() {
        this->payment();
        return this->monthlyPayment;
    }
    
};

int main() {
    
    float years = 0.0, rate = 0.0, amount = 0.0;
    bool good = true;
    
    Mortgage homeLoan;
    
    do {
        cout << "Loan Amount: $";
        cin >> amount;
        good = homeLoan.setLoanAmount(amount);
    } while (!good);
    
    do {
        cout << "Interest Rate (Percent): %";
        cin >> rate;
        good = homeLoan.setInterestRate(rate);
    } while (!good);
    
    do {
        cout << "Number of Years for Loan: ";
        cin >> years;
        good = homeLoan.setYears(years);
    } while (!good);
    
    cout.precision(2);
    
    cout << "Monthly Payment = $" << fixed << homeLoan.getMonthlyPayment();
    
    return 0;
}
