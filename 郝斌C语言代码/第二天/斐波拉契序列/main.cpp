#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
*	�Ѳ��ɴ�����
*   1 2 3 5 8 13 21 34
*	����ǰ������඼��ǰ������֮��

*/
int main(void)
{
	int n; //����ڼ���ķѲ��ɴ�����
	int f1, f2, f3;
	char ch  ;
	do
		{
			f1 = 1;
			f2 = 2;
			f3 = 3;
			printf("��������Ҫ���ҵķѲ��ɴ����У�");
			scanf("%d", &n);
			if (1 == n)
				printf("%d\n", f1);
			else if (2 == n)
				printf("%d\n",f2);
			else
			{
				for (int i = 3; i <= n; i++)
				{
					f3 = f1 + f2;
					f1 = f2;
					f2 = f3;
				}
				printf("��%d��ķѲ��ɴ�������%d\n", n, f3);
			}
			//system("pause");
			printf("������ֹѭ����Y/N:");
			scanf(" %c", &ch);   // %cǰ����ӿո񣬿ո�����Ʊ�������з���ͳ��Ϊ�հ׷�
			//system("cls");
		} 
	while ('Y' == ch || 'y' == ch );
	return 0;
}