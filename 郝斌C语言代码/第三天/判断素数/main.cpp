#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
* �ж������������ǳ����ܱ�1���������������ܱ���������������

*/
int main(void)
{
	int n;// �洢����
	printf("��������Ҫ�жϵ���:");
	scanf("%d", &n);
	for (int i = 2; i < n ; i++)
	{
		if (n % i == 0)//�����������Ա�i������û����������������
		{
			printf("%d��������\n", n);
			break;  //ֻҪ��һ��֤��������forѭ��
		}
		else
		{
			if (i == n - 1)
			{
				printf("%d������\n", n);
			}
			continue;
		}
	}

	return 0;
}