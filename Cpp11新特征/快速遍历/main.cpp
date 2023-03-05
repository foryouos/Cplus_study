#include <iostream>
using namespace std;

void func(int v)
{
	cout << "func(int) - " << v << endl;
}
void func(int* v)
{
	cout << "func(int *) - " << v << endl;
}
int main(void)
{
	//auto a = 10;
	//func(NULL);//NULL为宏定义0
	//int* p = nullptr; //空指针使用nullptr
	//func(p);

	//快速遍历
	int array[]{ 11,22,33,44,55 };
	for (int item : array)
	{
		cout << item << endl;
	}

	return 0;
}