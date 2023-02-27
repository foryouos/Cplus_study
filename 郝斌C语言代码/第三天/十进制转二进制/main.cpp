#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
* 将十进制转化为二进制
* 两种方式 
* 1，使用数组存储实现倒序
*,2，使用函数递归实现倒序
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
	printf("请输入你要转换成二进制的数:");
	scanf("%d", &n);
	to_binary(n);
	printf("\n");
	return 0;
}