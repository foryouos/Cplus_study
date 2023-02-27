#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
* 判断素数：素数是除了能被1和自身整除，不能被其它数整除的数

*/
int main(void)
{
	int n;// 存储素数
	printf("请输入你要判断的数:");
	scanf("%d", &n);
	for (int i = 2; i < n ; i++)
	{
		if (n % i == 0)//代表整数可以被i整除，没有余数，则不是素数
		{
			printf("%d不是素数\n", n);
			break;  //只要有一个证明就跳出for循环
		}
		else
		{
			if (i == n - 1)
			{
				printf("%d是素数\n", n);
			}
			continue;
		}
	}

	return 0;
}