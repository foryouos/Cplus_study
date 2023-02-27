#include <iostream>
#include <list>
#include <deque>
using namespace std;
//���ָ��˳��������Ԫ��
template <class T>
//��һ������ַ����ڶ��������������ͳ�����
void  printContainer(const char* msg, const T& s)
{
	cout << msg << ":";
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}
int main(void)
{
	//�ӱ�׼�������10�������������ŷֱ��s��ͷ������
	deque<int> s;
	for (int i = 0; i < 10; i++)
	{
		int x;
		cin >> x;
		s.push_back(x);
		//��x�����ݴ��뵽s���У�ÿ�ζ����뵽��ͷλ��
	}
	printContainer("deque at first", s);
	//��s���������ݵ��������б�����
	list<int> l(s.rbegin(), s.rend());
	printContainer("list at first", l);
	//���б�����l��ÿ����˳��ߵ� 
	list<int>::iterator iter = l.begin();
	while (iter != l.end()) //����l
	{
		int v = *iter; //ȡ
		iter = l.erase(iter); //ɾ����Ԫ��
		l.insert(++iter, v);
	}
	printContainer("list at list", l);
	//���б�����l�����ݸ�s��ֵ����s���
	s.assign(l.begin(), l.end());
	printContainer("deque at last", s);
	return 0;
}
/*
0 9 8 6 4 3 2 1 5 4
deque at first:0 9 8 6 4 3 2 1 5 4
list at first:4 5 1 2 3 4 6 8 9 0
list at list:5 4 2 1 4 3 8 6 0 9
deque at last:5 4 2 1 4 3 8 6 0 9
*/