#include <iostream>
#include <set>
using namespace std;

int main(void)
{
	set<char>
		p{ 'A', 'C','B','B','A' },
		q{ 'E','D','E','C' };
	//返回A的数量
	cout << p.count('A') << endl;
	cout << p.count('C') << endl;
}
