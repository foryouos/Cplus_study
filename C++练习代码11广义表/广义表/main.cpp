#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#define MAXLEN 255  //顺序表的大小
#define CHUNKSIZE 80 //块的大小可由用户定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;   //函数的类型，其值是函数结果的状态代码
typedef int ElemType;

int main(void)
{
	int S = (1,2,3,4,5);
	printf("%d\n", S);
	return 0;
}