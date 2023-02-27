#include <stdio.h>
int main(void)
{
	char ch = 'A';
	int i = 99;
	double x = 66.6;
	char* p = &ch;
	int* q = &i;
	double* r = &x;
	printf("%d %d %d\n", sizeof(p), sizeof(q), sizeof(r));
	/*输出为
	* 8 8 8
	* 硬件上一个字节一个编号
	*/
	return 0;
}
