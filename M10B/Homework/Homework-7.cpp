#include <iostream>

using namespace std;

class Complex {

private:
	double real;

	double imaginary;

public:
	Complex(double real = 0.0, double imaginary = 0.0) {
		this->real = real;
		this->imaginary = imaginary;
	}

	Complex add(Complex num2) {
		double newReal = this->real + num2.getReal();
		double newImaginary = this->imaginary + num2.getImaginary();
		Complex newComplex(newReal, newImaginary);
		return newComplex;
	}

	Complex subtract(Complex num2) {
		double newReal = this->real - num2.getReal();
		double newImaginary = this->imaginary - num2.getImaginary();
		Complex newComplex(newReal, newImaginary);
		return newComplex;
	}

	void print() {
		cout << "(" << this->real << ", " << this->imaginary << ")" << endl;
	}

	double getReal() {
		return this->real;
	}

	double getImaginary() {
		return this->imaginary;
	}

};

int main() {

	while (true) {
		double firstReal, firstImaginary;
		double secondReal, secondImaginary;

		int choice;

		do {
			cout << "Enter the first real number: ";
			cin >> firstReal;

			cout << "Enter the first imaginary number: ";
			cin >> firstImaginary;

			cout << "Enter the second real number: ";
			cin >> secondReal;

			cout << "Enter the second imaginary number: ";
			cin >> secondImaginary;

			Complex first(firstReal, firstImaginary);
			Complex second(secondReal, secondImaginary);
			cout << "Complex Numbers are now stored." << endl << endl;

			do {
				cout << "Select an option to manipulate the Complex Numbers: " << endl;
				cout << "1. Add" << endl;
				cout << "2. Subtract" << endl;
				cout << "3. New Numbers" << endl;
				cout << "4. End Program." << endl;
				cin >> choice;
				if (choice < 1 || choice > 4) {
					cout << "INVALID CHOICE" << endl;
					continue;
				}

				Complex newComplex;

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
