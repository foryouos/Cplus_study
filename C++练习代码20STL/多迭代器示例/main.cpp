#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;
//将来自输入 迭代器的n个T类型数值排序，将结果 通过输出迭代器result输出
template <class T,class InputIterator,class OutputIterator>

void mySort(InputIterator first,InputIterator last,OutputIterator result)
{
	//通过输入迭代器将输入数据存入向量容器s中
	vector<T> s;
	for (; first != last; ++first)
		//push_back依次插入元素，直到结束
		s.push_back(*first); //将数据放入向量容器s中
	//对s进行排序，sort函数的参数必须是随机访问迭代器
	sort(s.begin(), s.end()); 
	copy(s.begin(), s.end(), result);//将s序列通过输出迭代器输出
}
int main(void)
{
	//将s数组的内容排序后输出
	double a[5] = { 1.2,2.4,0.8,3.3,3.2 };
	mySort<double>(a, a + 5, ostream_iterator<double>(cout, " "));
	cout << endl;
	//从标准输入读入若干整数,ctrl+z结束输入
	mySort<int>(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}