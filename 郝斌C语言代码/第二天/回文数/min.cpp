#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
*	�������������ź͵��Ž����ͬ
*   ���磺12321
	��������ѭ��
	���������yes
	��        NO

*/
int main(void)
{
	int val; //��Ż�����
	int sum=0;
	int m;
	while (1) //����ѭ��
	{
		printf("��������Ҫ�жϵ�����");
		scanf("%d", &val);

		m = val;

		while (m)
		{
			sum = sum * 10 + m % 10;
			m = m / 10;
		}
		if (sum == val)  //�ǻ�����
			printf("Yes\n");
		else
			printf("No\n");
		system("pause");  // ��ͣ������
		system("cls");    //	���cmd
	}
	return 0;
}