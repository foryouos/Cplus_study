#include <iostream>
#include <array>

using namespace std;

int main(void)
{
	array<int, 3> a = { 1,2,3 };
	array <int, 0> no;
	//判断是否为空
	cout << boolalpha; //把bool值显示为true或false
	cout << "a.empty() ： " << a.empty() << endl;
	cout << "no.empty() ： " << no.empty() << endl;
	//返回元素个数
	cout << "a.size() :" << a.size() << endl;
	//返回元素最大,由于array大小固定等于size
	cout << "a.max_size() :" << a.max_size() << endl;
	return 0;
}
/*
a.empty() ： false
no.empty() ： true
a.size() :3
a.max_size() :3
*/