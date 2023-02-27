#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include "train.h"
void wicket(void) //设置cmd窗口信息
{
	/*
	* 宽度
	* 高度
	* 背景和颜色
	* 标题
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
	//设置cmd窗口大小和背景
	wicket();
	//设置大火车头
	



	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t");
	for (int y = 0; y <= 2; y++)  //控制着小火车运行次数
	{
		Sleep(60);
		int a = 0;
		while (a <= 70)
		{
			system("cls");   //清空cmd窗口
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");  //设置换行，火车位置
			forward(a); //根据a值空格，推动火车逐步往前
			//使用for循环遍历


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