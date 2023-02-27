/*
* project:类的组合，线段（Line）类
* environment :VS2022
* time:2023年1月31日
*/
#include <iostream>
#include <cmath>
using namespace std;
class Point
{
public:
	Point(int xx = 0, int yy = 0)
	{
		x = xx;
		y = yy;
	};  //构造函数
	Point(const Point& p);//复制构造函数
	int getX() const { return x; } //常函数
	int getY() const { return y; }
private:
	int x, y;
};
//类的组合
class Line
{
public: //外部接口
	Line(Point xp1, Point xp2);
	Line(Line& l);
	double getLen()
	{
		return len;
	}
private:  //私有数据成员
	Point p1, p2; //Point类的对象P1，P2
	double len;
};
Point::Point(const Point& p)
{
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor" << endl;
}
//组合类的构造函数
Line::Line(Point xp1, Point xp2) :p1(xp1), p2(xp2)
{
	cout << "Calling constructor of Line" << endl;
	double x = static_cast<double>(p1.getX() - p2.getX());
	double y = static_cast<double>(p1.getY() - p2.getY());
	len = sqrt(x * x + y * y);  //如果长度断点可以变化
}

Line::Line(Line& l) :p1(l.p1), p2(l.p2) //组合类的复制构造函数
{
	cout << "Calling the copy constructor of Line" << endl;
	len = l.len;
}

int main(void)
{
	Point myp1(1, 1), myp2(4, 5);  //建立Point 类的对象
	Line line(myp1, myp2);    //建立Line类的对象
	Line line2(line);		 //利用复制构造函数建立一个新对象
	cout << "The length of line is";
	cout << line.getLen() << endl;
	cout << "The length of the line2 is:" << line2.getLen() << endl;

	return 0;
}
