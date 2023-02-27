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

//冒泡排序数组结构体
void sort(struct student* ptrr, int len)
{
	struct student t;
	for (int i = len; i > 0; i--)
	{

		for (int j = 0; j < i; j++)
		{
			if (ptrr[j].score < ptrr[j + 1].score)
				//如果前面的较少，替换位置
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
		printf("******正在输出第%d名同学的信息*****\n", i + 1);
		printf("姓名:%s\t",pst[i].name);
		printf("年龄:%d\t" ,pst[i].age);
		printf("成绩:%d\t\n", pst[i].score);


	}
}
void add_student(student* pst, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("******正在输入第%d名同学的信息*****\n", i + 1);
		printf("请输入姓名:");
		scanf("%s", &pst[i].name);
		printf("\n");
		printf("请输入年龄:");
		scanf("%d", &pst[i].age);
		printf("\n");
		printf("请输入成绩:");
		scanf("%d", &pst[i].score);
		printf("\n");
	}
	
	
}

int main(void)
{
	int len;
	printf("请输入学生数量:");
	scanf("%d", &len);
	struct student* ptrr;
	ptrr = (struct student*)malloc(sizeof(struct student) * len);//动态数组申请
	add_student(ptrr, len);
	see_student(ptrr, len);
	sort(ptrr, len);
	printf("*******输出排序过的学生信息*********\n");
	see_student(ptrr, len);

	return 0;
}

