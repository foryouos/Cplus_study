#include <iostream>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	//创建动态内存分配孔家
	int(*cp)[9][8] = new int[n][9][8]; //第一个为表达式，后面为常量
	for (int i = 0; i < 7; i++)
	{
		for (int j= 0; j < 9; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				*(*(*(cp + i) + j) + k) = (i * 100 + j * 10 + k);
			}
		}
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				cout << cp[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	delete[] cp; //释放整个动态多维数组空间

}