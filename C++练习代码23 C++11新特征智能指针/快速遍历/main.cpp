#include <iostream>
using namespace std;

void func(int v)
{
	cout << "func(int) - " << v << endl;
}
void func(int* v)
{
	cout << "func(int *) - " << v << endl;
}
int main(void)
{
	//auto a = 10;
	//func(NULL);//NULLΪ�궨��0
	//int* p = nullptr; //��ָ��ʹ��nullptr
	//func(p);

	//���ٱ���
	int array[]{ 11,22,33,44,55 };
	for (int item : array)
	{
		cout << item << endl;
	}

	return 0;
}