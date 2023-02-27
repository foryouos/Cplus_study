#include <stdio.h>
//函数定义为inline 即：内联函数
inline char* dbtest(int a)
{
		return (char*)((a % 2 > 0) ? "奇" : "偶");
}
int main()
{
	int i = 0;
	printf("%s\n", "奇");
	for (i = 1; i < 100; i++)
	{
		//printf("i:%d    奇偶性:%s\n", i, (i % 2 > 0) ? "奇" : "偶");
		printf("i:%d    奇偶性:%s\n", i, dbtest(i));
	}
	return 0;
}