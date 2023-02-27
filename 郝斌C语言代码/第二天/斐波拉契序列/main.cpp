#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
*	费波纳茨序列
*   1 2 3 5 8 13 21 34
*	除了前两项，其余都是前面两项之和

*/
int main(void)
{
	int n; //输出第几项的费波纳茨序列
	int f1, f2, f3;
	char ch  ;
	do
		{
			f1 = 1;
			f2 = 2;
			f3 = 3;
			printf("请输入你要查找的费波纳茨序列：");
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
				printf("第%d项的费波纳茨序列是%d\n", n, f3);
			}
			//system("pause");
			printf("你想终止循环吗？Y/N:");
			scanf(" %c", &ch);   // %c前必须加空格，空格符，制表符，换行符，统称为空白符
			//system("cls");
		} 
	while ('Y' == ch || 'y' == ch );
	return 0;
}