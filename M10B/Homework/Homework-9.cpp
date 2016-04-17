#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Shape {

protected:
	double pi = 3.14159265359;

public:
	virtual void printShapeName() = 0;

	virtual void print() = 0;

	virtual double area() {
		return 0.0;
	}

	virtual double volume() {
		return 0.0;
	}

};

class Point : public Shape {

private:
	double x, y;

public:
	Point() {
		this->x = 0.0;
		this->y = 0.0;
	}
	
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}

	double area() {
		return 0;
	}

	double volume() {
		return 0;
	}

	void printShapeName() {
		cout << endl << typeid(*this).name() << endl;
	}

	void print() {
		this->printShapeName();
		cout << "X: " << x << endl;
		cout << "Y: " << x << endl;
	}

};

class Circle : public Point {

protected:
	double radius;

public:
	Circle() : Point() {
		this->radius = 0.0;
	}

	Circle(double radius, double x=0.0, double y=0.0) : Point(x, y) {
		this->radius = radius;
	}

	double getRadius() {
		return this->radius;
	}

	void setRadius(double radius) {
		this->radius = radius;
	}
	
	double area() {
		return this->pi * sqrt(radius);
	}

	void print() {
		Point::print();
		cout << "Radius: " << this->radius << endl;
		cout << "Area: " << this->area() << endl;
	}

};

class Cylinder : public Circle {

private:
	double height = 0.0;

public:
	Cylinder() : Circle() {
		this->height = height;
	}

	Cylinder(double height, double radius, double x = 0.0, double y = 0.0) : Circle(radius, x, y) {
		this->height = height;
	}

	double getHeight() {
		return this->height;
	}

	void setHeight(double height) {
		this->height = height;
	}

	double area() {
		return (2 * this->pi * this->radius * this->height) + (2 * this->pi * sqrt(this->radius));
	}

	double volume() {
		return this->pi * sqrt(this->radius) * this->height;
	}

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
