#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main()
{
	int ch; //��int���͵ı����洢EOp
	FILE* fp = NULL; 
	fp = fopen("hello.txt", "w+"); // ���ļ����ö��ķ�ʽ
	if (fp == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	//д��һ���ַ�
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