//array����Ԫ�ط���
#include <iostream>
#include <array>
using namespace std;
int main(void)
{
	array<int,8> a = { 1,2,3,4,5,6,7,8 };
	cout << "at(2)=" << a.at(2) << endl;
	cout << "operator[2]=" << a[2] << endl;
	cout << "��front=" << a.front() << endl;
	cout << "βback=" << a.back() << endl;
	//a.data����array��Ԫ�ص�ַ
	cout << "data =" << a.data()[2] << endl;
	//��������
	for (int i = 0; i < a.size() ; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}