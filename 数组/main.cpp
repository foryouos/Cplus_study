#include <iostream>
#include "Pont.h"
using namespace std;
Point::Point() :x(0), y(0)
{
	cout << "Default Constructor called." << endl;
}
Point::Point(int x, int y) :x(x), y(y)
{
	cout << "Constructor called." << endl;
}
Point::~Point()
{
	cout << "Destructor called" << endl;
}
void Point::move(int newX, int newY)
{
	cout << "Moving the point to(" << newX << "," << newY << ")" << endl;
	x = newX;
	y = newY;
}
int main(void)
{
	cout << "Entering main..." << endl;
	Point a[2];
	for (int i = 0; i < 2; i++)
	{
		a[i].move(i + 10, i + 20);
	}
	cout << "Exiting main..." << endl;
	return 0;
}
/*
* Entering main...
Default Constructor called.
Default Constructor called.
Moving the point to(10,20)
Moving the point to(11,21)
Exiting main...
Destructor called
Destructor called
*/