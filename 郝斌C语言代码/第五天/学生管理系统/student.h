#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//�洢�û�Ȩ�޺͵�½
struct user 
{
	int name;
	char password[20];
};

//ѧ����Ϣ�洢�ṹ��
struct student
{
	int num;
	char name[20];
	char gender;
	int tel;
};
bool login();
void menus();
bool returnmenu();
void search_student_meaasge();
void update_student_message();
void add_student_message();
void delete_student_message();

void add_privilege_user();
void update_privilege_user();
void see__privilege_user();

bool returnmenu()
{
	int m;
	printf("  \n\t\t\t����0�������˵����������뷵����һ��: ");
	scanf("%d", &m);
	if (0 == m)
	{
		system("cls");
		menus();
		return false;
	}
	else
	{
		return true;
	}
}
void search_student_meaasge()
{
	system("cls");
	printf("  \n\t\t\t����ѧ����Ϣ\n");
	//......
	//������ҳ��Ŀ
	if (returnmenu())
	{
		system("cls");
		search_student_meaasge();
	}
}
void update_student_message()
{
	system("cls");
	printf("  \n\t\t\t����ѧ����Ϣ\n");


	if (returnmenu())
	{
		system("cls");
		update_student_message();
	}
}
void add_student_message()
{
	system("cls");
	printf("  \n\t\t\t����ѧ����Ϣ\n");

	if (returnmenu())
	{
		system("cls");
		add_student_message();
	}
}
void delete_student_message()
{
	system("cls");
	printf("  \n\t\t\tɾ��ѧ����Ϣ\n");

	if (returnmenu())
	{
		system("cls");
		delete_student_message();
	}
}
void add_privilege_user()
{
	system("cls");
	printf("  \n\t\t\t������Ȩ�û�\n");

	if (returnmenu())
	{
		system("cls");
		add_privilege_user();
	}
}
void update_privilege_user()
{
	system("cls");
	printf("  \n\t\t\t�����û���Ȩ\n");

	if (returnmenu())
	{
		system("cls");
		update_privilege_user();
	}
}
void see__privilege_user()
{
	system("cls");
	printf("  \n\t\t\t�鿴�û���Ȩ\n");

	if (returnmenu())
	{
		system("cls");
		see__privilege_user();
	}
}
void menus()
{
	int i;//�洢�û�Ҫ�����ϵͳ
	printf("\n\n\t\t*********************\t*******************\t*******************\n");
	printf("\n\t\t*********************\tforyouosѧ������ϵͳ\t*******************\n");
	printf("\n\t\t*********************\t*******************\t*******************\n");
	printf("  \n\t\t\t1,����ѧ����Ϣ\t\t\t2,����ѧ����Ϣ\t\t\t\t\n");
	printf("  \n\t\t\t3,����ѧ����Ϣ\t\t\t4,ɾ��ѧ����Ϣ\t\t\t\t\n");
	printf("  \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n");
	printf("  \n\t\t\t5,����Ȩ���û�\t\t\t6�������û�Ȩ��\t\t\t\t\n");
	printf("  \n\t\t\t7,�鿴��Ȩ�û�\t\t8,�˳�ѧ��ϵͳ\t\t\t\t\t\n");
	printf("\n\n\t\t\t\t��������Ҫ�����ϵͳ:");
	scanf("%d", &i);
	//����switch���ò�ͬ����
	switch (i)
	{
	case 1:search_student_meaasge();
	case 2:update_student_message();
	case 3:add_student_message();
	case 4:delete_student_message();
	case 5:add_privilege_user();
	case 6:update_privilege_user();
	case 7:see__privilege_user();
	case 8:break;
	default:
		break;
	}
}