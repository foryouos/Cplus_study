/* 
处理除零异常
*/
#include <iostream>
using namespace std;

int divide(int x, int y)
{
	if (y == 0)
		throw x; //通过throw创建x的异常对象抛掷给x
	return x / y;
}
int main(void)
{
	try
	{
		cout << "5 / 2 = " << divide(5, 2) << endl;
		cout << "8 / 0 = " << divide(8, 0) << endl;
		cout << "7 / 1 = " << divide(7, 1) << endl;
	}
	catch (int e)
	{
		cout << e << " is divided by zero !" << endl;
	}
	cout << "That is ok." << endl;
	return 0;
}
/*
5 / 2 = 2
8 is divided by zero !
That is ok.
*/