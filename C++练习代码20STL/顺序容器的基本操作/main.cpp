#include <iostream>
#include <list>
#include <deque>
using namespace std;
//输出指定顺序容器的元素
template <class T>
//第一个输出字符，第二个传入容器类型常引用
void  printContainer(const char* msg, const T& s)
{
	cout << msg << ":";
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}
int main(void)
{
	//从标准输入读入10个整数，将让门分别从s的头部加入
	deque<int> s;
	for (int i = 0; i < 10; i++)
	{
		int x;
		cin >> x;
		s.push_back(x);
		//将x的数据存入到s当中，每次都加入到开头位置
	}
	printContainer("deque at first", s);
	//用s容器的内容的逆序构造列表容器
	list<int> l(s.rbegin(), s.rend());
	printContainer("list at first", l);
	//将列表容器l的每相邻顺序颠倒 
	list<int>::iterator iter = l.begin();
	while (iter != l.end()) //遍历l
	{
		int v = *iter; //取
		iter = l.erase(iter); //删除该元素
		l.insert(++iter, v);
	}
	printContainer("list at list", l);
	//用列表容器l的内容给s赋值，将s输出
	s.assign(l.begin(), l.end());
	printContainer("deque at last", s);
	return 0;
}
/*
0 9 8 6 4 3 2 1 5 4
deque at first:0 9 8 6 4 3 2 1 5 4
list at first:4 5 1 2 3 4 6 8 9 0
list at list:5 4 2 1 4 3 8 6 0 9
deque at last:5 4 2 1 4 3 8 6 0 9
*/