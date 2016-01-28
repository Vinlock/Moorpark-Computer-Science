//
//  main.cpp
//  HW3
//
//  Created by Vinlock on 1/28/16.
//  Copyright © 2016 PvP All Day. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

class Mortgage {
    
private:
    
    const float NUM_MONTHS = 12.0;  // Number of months in a year.
    const float ONE = 1.0;          // Const for one.
    const float HUNDRED = 100.0;    // Const for one hundred.
    
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
    
    bool checkInput(float input) {
        if (input < 0) {
            return false;
        }
        else {
            return true;
        }
    }
    
public:
    void setLoanAmount(float amount) {
        this->loanAmount = amount;
    }
    void setInterestRate(float rate) {
        this->interestRate = rate / Mortgage::HUNDRED;
    }
    void setYears(float years) {
        this->numYears = years;
    }
    float getMonthlyPayment() {
        this->payment();
        return this->monthlyPayment;
    }
    
};

int main() {
    
    float years, rate, amount;
    
    Mortgage homeLoan;
    
    cout << "Loan Amount: $";
    cin >> amount;
    
    cout << "Interest Rate (Percent): %";
    cin >> rate;
    
    cout << "Number of Years for Loan: ";
    cin >> years;
    
    homeLoan.setInterestRate(rate);
    homeLoan.setLoanAmount(amount);
    homeLoan.setYears(years);
    
    cout.precision(2);
    
    cout << "Monthly Payment = $" << fixed << homeLoan.getMonthlyPayment();
    
    return 0;
}
