#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	char name[20];
	char* ptr;
	printf("输入你要输出的值:");
	ptr = fgets(name,20,stdin);
	//fputs(name,stdout);
	puts(name);
	printf("name:%s\n", name);
	printf("ptr:%s\n", ptr);
}
