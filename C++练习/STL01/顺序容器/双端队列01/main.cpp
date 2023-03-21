#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
	deque<int> a = { 1,2,3,4,5 };
	//
	a.push_back(6);
	a.push_front(5);

	//¥Ú”°
	for (int n : a)
	{
		cout << n << " ";
	}
	cout << endl;
	a.pop_back();
	a.pop_front();
	for (int n : a)
	{
		cout << n << " ";
	}
	cout << endl;
	return 0;

}
/*
5 1 2 3 4 5 6
1 2 3 4 5
*/