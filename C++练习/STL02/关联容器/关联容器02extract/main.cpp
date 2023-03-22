#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main(void)
{
	set<int> cont{ 1,2,3 };
	auto print = [](const int& n) { cout << " " << n; };
	for_each(cont.begin(), cont.end(), print);
	cout << endl;
	//C++17.解链含position所指向元素的结点柄返回占有它的结点柄
	auto nh = cont.extract(1);
	//对结点柄重新赋值
	nh.value() = 4;
	
	for_each(cont.begin(), cont.end(), print);
	cout << endl;
	//将nh结点柄插入尾部
	cont.insert(move(nh));

	for_each(cont.begin(), cont.end(), print);
	cout << endl;
}
/*
 1 2 3
 2 3
 2 3 4
*/