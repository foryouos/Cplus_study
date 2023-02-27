#include <stdio.h>
void sort(int* ptrr, int len)
{
	//*ptrr = 99;
	for (int i = len; i > 0; i--)
	{
		//for (int j = 0; j < i; j++)
		//{
		//	if (*(ptrr + j) < *(ptrr + j + 1))//如果前面的较少，替换位置
		//	{
		//		int t = *(ptrr + j);
		//		*(ptrr + j) = *(ptrr + j + 1);
		//		*(ptrr + j + 1) = t;
		//	}
		//}

		for (int j = 0; j < i; j++)
		{
			if (ptrr[j] < ptrr[j + 1])
				//如果前面的较少，替换位置
			{
				int t = ptrr[j];
				ptrr[j] = ptrr[j + 1];
				ptrr[j + 1] = t;
			}
		}

	}

}
int main()
{
	int a[6] = { 10,2,8,-8,11,0 };
	int i = 0;
	sort(a, 6);
	//输出
	for (i = 0; i < 6; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}