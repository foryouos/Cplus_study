#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int a[3][4] =
	{
	  {1, 2, 3, 4},
	  {5, 6, 7, 8},
	  {9,10,11,12}
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++) 
		{
			printf("%-5d",a[i][j]);  //-5d意思是 -代表左对齐，5代表每个元素五个位置
		}
		printf("\n");
	}
	return 0;
}