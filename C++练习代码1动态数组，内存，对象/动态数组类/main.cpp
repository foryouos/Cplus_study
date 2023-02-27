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
	int getX() const { return x; } //������
	int getY() const { return y; }
	void move(int newX, int newY)
	{
		x = newX;
		y = newY;
	}
private:
	int x, y;
};
class ArrayOfPoints  //��̬����
{
public:
	ArrayOfPoints(int size) :size(size)
	{
		points = new Point[size];//�������飬��Ҫ�����ںδ��ͷ�
	}
	~ArrayOfPoints()
	{
		cout << "Deleting ..." << endl;  //�ͷ����� 
		delete[] points;
	}
	Point& element(int index) //��������
	{
		assert(index >= 0 && index < size);
		return points[index];  //����
	}
private:
	Point* points;//ָ��̬�����׵�ַ
	int size; //�����С
};


int main(void)
{
	int count;
	cout << "Please enter the count of points:";
	cin >> count;
	ArrayOfPoints points(count); //�����������
	points.element(0).move(5, 0); //��������Ԫ�صĳ�Ա
	points.element(1).move(15, 20); //��������Ԫ�صĳ�Ա
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