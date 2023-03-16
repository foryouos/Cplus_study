#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
int main(void)
{
	string names1[] = { "Alice","helen","lucy","Susan" };
	string names2[] = { "Bob","David","Levin","Mike" };
	//��names1��������ݹ����б�s1
	list<string> s1(names1, names1 + 4);
	//��names2��������ݹ����б�s2
	list<string> s2(names2, names2 + 4);

	//��s1�ĵ�һ��Ԫ�طŵ�s2�����
	s2.splice(s2.end(), s1, s1.begin());
	list<string>::iterator iter1 = s1.begin(); //iter1ָ��s1��
	advance(iter1, 2);//iter1ǰ��2��Ԫ�أ�����ָ��s1������Ԫ��
	list<string>::iterator iter2 = s2.begin(); //iter2ָ��s2��
	++iter2; //iter2ǰ��һ��Ԫ�أ�����ָ��s2�ĵڶ���Ԫ��
	list<string>::iterator iter3 = iter2; //��iter2��ʼ��iter3
	advance(iter3, 2);//iter3ǰ��2��Ԫ�أ�����ָ��s2�ĵ�4��Ԫ��
	//��[iter2,iter3)��Χ�ڵĽ��ӵ�s1��iter1ָ��Ľ��ǰ
	s1.splice(iter1, s2, iter2, iter3);
	//�ֱ�s1��s2���
	copy(s1.begin(), s1.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	copy(s2.begin(), s2.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
	return 0;
}
/*
helen lucy David Levin Susan
Bob Mike Alice
*/
