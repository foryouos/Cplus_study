#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
/*多级指针*/
void f(int** q)
{
	*q = (int*)malloc(sizeof(int));
	**q = 5;
}
int main(void)
{ 
	int* p;
	f(&p); //要想改编值必须取地址
	printf("%d\n", *p);//

}
/*输出 10*/