//array数组元素访问
#include <iostream>
#include <array>
using namespace std;
int main(void)
{
	array<int,8> a = { 1,2,3,4,5,6,7,8 };
	cout << "at(2)=" << a.at(2) << endl;
	cout << "operator[2]=" << a[2] << endl;
	cout << "首front=" << a.front() << endl;
	cout << "尾back=" << a.back() << endl;
	//a.data返回array首元素地址
	cout << "data =" << a.data()[2] << endl;
	//遍历数组
	for (int i = 0; i < a.size() ; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}