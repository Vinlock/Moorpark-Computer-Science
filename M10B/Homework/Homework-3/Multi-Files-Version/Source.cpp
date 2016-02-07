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

#include "MortgageDriver.h"

using namespace std;

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
