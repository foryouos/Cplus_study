#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	vector<int> a = { 1,2,3 };
	for (const auto& el : a)
	{
		cout << el << " ";
	}
	cout << endl;

	//���Ӵ�С,����ĸ�ֵΪ0
	a.resize(5);
	for (const auto& el : a)
	{
		cout << el << " ";
	}
	cout << endl;
	//��ӵ�7����ֵΪ6
	a.resize(7,6);
	for (const auto& el : a)
	{
		cout << el << " ";
	}
	cout << endl;

}
/*
1 2 3
1 2 3 0 0
1 2 3 0 0 6 6
*/