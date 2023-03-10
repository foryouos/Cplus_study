#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
//通过双端队列实现奇偶排序
//先按照从大到 小顺序输出计数，再按照从小到 大顺序输出偶数


int main(void)
{
	istream_iterator<int>i1(cin), i2;//建立一对输入流迭代器
	vector<int>s1(i1, i2);//通过输入迭代器从标准输入流中输入数据
	sort(s1.begin(), s1.end()); //将输入的整数排序
	deque<int> s2;
	//循环遍历s1
	for (vector<int>::iterator iter = s1.begin(); iter != s1.end(); ++iter)
	{
		if (*iter % 2 == 0)
		{
			s2.push_back(*iter); //偶数放到s2尾部
		}
		else
		{
			s2.push_front(*iter); //奇数放到s2首部
		}
	}
	//将s2的结果输出
	copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}