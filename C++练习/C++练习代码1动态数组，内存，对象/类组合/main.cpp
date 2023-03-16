/*
* project:�����ϣ��߶Σ�Line����
* environment :VS2022
* time:2023��1��31��
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
	};  //���캯��
	Point(const Point& p);//���ƹ��캯��
	int getX() const { return x; } //������
	int getY() const { return y; }
private:
	int x, y;
};
//������
class Line
{
public: //�ⲿ�ӿ�
	Line(Point xp1, Point xp2);
	Line(Line& l);
	double getLen()
	{
		return len;
	}
private:  //˽�����ݳ�Ա
	Point p1, p2; //Point��Ķ���P1��P2
	double len;
};
Point::Point(const Point& p)
{
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor" << endl;
}
//�����Ĺ��캯��
Line::Line(Point xp1, Point xp2) :p1(xp1), p2(xp2)
{
	cout << "Calling constructor of Line" << endl;
	double x = static_cast<double>(p1.getX() - p2.getX());
	double y = static_cast<double>(p1.getY() - p2.getY());
	len = sqrt(x * x + y * y);  //������ȶϵ���Ա仯
}

Line::Line(Line& l) :p1(l.p1), p2(l.p2) //�����ĸ��ƹ��캯��
{
	cout << "Calling the copy constructor of Line" << endl;
	len = l.len;
}

int main(void)
{
	Point myp1(1, 1), myp2(4, 5);  //����Point ��Ķ���
	Line line(myp1, myp2);    //����Line��Ķ���
	Line line2(line);		 //���ø��ƹ��캯������һ���¶���
	cout << "The length of line is";
	cout << line.getLen() << endl;
	cout << "The length of the line2 is:" << line2.getLen() << endl;

	return 0;
}
