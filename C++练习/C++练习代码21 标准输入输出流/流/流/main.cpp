#include <iostream>
using namespace std;
int main(void)
{
	double values[] = { 1.23,35.36,653.7,4358.24 ,124567899};
	for (int i = 0; i < 5; i++)
	{
		//使用width控制输出宽度
		//每个字符10个字节
		cout.width(10); //影响其后的输出项，只影响一个
	}
	return 0;
}
/*
	  1.23
	 35.36
	 653.7
   4358.24
1.24568e+08
*/