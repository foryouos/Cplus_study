#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include <math.h>
//一元二次方程
int main()
{
	int a;	//二次项系数
	int b;	//一次项系数
	int c;  //常数项
	printf("请分别输入二次项系数，一次项系数，常数（中间空格隔开）\n");
	scanf("%d %d %d", &a, &b, &c);
	float judge;	//根据b的平方-4ac来判断是否有解及解的个数
	judge = b * b - 4 * a * c;
	printf("%f\n", judge);
	float x1, x2; //	方程的解
	if (judge < 0)
	{
		printf("此方程无解\n");
	}
	else if (judge > 0) 
	{
		printf("此方程有两个不同的解\n解为：\n");
		x1 = (-b + sqrt(judge)) / 2 * a;
		x2 = (-b - sqrt(judge)) / 2 * a;
		printf(" X1：%f\n X2: %f\n", x1, x2);
	}
	else  if(judge == 0) 
	{
		printf("此方程有两个相同的解\n");
		x1 = (-b - sqrt(judge)) / 2 * a;
		x2 = (-b + sqrt(judge)) / 2 * a;
		printf(" X1=X2: %f", x1);
	}
	return 0;
}