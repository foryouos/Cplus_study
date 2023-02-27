#include <stdio.h>

int main(void)
{
	int i = 6;
	int j = 5;
	int k;
	k = i << 1;//左移n位，相当于乘以n的二次方
	printf("%d\n", k);  //

	k = i >> 1; //右移相当于除以2
	printf("%d\n", k);  //
	return 0;
}