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
//����˳��洢�ṹ
typedef struct SString
{
	char ch[MAXLEN + 1];  //�洢����һά����
	int length;			  //���ĵ�ǰ����
};
//������ʽ�洢�ṹ ��ʹ�õ�����--�鴮�ṹ
typedef struct Chunk   //chunk �����˼
{
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;
typedef struct LString
{
	Chunk* head, * tail;  //����ͷָ���βָ��
	int curlen;		      //���ĵ�ǰ����
}LString;			      //�ַ����Ŀ����ṹ

//����ģʽƥ���㷨---BF�㷨
int Index_BF(SString S, SString T)
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])  //�������Ӵ�����ƥ����һ���ַ�
		{
			++i;
			++j;
		}
		else                    //�������Ӵ�����ƥ����һ���ַ�
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j >= T.length)
		return i - T.length;  //����ƥ��ĵ�һ���ַ����±�
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



//KMP�㷨
int Index_KMP(SString S, SString T,int next[])
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])  //�������Ӵ�����ƥ����һ���ַ�
		{
			++i;
			++j;
		}
		else                    //�������Ӵ�����ƥ����һ���ַ�
		{
			j = next[j];
		}
	}
	if (j >= T.length)
		return i - T.length;  //����ƥ��ĵ�һ���ַ����±�
	else
		return 0;
}









int main(void)
{

}