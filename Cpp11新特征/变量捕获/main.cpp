#include <iostream>
using namespace std;

int exec(int v1, int v2, int (*func)(int, int))
{
	return func(v1, v2);
}


int main(void)
{
	int a = 10;
	//int b = 10;
	//auto func = [a, b]
	//{
	//	cout << a << endl;
	//	cout << b << endl;
	//};
	//a = 20;
	//func(); //ֵ���񣬲�û�л�ȡ���µ�aֵ

	//auto func = [&a] //ʹ�õ�ַ���񣬿��Ա�֤��ȡ���µ�aֵ
	//{
	//	cout << a << endl;
	//};

	//a = 70; 
	//func(); //��ַ�����ȡ����ֵ

	//ֵ�����ܼӼ�
	//auto func = [a]
	//{
	//	a++; //ֵ������++
	//};
	//func();
	//��ַ�������
	//auto func = [&a]
	//{
	//	a++;
	//};
	//func();
	// cout << a << endl; //ֵa+1
	//mutable 
	auto func = [a] () mutable //�ڲ�a�������
	{
		int b = a;
		b++;
		cout << "lambda = " << b << endl;
	};
	func();
	cout << a << endl;


	return 0;
}