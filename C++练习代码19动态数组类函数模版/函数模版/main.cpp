#include <iostream>
using namespace std;
template <class T> //定义函数模版
void outputArray(const T* array, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << array[i] << " "; //如果数组元素是类的对象，需要该对象所属类重载流插入运算符"<<"
	}
	cout << endl;
}

int main(void)
{
	const int A_count = 8, B_count = 8, C_count = 20;
	int a[A_count] = { 1,2,3,4,5,6,7,8 };
	double b[B_count] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8 };
	char c[C_count] = "welcome";
	cout << "a array contains:" << endl;
	outputArray(a, A_count);
	cout << "b array contains:" << endl;
	outputArray(b, B_count);
	cout << "c array contains:" << endl;
	outputArray(c, C_count);
	return 0;
}
/*
a array contains:
1 2 3 4 5 6 7 8
b array contains:
1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8
c array contains:
w e l c o m e
*/