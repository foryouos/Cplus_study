#include <iostream>
using namespace std;
int main(void)
{
	double values[] = { 1.23,35.36,653.7,4358.24 ,124567899};
	for (int i = 0; i < 5; i++)
	{
		//ʹ��width����������
		//ÿ���ַ�10���ֽ�
		cout.width(10); //Ӱ����������ֻӰ��һ��
	}
	return 0;
}
/*
	  1.23
	 35.36
	 653.7
   4358.24
1.24568e+08
*/