//array�ĵ�����
#include <iostream>
#include <array>

using namespace std;

int main(void)
{
	array<int,6> a = { 1,2,3,4,5,6 };
	//��ӡ��Ԫ��
	//cout << *a.begin() << endl;

	//��ӡ����Ԫ��
	//for_each(a.cbegin(), a.cend(), 
	//	[](int x){
	//		cout << x << " ";
	//	});
	//cout << "\n";
	////����c
	//for_each(a.begin(), a.end(),
	//	[](int x)
	//	{
	//		cout << x << " ";
	//	});
	//cout << "\n";
	//ʹ��while����
	auto first = a.cbegin();
	auto last = a.cend();
	while (first != last)
	{
		cout << *first << " ";
		(first)++;
	}
	cout << endl;
	//����r
	//ʹ��while
	auto first_r = a.rbegin();
	auto last_r = a.rend();
	while (first_r !=last_r)
	{
		cout << *first_r << " ";
		first_r++;
	}
	cout << endl;

	return 0;
}
//���
/*
1 2 3 4 5 6
6 5 4 3 2 1
*/

