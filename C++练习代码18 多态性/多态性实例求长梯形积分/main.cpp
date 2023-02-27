/*
主函数
*/
#include <iostream>
#include "Trapzint.h"
#include <iomanip>
using namespace std;

int main(void)
{
	MyFunction f;
	Trapz trapz(f);
	//计算并输出积分结果
	cout << "TRAPZ INT" << setprecision(7) << trapz(0, 2, 1e-7) << endl;
	//setprecision 是 C++ 标准库 <iomanip> 中的一个函数，用于设置浮点数的输出精度
	//若精度不够，会在后面补0
	return 0;
}
/*
* 输出结果
* TRAPZ INT0.5548952
*/