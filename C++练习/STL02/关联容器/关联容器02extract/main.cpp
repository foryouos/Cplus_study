#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main(void)
{
	set<int> cont{ 1,2,3 };
	auto print = [](const int& n) { cout << " " << n; };
	for_each(cont.begin(), cont.end(), print);
	cout << endl;
	//C++17.������position��ָ��Ԫ�صĽ�������ռ�����Ľ���
	auto nh = cont.extract(1);
	//�Խ������¸�ֵ
	nh.value() = 4;
	
	for_each(cont.begin(), cont.end(), print);
	cout << endl;
	//��nh��������β��
	cont.insert(move(nh));

	for_each(cont.begin(), cont.end(), print);
	cout << endl;
}
/*
 1 2 3
 2 3
 2 3 4
*/