#include <iostream>

using namespace std;

class Complex {

private:
	// Declare the Real Number
	double real;

	// Declare the Imaginary Number
	double imaginary;

public:
	/**
	* Complex constructor.
	* 
	* @param double real			Initializer for the Real Number
	* @param double imaginary		Initializer for the Imaginary Number
	*/
	Complex(double real = 0.0, double imaginary = 0.0) {
		// Store the Real Number
		this->real = real;

		// Store the Imaginary Number
		this->imaginary = imaginary;
	}

	/**
	* Add this Complex to with another Complex and return the newComplex.
	* 
	* @param Complex num2			Complex to be added to this Complex
	* @return Complex newComplex	returns the newComplex number after adding.
	*/
	Complex add(Complex num2) {
		double newReal = this->real + num2.getReal();
		double newImaginary = this->imaginary + num2.getImaginary();
		Complex newComplex(newReal, newImaginary);
		return newComplex;
	}

	/**
	* Subtract another Complex from this Complex and return the new Complex.
	*
	* @param Complex num2			Complex to be subtracted from this Complex
	* @return Complex newComplex	returns the newComplex number after subtracting.
	*/
	Complex subtract(Complex num2) {
		double newReal = this->real - num2.getReal();
		double newImaginary = this->imaginary - num2.getImaginary();
		Complex newComplex(newReal, newImaginary);
		return newComplex;
	}

	/**
	* Print this Complex Number as (a, b). Where a is the real number and b is the imaginary part.
	*/
	void print() {
		cout << "(" << this->real << ", " << this->imaginary << ")" << endl;
	}

	/**
	* Accessor function for this real number.
	* 
	* @return double real
	*/
	double getReal() {
		return this->real;
	}

	/**
	* Accessor function for this real number.
	*
	* @return double imaginary
	*/
	double getImaginary() {
		return this->imaginary;
	}

};

int main() {

	while (true) {
		/**
		* Declare the real and imaginary doubles for the first and second complex numbers.
		*/
		double firstReal, firstImaginary;
		double secondReal, secondImaginary;

		/**
		* Declare the choice integer for the action the user want's to make.
		*/
		int choice;

		do {
			// Request the first real number.
			cout << "Enter the first real number: ";
			cin >> firstReal;

			// Request the first imaginary number.
			cout << "Enter the first imaginary number: ";
			cin >> firstImaginary;

			// Request the second real number.
			cout << "Enter the second real number: ";
			cin >> secondReal;

			// Request the second imaginary number.
			cout << "Enter the second imaginary number: ";
			cin >> secondImaginary;

			/**
			* Create the Complex objects for the first and second complex numbers.
			*/
			Complex first(firstReal, firstImaginary);
			Complex second(secondReal, secondImaginary);
			cout << "Complex Numbers are now stored." << endl << endl;

			/**
			* Do while loop for the choices of how to manipulate the Complex numbers.
			*/
			do {
				cout << "Select an option to manipulate the Complex Numbers: " << endl;
				cout << "1. Add" << endl;
				cout << "2. Subtract" << endl;
				cout << "3. New Numbers" << endl;
				cout << "4. End Program." << endl;
				cin >> choice;
				// If the choice is out of range, continue.
				if (choice < 1 || choice > 4) {
					cout << "INVALID CHOICE" << endl;
					continue;
				}

				// Declare what will be the new Complex number.
				Complex newComplex;

				// Switch statement to run the action that the user chooses.
				switch (choice) {
				case 1:
					newComplex = first.add(second);
					newComplex.print();
					break;
				case 2:
					newComplex = first.subtract(second);
					newComplex.print();
					break;
				case 3:
					goto store;
					break;
				default:
					goto stop;
					break;
				}

			} while (true);
		store:
			continue;
		} while (true);
	stop:
		break;
	}

	cout << endl;

	return 0;

}
