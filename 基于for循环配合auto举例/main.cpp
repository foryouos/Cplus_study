/*
* ���ڷ�Χ��forѭ�����auto����
*/
#include <vector>
#include <iostream>
using namespace std;
int main(void)
{
	vector<int>v = { 1,2,3 };
	/*v.begin(),ָ����Ԫ�صĵ�������������Ϊ��ָ����Ԫ�صġ����͡�ָ��*/
	for (auto i = v.begin(); i != v.end(); ++i) //auto��i�����͸��ݺ����
	{
		cout << *i << endl;
	}
	for (auto e : v)
	{
		cout << e << endl;
	}

}