/*
������
*/
#include <iostream>
#include "Trapzint.h"
#include <iomanip>
using namespace std;

int main(void)
{
	MyFunction f;
	Trapz trapz(f);
	//���㲢������ֽ��
	cout << "TRAPZ INT" << setprecision(7) << trapz(0, 2, 1e-7) << endl;
	//setprecision �� C++ ��׼�� <iomanip> �е�һ���������������ø��������������
	//�����Ȳ��������ں��油0
	return 0;
}
/*
* ������
* TRAPZ INT0.5548952
*/