#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#define MAXLEN 255  //˳���Ĵ�С
#define CHUNKSIZE 80 //��Ĵ�С�����û�����
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;   //���������ͣ���ֵ�Ǻ��������״̬����
typedef int ElemType;

int main(void)
{
	int S = (1,2,3,4,5);
	printf("%d\n", S);
	return 0;
}