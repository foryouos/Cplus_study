#include <iostream>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	//������̬�ڴ����׼�
	int(*cp)[9][8] = new int[n][9][8]; //��һ��Ϊ���ʽ������Ϊ����
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

	delete[] cp; //�ͷ�������̬��ά����ռ�

}