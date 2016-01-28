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
 *************************************************** */

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class Mortgage {
    
private:
    
    const float NUM_MONTHS = 12.0;  // Number of months in a year.
    const float ONE = 1.0;          // Const for one.
    const float HUNDRED = 100.0;    // Const for one hundred.
    
    /* **************************************************
     String Error constants for each possible error.
     ************************************************* */
    const string ERR_AMOUNT = "Invalid Amount!", ERR_RATE = "Invalid Interest Rate!", ERR_YEARS = "Invalid Years!";
    
    float monthlyPayment = 0.0;     // Monthly Payment.
    float loanAmount = 0.0;         // The dollar amount of the loan.
    float interestRate = 0.0;       // The annual interest rate.
    float numYears = 0.0;           // The number of years of the loan.
    
    
    void payment() {
        /* **************************************************
         This function will calculate the monthly payment on
         a home loan.
         ************************************************* */
        this->monthlyPayment = (this->loanAmount * (this->interestRate / Mortgage::NUM_MONTHS) * this->term()) / (this->term() - Mortgage::ONE);
    }
    
    float term() {
        /* **************************************************
         Calculate the term.
         ************************************************* */
        return pow(Mortgage::ONE + (this->interestRate / Mortgage::NUM_MONTHS), (Mortgage::NUM_MONTHS * this->numYears));
    }
    
    void throwError(const string ERROR) {
        /* **************************************************
         This function will print the error passed into it.
         ************************************************* */
        cout << endl << ERROR << endl << endl;
    }
    
public:
    
    bool setLoanAmount(float amount) {
        /* **************************************************
         This function sets the loanAmount member variable.
         Throws an error if the value is less than 1.
         ************************************************* */
        if (amount < 1) {
            this->throwError(ERR_AMOUNT);
            return false;
        }
        else {
            this->loanAmount = amount;
            return true;
        }
    }
    
    bool setInterestRate(float rate) {
        /* **************************************************
         This function sets the interestRate member variable.
         Throws an error if the value is less than 1.
         ************************************************* */
        if (rate < 1) {
            this->throwError(ERR_RATE);
            return false;
        }
        else {
            this->interestRate = rate / Mortgage::HUNDRED;
            return true;
        }
    }
    
    bool setYears(float years) {
        /* **************************************************
         This function sets the numYears member variable.
         Throws an error if the value is less than 1.
         ************************************************* */
        if (years < 1) {
            this->throwError(ERR_YEARS);
            return false;
        }
        else {
            this->numYears = years;
            return true;
        }
    }
    
    float getMonthlyPayment() {
        /* **************************************************
         This function returns the monthlyPayment member
         variable value after calculating it.
         ************************************************* */
        this->payment();
        return this->monthlyPayment;
    }
    
};

int main() {
    
    /* **************************************************
     First, initialize the floating point values for
     years, rate, and amount. These will store the values
     that the user inputs.
     ************************************************* */
    float years = 0.0, rate = 0.0, amount = 0.0;
    
    /* **************************************************
     This boolean value is purely for error checking.
     good will be false if the user ever inputs an
     unacceptable value. This will cause the do loops to
     loop until good == true.
     ************************************************* */
    bool good = true;
    
    /* **************************************************
     Initialize the class under the homeLoan variable.
     ************************************************* */
    Mortgage homeLoan;
    
    /* **************************************************
     Get and set the Loan Amount. Error checking for if
     the user inputs any value under 1.
     ************************************************* */
    do {
        cout << "Loan Amount: $";
        cin >> amount;
        good = homeLoan.setLoanAmount(amount);
    } while (!good);
    
    /* **************************************************
     Get and set the Interest Rate. Error checking for if
     the user inputs any value under 1.
     ************************************************* */
    do {
        cout << "Interest Rate (Percent): %";
        cin >> rate;
        good = homeLoan.setInterestRate(rate);
    } while (!good);
    
    /* **************************************************
     Get and set the Number of Years. Error checking for
     if the user inputs any value under 1.
     ************************************************* */
    do {
        cout << "Number of Years for Loan: ";
        cin >> years;
        good = homeLoan.setYears(years);
    } while (!good);
    
    cout.precision(2);      // Set the precision to 2 so that a valid dollar ($) amount is shown to the user.
    
    // Print the Monthly Payment.
    cout << endl << "Monthly Payment = $" << fixed << homeLoan.getMonthlyPayment() << endl << endl;
    
    return 0;
}
