#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<String.h>
#include<malloc.h>

struct student
{
	int name[20];
	int age;
	int score;
};

//ð����������ṹ��
void sort(struct student* ptrr, int len)
{
	struct student t;
	for (int i = len; i > 0; i--)
	{

		for (int j = 0; j < i; j++)
		{
			if (ptrr[j].score < ptrr[j + 1].score)
				//���ǰ��Ľ��٣��滻λ��
			{
				t = ptrr[j];
				ptrr[j] = ptrr[j + 1];
				ptrr[j + 1] = t;
			}
		}

	}

}


void see_student(student* pst, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("******���������%d��ͬѧ����Ϣ*****\n", i + 1);
		printf("����:%s\t",pst[i].name);
		printf("����:%d\t" ,pst[i].age);
		printf("�ɼ�:%d\t\n", pst[i].score);


	}
}
void add_student(student* pst, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("******���������%d��ͬѧ����Ϣ*****\n", i + 1);
		printf("����������:");
		scanf("%s", &pst[i].name);
		printf("\n");
		printf("����������:");
		scanf("%d", &pst[i].age);
		printf("\n");
		printf("������ɼ�:");
		scanf("%d", &pst[i].score);
		printf("\n");
	}
	
	
}

int main(void)
{
	int len;
	printf("������ѧ������:");
	scanf("%d", &len);
	struct student* ptrr;
	ptrr = (struct student*)malloc(sizeof(struct student) * len);//��̬��������
	add_student(ptrr, len);
	see_student(ptrr, len);
	sort(ptrr, len);
	printf("*******����������ѧ����Ϣ*********\n");
	see_student(ptrr, len);

	return 0;
}

