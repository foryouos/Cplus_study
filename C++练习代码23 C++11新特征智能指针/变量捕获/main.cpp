#include <iostream>
using namespace std;

int exec(int v1, int v2, int (*func)(int, int))
{
	return func(v1, v2);
}


int main(void)
{
	int a = 10;
	//int b = 10;
	//auto func = [a, b]
	//{
	//	cout << a << endl;
	//	cout << b << endl;
	//};
	//a = 20;
	//func(); //值捕获，并没有获取最新的a值

	//auto func = [&a] //使用地址捕获，可以保证获取最新的a值
	//{
	//	cout << a << endl;
	//};

	//a = 70; 
	//func(); //地址捕获获取最新值

	//值捕获不能加加
	//auto func = [a]
	//{
	//	a++; //值捕获不能++
	//};
	//func();
	//地址捕获可以
	//auto func = [&a]
	//{
	//	a++;
	//};
	//func();
	// cout << a << endl; //值a+1
	//mutable 
	auto func = [a] () mutable //内部a可以相加
	{
		int b = a;
		b++;
		cout << "lambda = " << b << endl;
	};
	func();
	cout << a << endl;


	return 0;
}