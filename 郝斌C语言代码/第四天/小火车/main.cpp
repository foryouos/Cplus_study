#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include "train.h"
void wicket(void) //����cmd������Ϣ
{
	/*
	* ���
	* �߶�
	* ��������ɫ
	* ����
	* 
	*/
}

void forward(int a)
{
	int b = 1;
	while (b <= a)
	{
		printf(" ");
		b++;
	}
}

int main()
{
	//����cmd���ڴ�С�ͱ���
	wicket();
	//���ô��ͷ
	



	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t");
	for (int y = 0; y <= 2; y++)  //������С�����д���
	{
		Sleep(60);
		int a = 0;
		while (a <= 70)
		{
			system("cls");   //���cmd����
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");  //���û��У���λ��
			forward(a); //����aֵ�ո��ƶ�������ǰ
			//ʹ��forѭ������


			printf("%s\n",top_1);
			forward(a);
			printf("%s\n",top_2);
			forward(a);
			printf("%s\n",top_3);
			Sleep(1);
			a ++;
		}
	}
}