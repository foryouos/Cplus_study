#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
struct student //���������  �ṹ��//��һ�ַ�ʽ
{
	char name[30];
	int age;
	float score;
	char sex;
};
int main(void)
{
	struct student st = {"yuheshui",80,66.6F,'F'};  // �ṹ�����
	struct student* pst = &st;
	pst->age = 99;//�ڶ��ַ�ʽ  
	/* 
	pst->age �ڼ�����ڲ��ᱻת���ɣ�*pst).age 
	*/
	st.age = 10;//��һ�ַ�ʽ
	struct student st2;
	strcpy(st2.name, "foryouos");
	//st2.name = "foryouos";  //����������ַ�ǳ������Ǳ�����Ҳ����ֱ�Ӹ�ֵ
	st2.age = 10;
	st2.score = 88.6f;  //88.6��C������Ĭ����double���ͣ�
	//���ϣ��һ��ʵ����float���ͣ��������ĩλ��f��F�����88.6f��88.6F ��float����

	st2.sex = 'F';
	printf("%s %d %f %c\n",st.name, st.age, st.score, st.sex);
	printf("%s %d %f %c\n", st2.name, st2.age, st2.score, st2.sex);
	return 0;
}