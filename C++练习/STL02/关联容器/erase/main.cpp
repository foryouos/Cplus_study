#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	set<int> c = { 1,2,3,4,1,2,3,4 };
	auto print = [&c]
	{
		cout << "c={";
		for (int n : c)
		{
			cout << n << " ";
		}
		cout <<"}"<< endl;
	};
	print();
	cout << "�Ƴ�����������" << endl;
	for (auto it = c.begin(); it != c.end();)
	{
		if (*it % 2 != 0)
		{
			//������Ԫ��
			it = c.erase(it);
		}
		else
		{
			++it;
		}
	}
	print();
	cout << "�Ƴ�1���Ƴ�����" << c.erase(1) << endl;
	cout << "�Ƴ�2���Ƴ�����" << c.erase(2) << endl;
	cout << "�Ƴ�2���Ƴ�����" << c.erase(2) << endl;
	print();
	return 0;
}
/*
c={1 2 3 4 }
�Ƴ�����������
c={2 4 }
�Ƴ�1���Ƴ�����0
�Ƴ�2���Ƴ�����1
�Ƴ�2���Ƴ�����0
c={4 }
*/