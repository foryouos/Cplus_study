#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
//存储用户权限和登陆
struct user 
{
	int name;
	char password[20];
};

//学生信息存储结构体
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
	printf("  \n\t\t\t输入0返回主菜单，其它输入返回上一级: ");
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
	printf("  \n\t\t\t查找学生信息\n");
	//......
	//返回主页项目
	if (returnmenu())
	{
		system("cls");
		search_student_meaasge();
	}
}
void update_student_message()
{
	system("cls");
	printf("  \n\t\t\t更新学生信息\n");


	if (returnmenu())
	{
		system("cls");
		update_student_message();
	}
}
void add_student_message()
{
	system("cls");
	printf("  \n\t\t\t增加学生信息\n");

	if (returnmenu())
	{
		system("cls");
		add_student_message();
	}
}
void delete_student_message()
{
	system("cls");
	printf("  \n\t\t\t删除学生信息\n");

	if (returnmenu())
	{
		system("cls");
		delete_student_message();
	}
}
void add_privilege_user()
{
	system("cls");
	printf("  \n\t\t\t增加特权用户\n");

	if (returnmenu())
	{
		system("cls");
		add_privilege_user();
	}
}
void update_privilege_user()
{
	system("cls");
	printf("  \n\t\t\t更新用户特权\n");

	if (returnmenu())
	{
		system("cls");
		update_privilege_user();
	}
}
void see__privilege_user()
{
	system("cls");
	printf("  \n\t\t\t查看用户特权\n");

	if (returnmenu())
	{
		system("cls");
		see__privilege_user();
	}
}
void menus()
{
	int i;//存储用户要进入的系统
	printf("\n\n\t\t*********************\t*******************\t*******************\n");
	printf("\n\t\t*********************\tforyouos学生管理系统\t*******************\n");
	printf("\n\t\t*********************\t*******************\t*******************\n");
	printf("  \n\t\t\t1,查找学生信息\t\t\t2,更新学生信息\t\t\t\t\n");
	printf("  \n\t\t\t3,增加学生信息\t\t\t4,删除学生信息\t\t\t\t\n");
	printf("  \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n");
	printf("  \n\t\t\t5,增加权限用户\t\t\t6，更新用户权限\t\t\t\t\n");
	printf("  \n\t\t\t7,查看特权用户\t\t8,退出学生系统\t\t\t\t\t\n");
	printf("\n\n\t\t\t\t请输入你要进入的系统:");
	scanf("%d", &i);
	//根据switch调用不同函数
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