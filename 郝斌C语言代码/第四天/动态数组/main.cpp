#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
/*�༶ָ��*/
void f(int** q)
{
	*q = (int*)malloc(sizeof(int));
	**q = 5;
}
int main(void)
{ 
	int* p;
	f(&p); //Ҫ��ı�ֵ����ȡ��ַ
	printf("%d\n", *p);//

}
/*��� 10*/