#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//实现表白窗口操作
// 2022年12月30号
//system指令

int main()
{
	int i = 0;
	char Input[4][60] =
	{
		"做我女朋友好吗？",
		"以后挣钱都给你",
		"什么都是你说了算",
		"答应吧"
	};

	system("mode con cols=150 lines=30");	//设置窗口大小
	system("color 84");	//设置窗口颜色
	system("title 表白");
	printf("做我女朋友");
	while (1)
	{
		//创建一个vbs文件
		FILE* fp = fopen("biaobai.vbs", "w");
		//写入脚本语言
		fprintf(fp, "msgbox(\"%s\")", Input[i++]);
		fclose(fp);
		system("biaobai.vbs");//运行
		system("del biaobai.vbs");//删除
		if (i == 4)
		{
			i = 0;
		}

	}


	return 0;
}