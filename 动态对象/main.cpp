#include <iostream>
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

int main(void)
{
	Point* ptr = new Point[2];//创建对象数组
	ptr[0].move(5, 10); //通过指针访问数组元素的成员
	ptr[1].move(15, 20); 
	cout << "Deleting..." << endl;
	delete[] ptr; //删除整个对象数组
	return 0;
}
/*
Default Destructor called.
Default Destructor called.
Deleting...
Destructor called
Destructor called
*/
