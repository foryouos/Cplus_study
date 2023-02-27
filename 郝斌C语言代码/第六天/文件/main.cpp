#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
	int ch; //用int类型的变量存储EOp
	FILE* fp = NULL; 
	fp = fopen("hello.txt", "w+"); // 打开文件采用读的方式
	if (fp == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//写入一个字符
	fputc('a', fp);
	fclose(fp);
	fp = NULL;
	return 0;
}



/*
while ((ch = getc(fp)) != EOF)
	{
		putchar(ch);
	}*/