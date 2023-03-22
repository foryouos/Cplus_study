#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(void)
{
	//创建关联容器set
	set<int> s{ 1,2,3,4,5,6 };
	//使用set的迭代器，循环遍历
	for_each(s.cbegin(), s.cend(), [](int x) { cout << x << " "; });
	cout << endl;
	//让bool显示未true或false
	cout << boolalpha;
	s.empty();
	cout << "s是否为空:" << s.empty() << endl;
	cout << "s的元素个数:" << s.size() << endl;
	cout << "s可理论容纳的最大数量:" << s.max_size() << endl;
	cout << endl;
	//清除s内容
	s.clear();
	cout << "清除后s是否为空:" << s.empty() << endl;
	//插入元素
	s.insert(s.begin(), 99);
	for_each(s.cbegin(), s.cend(), [](int x) { cout << x << " "; });
	cout << endl;
	return 0;
}
/*
1 2 3 4 5 6
s是否为空:false
s的元素个数:6
s可理论容纳的最大数量:576460752303423487

清除后s是否为空:true
99
*/