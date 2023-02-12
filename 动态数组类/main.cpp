#include <iostream>
#include <cassert>
using namespace std;
class Point
{
public:
	Point(int x, int y)
	{
		cout << "Destructor called." << endl;
	};
	Point() :x(x), y(y)
	{
		cout << "Default Destructor called." << endl;
	};
	~Point()
	{
		cout << "Destructor called" << endl;
	}
	int getX() const { return x; } //常函数
	int getY() const { return y; }
	void move(int newX, int newY)
	{
		x = newX;
		y = newY;
	}
private:
	int x, y;
};
class ArrayOfPoints  //动态数组
{
public:
	ArrayOfPoints(int size) :size(size)
	{
		points = new Point[size];//建立数组，就要想起在何处释放
	}
	~ArrayOfPoints()
	{
		cout << "Deleting ..." << endl;  //释放数组 
		delete[] points;
	}
	Point& element(int index) //返回引用
	{
		assert(index >= 0 && index < size);
		return points[index];  //返回
	}
private:
	Point* points;//指向动态数组首地址
	int size; //数组大小
};


int main(void)
{
	int count;
	cout << "Please enter the count of points:";
	cin >> count;
	ArrayOfPoints points(count); //创建数组对象
	points.element(0).move(5, 0); //访问数组元素的成员
	points.element(1).move(15, 20); //访问数组元素的成员
	return 0;
}
/*
Please enter the count of points:3
Default Destructor called.
Default Destructor called.
Default Destructor called.
Deleting ...
Destructor called
Destructor called
Destructor called
*/