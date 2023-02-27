/*
* project :矩形位置，类的继承
*/
#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(void)
{
	Rectangle rect;//定义Rectangle类的对象
	//设置举行数据
	rect.initRectangle(2, 3, 20, 10);//设置矩形数据
	rect.move(3, 2);//移动矩形位置
	cout << "The data of rect(x,y,w,h):" << endl;
	//输出矩形的特征参数
	cout << rect.getX() << "," << rect.getY() << "," << rect.getW() <<"," << rect.getH() << endl;
	return 0;
}
/*
The data of rect(x,y,w,h):
5,5,20,10
*/