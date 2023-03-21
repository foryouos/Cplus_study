#include <iostream>
#include <array>

using namespace std;

int main(void)
{
	array<int, 3> a;
	array<int, 3> b ;
	//判断是否为空
	cout << boolalpha; //把bool值显示为true或false
	cout << "a.empty() ： " << a.empty() << endl;
	//将所有元素用2填充
	a.fill(2);
	b.fill(6);
	//将a的元素与b元素交换
	a.swap(b);
	//返回a元素个数

	cout << "a.size() :" << a.size() << endl;
	//返回a的所有元素
	cout << "A数组:";
	auto first_ra = a.rbegin();
	auto last_ra = a.rend();
	while (first_ra != last_ra)
	{
		cout << *first_ra << " ";
		first_ra++;
	}
	cout << endl;

	//返回b元素个数
	cout << "b.size() :" << a.size() << endl;
	//返回b的所有元素
	auto first_rb = b.rbegin();
	auto last_rb = b.rend();
	cout << "B数组:";
	while (first_rb != last_rb)
	{
		cout << *first_rb << " ";
		first_rb++;
	}
	cout << endl;
	return 0;
}
/*
a.empty() ： false
a.size() :3
A数组:6 6 6
b.size() :3
B数组:2 2 2
*/