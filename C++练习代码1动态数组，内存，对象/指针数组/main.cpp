/*
project:ʹ��const����Ȩ�޹���
*/
#include <iostream>
using namespace std;
const int N = 6;
void print(const int* p, int n) //��const��������ֻ�ж���Ȩ�ޣ������޸�
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