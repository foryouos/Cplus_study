#include <iostream>
#include <array>

using namespace std;

int main(void)
{
	array<int, 3> a = { 1,2,3 };
	array <int, 0> no;
	//�ж��Ƿ�Ϊ��
	cout << boolalpha; //��boolֵ��ʾΪtrue��false
	cout << "a.empty() �� " << a.empty() << endl;
	cout << "no.empty() �� " << no.empty() << endl;
	//����Ԫ�ظ���
	cout << "a.size() :" << a.size() << endl;
	//����Ԫ�����,����array��С�̶�����size
	cout << "a.max_size() :" << a.max_size() << endl;
	return 0;
}
/*
a.empty() �� false
no.empty() �� true
a.size() :3
a.max_size() :3
*/