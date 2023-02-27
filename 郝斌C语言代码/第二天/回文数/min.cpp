#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
*	回文数数字正着和倒着结果相同
*   例如：12321
	持续输入循环
	回文数输出yes
	非        NO

*/
int main(void)
{
	int val; //存放回文数
	int sum=0;
	int m;
	while (1) //不断循环
	{
		printf("请输入你要判断的数：");
		scanf("%d", &val);

		m = val;

		while (m)
		{
			sum = sum * 10 + m % 10;
			m = m / 10;
		}
		if (sum == val)  //是回文数
			printf("Yes\n");
		else
			printf("No\n");
		system("pause");  // 暂停输入结果
		system("cls");    //	清空cmd
	}
	return 0;
}