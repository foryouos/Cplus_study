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
	strcpy(pst->name, "�ں�ˮ");
}
void OuputStudent(struct student*pst)
{
	printf("%s %d\n", pst->name,pst->age);
}
int main()
{
	struct student st = {21,'F',"ƿ�ӵİ���"};
	struct student* pst = &st;
	InputStudent(pst);//�Խṹ���������
	OuputStudent(pst);//�Խṹ��������
	return 0;
}