#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
* ��ʮ����ת��Ϊ������
* ���ַ�ʽ 
* 1��ʹ������洢ʵ�ֵ���
*,2��ʹ�ú����ݹ�ʵ�ֵ���
*/
void to_binary(int m)
{
	int i,j;
	i = m / 2;
	j = m % 2;
	if (i != 0)
	{
		to_binary(i);
	}
	printf("%d", j);
}

int main(void)
{
	int n;
	int i = 0;
	printf("��������Ҫת���ɶ����Ƶ���:");
	scanf("%d", &n);
	to_binary(n);
	printf("\n");
	return 0;
}