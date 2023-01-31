/*
* project:���ƹ��캯��
* environment :VS2022
* time:2023��1��31��
*/
#include <iostream>
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
		void setX(int xx)
		{
			x = xx;
		}
		void setY(int yy)
		{
			y = yy;
		}
		int getX() const { return x; } //������
		int getY() const { return y; }
	private:
		int x,y;
};
//���ƹ��캯����ʵ��
Point::Point(const Point& p)
{
	x = p.x;
	y = p.y;
	cout << "Calling the copy constructor" << endl;
}
void fun1(Point p)
{
	cout << p.getX() << endl;
}
Point fun2()
{
	Point a(1, 2);
	return a;
}
int main(void)
{
	Point a(4,5);
	Point b(a);  //��a��ʼ��b
	cout << b.getX() << endl;
	fun1(b);  //����b��Ϊfun1��ʵ��
	b = fun2(); //�����ķ���ֵ�������
	cout << b.getX() << endl;
	return 0;
}
