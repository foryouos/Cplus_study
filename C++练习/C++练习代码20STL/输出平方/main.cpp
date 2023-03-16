#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

//求平方的函数
double square(double x)
{
	return x * x;
}
int main(void)
{
	//从标准输入读入若干个实数，分别将它们的平方输出
	transform(istream_iterator<double>(cin), istream_iterator<double>(), ostream_iterator<double>(cout, "\t"), square);
	//头，尾，写入结果，函数处理
	//头：输入流迭代器，double， 关联到cin
	//尾没有构造函数，不给为空，----指向输入流结束
	//写入结果:cout
	//函数处理:square

	cout << endl;
}