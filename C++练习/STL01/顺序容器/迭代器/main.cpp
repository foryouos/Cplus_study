//array的迭代器
#include <iostream>
#include <array>

using namespace std;

int main(void)
{
	array<int,6> a = { 1,2,3,4,5,6 };
	//打印首元素
	//cout << *a.begin() << endl;

	//打印所有元素
	//for_each(a.cbegin(), a.cend(), 
	//	[](int x){
	//		cout << x << " ";
	//	});
	//cout << "\n";
	////不加c
	//for_each(a.begin(), a.end(),
	//	[](int x)
	//	{
	//		cout << x << " ";
	//	});
	//cout << "\n";
	//使用while正序
	auto first = a.cbegin();
	auto last = a.cend();
	while (first != last)
	{
		cout << *first << " ";
		(first)++;
	}
	cout << endl;
	//逆序r
	//使用while
	auto first_r = a.rbegin();
	auto last_r = a.rend();
	while (first_r !=last_r)
	{
		cout << *first_r << " ";
		first_r++;
	}
	cout << endl;

	return 0;
}
//输出
/*
1 2 3 4 5 6
6 5 4 3 2 1
*/

