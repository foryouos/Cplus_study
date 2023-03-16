/*
project:使用const进行权限管理
*/
#include <iostream>
using namespace std;
const int N = 6;
void print(const int* p, int n) //加const常量，其只有读的权限，不能修改
{
	cout << "{" << *p;
	for (int i = 1; i < n; i++)
	{
		cout << "," << *(p + i);
	}
	cout << "}" << endl;
}
int main(void)
{
	int array[N];
	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
	}
	print(array, N);
	return 0;
}
/*1 2 3 4 5 6
{1,2,3,4,5,6}
*/