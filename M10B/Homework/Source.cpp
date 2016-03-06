/* 
 * CS - M10B - 30110 - Dak Washbrook - HOMEWORK 6 - Median Function 
 * Due Week Eight, Sun. March 6, 2016
 * Median Function
 * In statistics, when a set of values is sorted in ascending or descending order, its median is the middle value (for odd number of values). If the set contains an even number of values, the median is the average, of the two middle values. Write a function that accepts as arguments the following:
 * An array of integers
 * An integer that indicates the number of elements in the array
 * The function should determine the median of the array. This value should be returned as a double. (Assume the values in the array are already sorted.)
 * Demonstrate your pointer prowess by using pointer notation instead of array notation in this function.
*/

#include <iostream>

using namespace std;

double median(double * array, int num) {
	if (num % 2 == 0) {
		// This means that the number of elements in the array is even
		int first_check = (num / 2) - 1; // This grabs the first of the two middle array keys.
		int second_check = (num / 2);	 // This grabs the seconds of the two middle array keys.
		double result = (array[first_check] + array[second_check]) / 2;	// This finds the average of the two middle array key's values.
		return result;	// Returns that result.
	}
	else {
		// Else the number of elements in the array is odd.
		int check = num / 2;	// This grabs the middle array key.
		double result = array[check];	// This gets the value at that array key.
		return result;	// Returns that result.
	}
}

int main() {
	
	double even_array[6] = { 1, 2, 3, 4, 5, 6 };
	int even_num = 6;

	double odd_array[5] = { 50, 51, 52, 53, 54 };
	int odd_num = 5;

	cout << "Even array: [" << even_num << "] - ";
	for (double value : even_array) {
		cout << value << " ";
	}
	cout << endl;
	cout << "Median: " << median(even_array, even_num) << endl << endl;

	cout << "Odd array: [" << odd_num << "] - ";
	for (double value : odd_array) {
		cout << value << " ";
	}
	cout << endl;
	cout << "Median: " << median(odd_array, odd_num) << endl << endl;

	return 0;
}