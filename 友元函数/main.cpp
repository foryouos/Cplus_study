#include <iostream>
using namespace std;
class Point
{
public:
	Point(int x = 0, int y = 0) :x(x), y(y)
	{
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	friend float dist(const Point& a,const Point& b); //友元函数，只要在类体中就行
private: //私有函数成员
	int x, y;
};
float dist(const Point& a,const Point& b)
{
	double x = a.x - b.x;
	double y = a.y - b.y;
	return static_cast<float>(sqrt(x * x + y * y));
}
int main(void)
{
	Point p1(1, 1), p2(4, 5);
	cout << "This distance is:";
	cout << dist(p1, p2) << endl;
	return 0;
}
/*This distance is:5*/