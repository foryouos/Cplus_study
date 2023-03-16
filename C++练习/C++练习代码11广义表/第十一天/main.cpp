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
//串的顺序存储结构
typedef struct SString
{
	char ch[MAXLEN + 1];  //存储串的一维数组
	int length;			  //串的当前长度
};
//串的链式存储结构 ，使用单链表--块串结构
typedef struct Chunk   //chunk 块的意思
{
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;
typedef struct LString
{
	Chunk* head, * tail;  //串的头指针和尾指针
	int curlen;		      //串的当前长度
}LString;			      //字符串的块链结构

//串的模式匹配算法---BF算法
int Index_BF(SString S, SString T)
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])  //主串和子串依次匹配下一个字符
		{
			++i;
			++j;
		}
		else                    //主串和子串依次匹配下一个字符
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j >= T.length)
		return i - T.length;  //返回匹配的第一个字符的下标
	else
		return 0;
}
void get_next(SString T, int next[])
{
	int i = 0;
	next[1] = 0;
	int j = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}
void get_nextval(SString T, int nextval[])
{
	int i = 0;
	nextval[1] = 0;
	int j = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i;
			++j;
			if (T.ch[i] != T.ch[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
		{
			j = nextval[j];
		}
	}
}



//KMP算法
int Index_KMP(SString S, SString T,int next[])
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])  //主串和子串依次匹配下一个字符
		{
			++i;
			++j;
		}
		else                    //主串和子串依次匹配下一个字符
		{
			j = next[j];
		}
	}
	if (j >= T.length)
		return i - T.length;  //返回匹配的第一个字符的下标
	else
		return 0;
}









int main(void)
{

}