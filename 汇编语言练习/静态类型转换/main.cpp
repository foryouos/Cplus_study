#include <iostream>
using namespace std;
int main(void)
{
	int a = 10;
	//小端模式从后面开始读
	//二进制 0000 1010 0000 0000 0000 0000
	//十六进制: 0A 00 00 00
	//int a = 10;
	//double八个字节,double和int并不能简单的二进制copy
	// 00 00 00 00 00 00 24 40
	double d = reinterpret_cast<double&>(a);
	//二进制纯copy
	cout << "a= " << a << endl;
	cout << "d= " << d << endl;
	return 0;
}
/*
a= 10
d= 8.33713e+80
*/