/*
project:�Ӹ�������ȡ�����͸�����
*/
#include <iostream>
using namespace std;
void splitFloat(float x, int& intpart, float& fracPart)
{
	intpart = static_cast<int>(x); //ȡx����������
	fracPart = x - intpart; //ȡx��С������
}
int main(void)
{
	cout << "Enter 3 float point numbers:" << endl;
	for (int i = 0; i < 3; i++)
	{
		float x, f;
		int n;
		cin >> x;
		splitFloat(x, n, f);
		cout << "integer Part=" << n << " Fraction Part = " << f << endl;
	}
	return 0;
}
/*
Enter 3 float point numbers:
3.14
integer Part=3 Fraction Part = 0.14
9.7
integer Part=9 Fraction Part = 0.7
5
integer Part=5 Fraction Part = 0
*/
