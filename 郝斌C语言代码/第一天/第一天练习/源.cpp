#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include <math.h>
//һԪ���η���
int main()
{
	int a;	//������ϵ��
	int b;	//һ����ϵ��
	int c;  //������
	printf("��ֱ����������ϵ����һ����ϵ�����������м�ո������\n");
	scanf("%d %d %d", &a, &b, &c);
	float judge;	//����b��ƽ��-4ac���ж��Ƿ��н⼰��ĸ���
	judge = b * b - 4 * a * c;
	printf("%f\n", judge);
	float x1, x2; //	���̵Ľ�
	if (judge < 0)
	{
		printf("�˷����޽�\n");
	}
	else if (judge > 0) 
	{
		printf("�˷�����������ͬ�Ľ�\n��Ϊ��\n");
		x1 = (-b + sqrt(judge)) / 2 * a;
		x2 = (-b - sqrt(judge)) / 2 * a;
		printf(" X1��%f\n X2: %f\n", x1, x2);
	}
	else  if(judge == 0) 
	{
		printf("�˷�����������ͬ�Ľ�\n");
		x1 = (-b - sqrt(judge)) / 2 * a;
		x2 = (-b + sqrt(judge)) / 2 * a;
		printf(" X1=X2: %f", x1);
	}
	return 0;
}