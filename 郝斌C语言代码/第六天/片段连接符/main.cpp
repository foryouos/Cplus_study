#include <stdio.h>
//��������Ϊinline ������������
inline char* dbtest(int a)
{
		return (char*)((a % 2 > 0) ? "��" : "ż");
}
int main()
{
	int i = 0;
	printf("%s\n", "��");
	for (i = 1; i < 100; i++)
	{
		//printf("i:%d    ��ż��:%s\n", i, (i % 2 > 0) ? "��" : "ż");
		printf("i:%d    ��ż��:%s\n", i, dbtest(i));
	}
	return 0;
}