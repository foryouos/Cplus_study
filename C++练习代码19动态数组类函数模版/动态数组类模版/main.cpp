/*��2~N�е�����*/
#include "Array.h"
#include <iostream>
#include <iomanip>
using namespace std;
void read(int* p, int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
}
int main(void)
{
	//����������������飬��ʼ״̬��10��Ԫ��
	Array<int>a(3);
	//read(a, 10);
	int n, count = 0;
	cout << "Enter a value > = 2 as upper limit for prime number:";
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		bool isPrime = true;  //Ĭ��i������
		for (int j = 0; j < count; j++)  //�ж��Ƿ�Ϊ����
		{
			if (i % a[j] == 0) //���
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			if (count == a.getSize())
				a.resize(count * 2);
			a[count++] = i;
		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << setw(8) << a[i];
	}
	cout << endl;
	return 0;
}