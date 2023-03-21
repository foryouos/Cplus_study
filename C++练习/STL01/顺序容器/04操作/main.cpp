#include <iostream>
#include <array>

using namespace std;

int main(void)
{
	array<int, 3> a;
	array<int, 3> b ;
	//�ж��Ƿ�Ϊ��
	cout << boolalpha; //��boolֵ��ʾΪtrue��false
	cout << "a.empty() �� " << a.empty() << endl;
	//������Ԫ����2���
	a.fill(2);
	b.fill(6);
	//��a��Ԫ����bԪ�ؽ���
	a.swap(b);
	//����aԪ�ظ���

	cout << "a.size() :" << a.size() << endl;
	//����a������Ԫ��
	cout << "A����:";
	auto first_ra = a.rbegin();
	auto last_ra = a.rend();
	while (first_ra != last_ra)
	{
		cout << *first_ra << " ";
		first_ra++;
	}
	cout << endl;

	//����bԪ�ظ���
	cout << "b.size() :" << a.size() << endl;
	//����b������Ԫ��
	auto first_rb = b.rbegin();
	auto last_rb = b.rend();
	cout << "B����:";
	while (first_rb != last_rb)
	{
		cout << *first_rb << " ";
		first_rb++;
	}
	cout << endl;
	return 0;
}
/*
a.empty() �� false
a.size() :3
A����:6 6 6
b.size() :3
B����:2 2 2
*/