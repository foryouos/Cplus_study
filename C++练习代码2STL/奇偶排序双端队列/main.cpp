#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
//ͨ��˫�˶���ʵ����ż����
//�Ȱ��մӴ� С˳������������ٰ��մ�С�� ��˳�����ż��


int main(void)
{
	istream_iterator<int>i1(cin), i2;//����һ��������������
	vector<int>s1(i1, i2);//ͨ������������ӱ�׼����������������
	sort(s1.begin(), s1.end()); //���������������
	deque<int> s2;
	//ѭ������s1
	for (vector<int>::iterator iter = s1.begin(); iter != s1.end(); ++iter)
	{
		if (*iter % 2 == 0)
		{
			s2.push_back(*iter); //ż���ŵ�s2β��
		}
		else
		{
			s2.push_front(*iter); //�����ŵ�s2�ײ�
		}
	}
	//��s2�Ľ�����
	copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}