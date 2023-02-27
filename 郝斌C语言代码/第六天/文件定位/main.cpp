#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>

typedef struct S
{
	char name[10];
	int age;

}Peo;
int main()
{
	FILE* pf = fopen("a.txt", "wb+");

	if (pf != NULL)
	{
		Peo p = { "lisi", 19 };
		fwrite(&p, sizeof(Peo), 2, pf);
		fclose(pf);
		pf = NULL;
	}

	return 0;
}
