/*
environment:C++20
*/
#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <string_view>
using namespace std;
template<typename T>
void print(string_view name, T const& q)
{
	cout << name << ": \t";
	for (auto const& n : q)
	{
		cout << n << ' ';
	}
	cout << endl;
}
template<typename Q>
void print_queue(string_view name, Q q)
{
	//注意按照值传递q，这是因为无法再不清楚队列的情况下遍历priority_queue的内容
	for (cout << name << ": \t"; !q.empty(); q.pop())
	{
		cout << q.top() << ' ';
	}
	cout << endl;
}
int main(void)
{
	const auto data = { 1,8,5,6,3,4,0,9,7,2 };
	print("data", data);
	//最大优先队列
	priority_queue<int> q1; 
	for (int n : data)
	{
		//向栈顶插入元素
		q1.push(n);
	}
	print_queue("q1", q1);

	//最小优先队列
	//std::gerater<int>使得最大优先队列的行为变成最小优先队列的行为
	priority_queue<int, vector<int>, greater<int>>
		minq1(data.begin(), data.end());
	print_queue("minq1", minq1);
	return 0;
}
/*
data:   1 8 5 6 3 4 0 9 7 2
q1:     9 8 7 6 5 4 3 2 1 0
minq1:  0 1 2 3 4 5 6 7 8 9
*/