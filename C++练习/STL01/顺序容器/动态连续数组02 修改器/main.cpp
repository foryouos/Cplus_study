#include <iostream>
//project:
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
//��̬�����������
void print(int id, const vector<int>& a)
{
	cout << id << ". ";
	for (const int x : a)
	{
		cout << x << " ";
	}
	cout << endl;
}
int main(void)
{
	//������̬����
	vector<int> c1 (3,100);
	//����Ԫ��
	print(1, c1);
	//��c1��Ԫ�ز���200
	auto it = c1.begin();
	it = c1.insert(it, 200);
	print(2, c1);
	//�����������ֵit��ʼλ�ò�������300
	c1.insert(it, 2, 300);


	print(3, c1);
	//it�Ѿ���ʧЧ���ṩ�µ�����
	it = c1.begin();
	//����c2����
	vector<int>c2(2, 400);
	//��c1�в���it��λ�ò���c2��begin��end
	c1.insert(next(it, 2), c2.begin(), c2.end());
	print(4, c1);

	return 0;
}
/*
1. 100 100 100
2. 200 100 100 100
3. 300 300 200 100 100 100
4. 300 300 400 400 200 100 100 100
*/