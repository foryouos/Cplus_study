#include <iostream>
//project:
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
//动态数组输出函数
void print(int id, const vector<int>& a)
{
	cout << id << ". ";
	for (const int x : a)
	{
		cout << x << " ";
	}
	cout << endl;
}
int main(void)
{
	//创建动态数组
	vector<int> c1 (3,100);
	//插入元素
	print(1, c1);
	//在c1受元素插入200
	auto it = c1.begin();
	it = c1.insert(it, 200);
	print(2, c1);
	//将上面的两个值it初始位置插入两个300
	c1.insert(it, 2, 300);


	print(3, c1);
	//it已经是失效，提供新迭代器
	it = c1.begin();
	//创建c2数组
	vector<int>c2(2, 400);
	//在c1中插入it的位置插入c2从begin到end
	c1.insert(next(it, 2), c2.begin(), c2.end());
	print(4, c1);

	return 0;
}
/*
1. 100 100 100
2. 200 100 100 100
3. 300 300 200 100 100 100
4. 300 300 400 400 200 100 100 100
*/