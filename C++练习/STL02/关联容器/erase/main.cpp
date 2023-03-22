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
	cout << "ÒÆ³ýËùÓÐÆæÊý£º" << endl;
	for (auto it = c.begin(); it != c.end();)
	{
		if (*it % 2 != 0)
		{
			//²Á³ýÊ×ÔªËØ
			it = c.erase(it);
		}
		else
		{
			++it;
		}
	}
	print();
	cout << "ÒÆ³ý1£¬ÒÆ³ý¸öÊý" << c.erase(1) << endl;
	cout << "ÒÆ³ý2£¬ÒÆ³ý¸öÊý" << c.erase(2) << endl;
	cout << "ÒÆ³ý2£¬ÒÆ³ý¸öÊý" << c.erase(2) << endl;
	print();
	return 0;
}
/*
c={1 2 3 4 }
ÒÆ³ýËùÓÐÆæÊý£º
c={2 4 }
ÒÆ³ý1£¬ÒÆ³ý¸öÊý0
ÒÆ³ý2£¬ÒÆ³ý¸öÊý1
ÒÆ³ý2£¬ÒÆ³ý¸öÊý0
c={4 }
*/