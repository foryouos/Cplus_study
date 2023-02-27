#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(void)
{
	double values[] = { 1.23,35.36,653.7,4358.24 };
	string names[] = { "Zoot","Jimmy","AI","Stan" };
	for (int i = 0; i < 4; i++)
	{
		cout << setw(6) << names[i]
			<< setw(10) << values[i] << endl;
	}
	//设置对齐方式
	cout << "设置对齐方式" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << setiosflags(ios_base::left) //左对齐
			<< setw(6) << names[i]
			<< setw(10) << values[i] << endl;
	}
	//输出精度
	cout << "控制输出精度" << endl;
	cout << setiosflags(ios_base::fixed);
	for (int i = 0; i < 4; i++)
	{
		cout << setiosflags(ios_base::left) //左对齐
			<< setw(6) << names[i]
			<< setw(10) << values[i]
			<< resetiosflags(ios_base::left)//清楚左对齐设置
			<< setw(10) << setprecision(1) <<values[i]
			<<endl;
	}

	//输出精度scientific
	cout << "控制输出精度scientific" << endl;
	cout << setiosflags(ios_base::scientific);
	for (int i = 0; i < 4; i++)
	{
		cout << setiosflags(ios_base::left) //左对齐
			<< setw(6) << names[i]
			<< resetiosflags(ios_base::left)//清楚左对齐设置
			<< setw(10) << setprecision(1) << values[i]
			<< endl;
	}

	return 0;
}
/*
  Zoot      1.23
 Jimmy     35.36
	AI     653.7
  Stan   4358.24
设置对齐方式
Zoot  1.23
Jimmy 35.36
AI    653.7
Stan  4358.24
控制输出精度
Zoot  1.230000         1.2
Jimmy 35.4            35.4
AI    653.7          653.7
Stan  4358.2        4358.2
控制输出精度scientific
Zoot  0x1.3ae147ae147aep+0
Jimmy 0x1.1ae147ae147aep+5
AI    0x1.46d999999999ap+9
Stan  0x1.1063d70a3d70ap+12
*/