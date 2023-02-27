/*
* 基于范围的for循环配合auto举例
*/
#include <vector>
#include <iostream>
using namespace std;
int main(void)
{
	vector<int>v = { 1,2,3 };
	/*v.begin(),指向首元素的迭代器，可以认为是指向首元素的“泛型”指针*/
	for (auto i = v.begin(); i != v.end(); ++i) //auto是i的类型根据后面变
	{
		cout << *i << endl;
	}
	for (auto e : v)
	{
		cout << e << endl;
	}

}