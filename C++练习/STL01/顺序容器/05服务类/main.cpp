/*������*/
#include <iostream>
#include <array>

using namespace std;
template<class T>
void test(T t)
{
	int a[tuple_size<T>::value];// �����ڱ���ʱ
	cout << tuple_size<T>::value << endl;
}
int main(void)
{
	array<float, 3> arr = { 1,2,3 };
	test( arr );
	return 0;
}
/*
3
*/
