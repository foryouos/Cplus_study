#include <stdio.h>
int main(void)
{
	char ch = 'A';
	int i = 99;
	double x = 66.6;
	char* p = &ch;
	int* q = &i;
	double* r = &x;
	printf("%d %d %d\n", sizeof(p), sizeof(q), sizeof(r));
	/*���Ϊ
	* 8 8 8
	* Ӳ����һ���ֽ�һ�����
	*/
	return 0;
}
