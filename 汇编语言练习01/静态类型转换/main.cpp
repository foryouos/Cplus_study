#include <iostream>
using namespace std;
int main(void)
{
	int a = 10;
	//С��ģʽ�Ӻ��濪ʼ��
	//������ 0000 1010 0000 0000 0000 0000
	//ʮ������: 0A 00 00 00
	//int a = 10;
	//double�˸��ֽ�,double��int�����ܼ򵥵Ķ�����copy
	// 00 00 00 00 00 00 24 40
	double d = reinterpret_cast<double&>(a);
	//�����ƴ�copy
	cout << "a= " << a << endl;
	cout << "d= " << d << endl;
	return 0;
}
/*
a= 10
d= 8.33713e+80
*/