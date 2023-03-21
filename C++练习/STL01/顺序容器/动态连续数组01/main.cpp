/*
* project�� vector�����﷨
*/
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> a;
	//���ص�ǰ������Ԫ���������������ֵ
	cout << "Maximum size of a vector is :" << a.max_size() << endl;
	//capacity����������ǰ��Ϊ֮����ռ��Ԫ����
	cout << "capacity size of a vector is :" << a.capacity() << endl;
	//����vector����������Լ�����new_cap��ֵ������vector��������
	a.reserve(10);
	//capacity����������ǰ��Ϊ֮����ռ��Ԫ����
	cout << "New capacity size of a vector is :" << a.capacity() << endl;
	a = { 1,2,3,4 };
	//�����Ƴ�δʹ�õ�����
	a.shrink_to_fit();
	//capacity����������ǰ��Ϊ֮����ռ��Ԫ����
	cout << "Shrink capacity size of a vector is :" << a.capacity() << endl;
	return 0;
}
/*
Maximum size of a vector is :4611686018427387903
capacity size of a vector is :0
New capacity size of a vector is :10
Shrink capacity size of a vector is :4
*/