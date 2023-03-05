#include <iostream>
using namespace std;

int exec(int v1, int v2, int (*func)(int, int))
{
	return func(v1, v2);
}


int main(void)
{

	cout << exec(20, 10, [](int v1, int v2)
		{
			return v1 + v2;
		}) << endl;
	cout << exec(20, 10, [](int v1, int v2)
		{
			return v1 - v2;
		}) << endl;
	cout << exec(20, 10, [](int v1, int v2)
		{
			return v1 * v2;
		}) << endl;


	//最简单的调用此表达式
	/*([]
		{
			cout << "funvc()----" << endl;
		}
	)();*/

	//void (*p)() = []
	//	{
	//		cout << "funvc()----" << endl;
	//	};

	//p(); //调用lambda表达式
	////计算两个整数和
	//auto q = [](int a,int b) -> int
	//{
	//	 return a + b;
	//};

	//cout << q(10,20) << endl;



	return 0;
}