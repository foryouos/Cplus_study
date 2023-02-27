#include <iostream>
#include <vector>		//向量
#include <iterator>  //迭代器
#include <algorithm>  //算法
#include <functional> //函数对象
using namespace std;
int main(void)
{
	const int N = 5;
	vector<int> s(N);  //容器
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
	}
	transform(s.begin(), s.end(), ostream_iterator<int>(cout, "## "), negate<int>());  //算法，negate取相反数
	cout << endl;
	return 0;
}