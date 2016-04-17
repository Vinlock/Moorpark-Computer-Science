/**
* HW#9 E. Nikjeh
* Due Week 13, Sun. April 17, 2016
* Design a class named Shape which is an abstract base class. Shape has two pure virtual functions, printShapeName and print.
* Shape contains two other virtual functions, area and volume, each of which has a default implementation that returns a value of zero.
* Point class inherits these implementations (both area and volume of a point are zero) from Shape. A Point has x and y coordinate private members.
* Class Circle is derived from Point with public inheritance. A Circle has a volume of 0.0, so base-class member function volume is not overridden.
* A Circle has nonzero area, so the area function is overridden in this class. Write get and set functions to return and to assign a new radius to a Circle.
* Class Cylinder is derived from Circle with public inheritance. A Cylinder has area and volume different from those of Circle, so the area and volume
* functions are both overridden in this class. Write get and set functions to return height and assign new height.
* Create one point, one circle, and one Cylinder then print the results.
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Shape {

protected:
	// Pi
	double pi = 3.14159265359;

public:
	// Pure Virtual Void Function that make the Shape class abstract.
	virtual void printShapeName() = 0;
	virtual void print() = 0;

	// Overridable virtual functions
	virtual double area() {
		return 0.0;
	}
	virtual double volume() {
		return 0.0;
	}

};

class Point : public Shape {

private:
	// X and Y location of the point or center point.
	double x, y;

public:
	// Default Constructor
	Point() {
		this->x = 0.0;
		this->y = 0.0;
	}
	// Constructor from Parameters
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

	// A point does not have an area or volume, so they remain zero.
	double area() {
		return 0.0;
	}
	double volume() {
		return 0.0;
	}

	// Print the Name of the Shape.
	void printShapeName() {
		cout << endl << "Point" << endl;
	}

	// Print the Shape's Information
	void print() {
		this->printShapeName();
		cout << "X: " << x << endl;
		cout << "Y: " << x << endl;
	}

};

class Circle : public Point {

protected:
	// The circle's radius.
	double radius;

public:
	// Default Constructor
	// Also initializes the Parent Constructor.
	Circle() : Point() {
		this->radius = 0.0;
	}
	
	// Constructor with Parameters that also initialized the parent constructor with parameters.
	Circle(double radius, double x=0.0, double y=0.0) : Point(x, y) {
		this->radius = radius;
	}

	// Radius member accessor.
	double getRadius() {
		return this->radius;
	}
	// Radius member set function.
	void setRadius(double radius) {
		this->radius = radius;
	}
	
	// Calculates the Area of the Circle
	double area() {
		return this->pi * sqrt(radius);
	}

	// A circle does not have volume, therefore that function remains default.

	// Print the Circle shape name.
	void printShapeName() {
		cout << endl << "Circle" << endl;
	}

	// Print the Circle's information.
	void print() {
		Point::print();
		cout << "Radius: " << this->radius << endl;
		cout << "Area: " << this->area() << endl;
	}

};

class Cylinder : public Circle {

private:
	// The Cylinder's Height
	double height = 0.0;

public:
	// Default Constructor
	// Intializes the Circle Parent Constructor
	Cylinder() : Circle() {
		this->height = height;
	}
	// Constructor with parameters that also initializes the Circle constructor with parameters.
	Cylinder(double height, double radius, double x = 0.0, double y = 0.0) : Circle(radius, x, y) {
		this->height = height;
	}

	// Accessor function for height.
	double getHeight() {
		return this->height;
	}
	// Set function for height.
	void setHeight(double height) {
		this->height = height;
	}

	// Calculate the Area of the cylinder.
	double area() {
		return (2 * this->pi * this->radius * this->height) + (2 * this->pi * sqrt(this->radius));
	}
	// Calculate the Volume of the cylinder.
	double volume() {
		return this->pi * sqrt(this->radius) * this->height;
	}

	// Print the Cylinder Shape name.
	void printShapeName() {
		cout << endl << "Cylinder" << endl;
	}

	// Print the Cylinder information.
	void print() {
		Circle::print();
		cout << "Height: " << this->height << endl;
		cout << "Volume: " << this->volume() << endl;
	}

};

int main() {
	
	Point p(1.0, 1.0);

	Circle c(5.0, 3.0, 3.0);

	Cylinder cy(10.0, 20.0, 4.0, 4.0);

	p.print();
	c.print();
	cy.print();

}
