#include <iostream>
//C++��׼���������б�ʶ������������std�����ռ���
using namespace std;
int i =1; //iΪȫ�ֱ���
void other()
{
	//a,bΪ��̬ȫ�ֱ���������ȫ���������ֲ��ɼ���ֻ��һ�ν��뺯��ʱ����ʼ��
	static int a = 2;
	static int b;
	//cΪ�ֲ�����
	int c = 10;
	a += 2;  //4
	i += 32; //33
	c += 5;  //15
	cout << "---- - other----" << endl;
	cout << " i��" << i << " a:" << a << " b:" << b << " c" << c << endl;
}
int main(void)
{

	//aΪ��̬�ֲ�����������ȫ�� �������ֲ��ɼ�
	static int a;
	//b,cΪ�ֲ����������ж�̬������
	int b = -10;
	int c = 0;
	cout << "����----main----" << endl;
	//i=1,aĬ��Ϊ0��b=-10,c=0
	cout << " i��" << i << " a:" << a << " b:" << b << " c" << c << endl;
	c += 8;  //c=8

	other();

	cout << "����----main----" << endl;
	cout << " i��" << i << " a:" << a << " b:" << b << " c" << c << endl;
	i += 10;
	other();

	return 0;
}