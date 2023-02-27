#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
struct student
{
	int age;
	char sex;
	char name[100];
};
void InputStudent(struct student* pst)
{
	pst->age = 3;
	strcpy(pst->name, "于喝水");
}
void OuputStudent(struct student*pst)
{
	printf("%s %d\n", pst->name,pst->age);
}
int main()
{
	struct student st = {21,'F',"瓶子的跋涉"};
	struct student* pst = &st;
	InputStudent(pst);//对结构体变量输入
	OuputStudent(pst);//对结构体变量输出
	return 0;
}