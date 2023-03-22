#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(void)
{
	//������������set
	set<int> s{ 1,2,3,4,5,6 };
	//ʹ��set�ĵ�������ѭ������
	for_each(s.cbegin(), s.cend(), [](int x) { cout << x << " "; });
	cout << endl;
	//��bool��ʾδtrue��false
	cout << boolalpha;
	s.empty();
	cout << "s�Ƿ�Ϊ��:" << s.empty() << endl;
	cout << "s��Ԫ�ظ���:" << s.size() << endl;
	cout << "s���������ɵ��������:" << s.max_size() << endl;
	cout << endl;
	//���s����
	s.clear();
	cout << "�����s�Ƿ�Ϊ��:" << s.empty() << endl;
	//����Ԫ��
	s.insert(s.begin(), 99);
	for_each(s.cbegin(), s.cend(), [](int x) { cout << x << " "; });
	cout << endl;
	return 0;
}
/*
1 2 3 4 5 6
s�Ƿ�Ϊ��:false
s��Ԫ�ظ���:6
s���������ɵ��������:576460752303423487

�����s�Ƿ�Ϊ��:true
99
*/