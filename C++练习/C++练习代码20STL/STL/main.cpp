#include <iostream>
#include <vector>		//����
#include <iterator>  //������
#include <algorithm>  //�㷨
#include <functional> //��������
using namespace std;
int main(void)
{
	const int N = 5;
	vector<int> s(N);  //����
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
	}
	transform(s.begin(), s.end(), ostream_iterator<int>(cout, "## "), negate<int>());  //�㷨��negateȡ�෴��
	cout << endl;
	return 0;
}