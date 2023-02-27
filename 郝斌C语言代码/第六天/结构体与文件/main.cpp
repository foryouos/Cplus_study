#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <errno.h>
typedef struct S
{
	char name[10];
	int age;
}stu;
int main()
{
	FILE* pf = fopen("stu.txt", "r");
	if (pf != NULL)
	{
		stu s;
		fscanf(pf, "%s %d", s.name, &s.age);
		printf("%s %d\n", s.name, s.age);
		fclose(pf);
		pf = NULL;
	}
	return 0;
}
