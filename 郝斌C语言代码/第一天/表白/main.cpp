#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ʵ�ֱ�״��ڲ���
// 2022��12��30��
//systemָ��

int main()
{
	int i = 0;
	char Input[4][60] =
	{
		"����Ů���Ѻ���",
		"�Ժ���Ǯ������",
		"ʲô������˵����",
		"��Ӧ��"
	};

	system("mode con cols=150 lines=30");	//���ô��ڴ�С
	system("color 84");	//���ô�����ɫ
	system("title ���");
	printf("����Ů����");
	while (1)
	{
		//����һ��vbs�ļ�
		FILE* fp = fopen("biaobai.vbs", "w");
		//д��ű�����
		fprintf(fp, "msgbox(\"%s\")", Input[i++]);
		fclose(fp);
		system("biaobai.vbs");//����
		system("del biaobai.vbs");//ɾ��
		if (i == 4)
		{
			i = 0;
		}

	}


	return 0;
}