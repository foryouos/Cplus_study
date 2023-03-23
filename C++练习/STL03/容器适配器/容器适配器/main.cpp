#include <stack>
#include <iostream>
using namespace std;

int main(void)
{
	//创建栈
	stack<int> s;
	//向栈顶插入元素
	s.push(2);
	s.push(6);
	s.push(51);
	//输出栈的数量
	cout << s.size() << " elements on stack\n";
	//访问栈顶元素
	cout << "s Top element:" << s.top() << endl;
	//删除栈顶元素
	s.pop();
	//输出栈的数量
	cout << s.size() << "s elements on stack\n";

	stack<int> a;
	//将s内容与a进行交换
	s.swap(a);
	cout << a.size() << "a elements on stack\n";
	//输出a的栈顶元素
	cout << "a Top element:" << a.top() << endl;
	return 0;
}
/*
3 elements on stack
s Top element:51
2s elements on stack
2a elements on stack
a Top element:6
*/