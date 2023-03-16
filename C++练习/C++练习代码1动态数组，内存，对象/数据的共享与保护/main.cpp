#include <iostream>
//C++标准程序库的所有标识符都被声明在std命名空间内
using namespace std;
class Point
{
public: //外部接口
	Point(int x = 0, int y = 0):x(x), y(x) //析构函数
	{
		//在构造函数中对cout累加，所有对象共同共同维护一个count
		count++;
	}
	Point(Point& p) //复制构造函数
	{
		x = p.x;
		y = p.y;
		count++;
	}
	~Point()  //析构函数
	{
		count--;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	static void showCount()  //静态函数成员，主函数可以直接调用查看count
	{
		cout << " Object count:" << count << endl;
	}
private:
	int x, y;
	static int count;  //静态数据成员声明，用于记录点的个数
};
int Point::count = 0;//静态数据成员定义和初始化，使用类名限定
int main(void)
{
	Point::showCount(); //输出对象个数
	Point a(4, 5);
	cout << "Point A:" << a.getX() << "," << a.getY();
	a.showCount();//输出对象个数

	Point b(a);
	cout << "Point B:" << b.getX() << "," << b.getY();
	b.showCount();//输出对象个数
	return 0;
}
/*
* 输出：
Point A:4,4 Object count:1
Point B:4,4 Object count:2
*/