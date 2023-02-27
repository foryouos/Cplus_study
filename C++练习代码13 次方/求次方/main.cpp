#include <iostream>
using namespace std;

double power(double x, int n)
{
	double val = 1.0;
	while (n--)
	{
		val = val * x;
	}
	return val;
}
int power(int x, int n)
{
	int val = 1;
	while (n--)
	{
		val = val * x;
	}
	return val;
}

int main(void)
{
	int n;
	double m;
	cout << "Please input:";
	cin >> n ;
	cout << n << "的立方:" << power(n, 3) << endl;
	cin >> m;
	cout << n << "的立方:" << power(m, 3) << endl;
	return 0;
}