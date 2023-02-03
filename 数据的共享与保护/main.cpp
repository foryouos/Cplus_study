#include <iostream>
//C++标准程序库的所有标识符都被声明在std命名空间内
using namespace std;
int i =1; //i为全局变量
void other()
{
	//a,b为静态全局变量，具有全局寿命，局部可见，只第一次进入函数时被初始化
	static int a = 2;
	static int b;
	//c为局部变量
	int c = 10;
	a += 2;  //4
	i += 32; //33
	c += 5;  //15
	cout << "---- - other----" << endl;
	cout << " i：" << i << " a:" << a << " b:" << b << " c" << c << endl;
}
int main(void)
{

	//a为静态局部变量，具有全局 寿命，局部可见
	static int a;
	//b,c为局部变量，具有动态生存期
	int b = -10;
	int c = 0;
	cout << "——----main----" << endl;
	//i=1,a默认为0，b=-10,c=0
	cout << " i：" << i << " a:" << a << " b:" << b << " c" << c << endl;
	c += 8;  //c=8

	other();

	cout << "——----main----" << endl;
	cout << " i：" << i << " a:" << a << " b:" << b << " c" << c << endl;
	i += 10;
	other();

	return 0;
}