/*
* project： vector容器语法
*/
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> a;
	//返回当前可容纳元素容量的理论最大值
	cout << "Maximum size of a vector is :" << a.max_size() << endl;
	//capacity返回容器当前已为之分配空间的元素数
	cout << "capacity size of a vector is :" << a.capacity() << endl;
	//增加vector的容量到大约或等于new_cap的值，参数vector的新容量
	a.reserve(10);
	//capacity返回容器当前已为之分配空间的元素数
	cout << "New capacity size of a vector is :" << a.capacity() << endl;
	a = { 1,2,3,4 };
	//请求移除未使用的容量
	a.shrink_to_fit();
	//capacity返回容器当前已为之分配空间的元素数
	cout << "Shrink capacity size of a vector is :" << a.capacity() << endl;
	return 0;
}
/*
Maximum size of a vector is :4611686018427387903
capacity size of a vector is :0
New capacity size of a vector is :10
Shrink capacity size of a vector is :4
*/