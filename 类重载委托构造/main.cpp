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
	Point(int xx, int yy)
	{
		x = xx;
		y = yy;
	};  //构造函数
	Point() :Point(5, 6) {};
	int getX() const { return x; } //常函数
	int getY() const { return y; }
private:
	int x, y;
};


int main(void)
{
	
	return 0;
}
