//员工工资管理系统头文件
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <wchar.h>
#include <io.h>  //判断文件是否存在
#define filename "staff.txt"  //保存的文件名称
/*
* 存储方案
* 顺序依次为：年份，月份，部门，员工编号
*/
typedef struct
{
	int id; //工号
	char name[20]; //姓名
	char department[20];//部门
	int year;  //年份
	int month;  //月份
	float salary; //应发工资
	float realsalary; //实发工资
}Employee;
//链表结构体
typedef struct Node
{
	Employee data;  //员工信息
	struct Node* next; //下一个节点指针
}Node,*NodeList;
//员工信息链表结构体
typedef struct
{
	struct Node* head; //头结点
	int size; //链表长度
}EmployeeList,*LinkList;


typedef struct average
{
	int id;
	char* name;
	float a_salary;
	struct average* next;
}average;

typedef struct salary
{
	int id;
	char* name;
	float all_salary;
	char* department;//部门
	struct salary* next;
}salary;
//纳税表  计算税率的时候可以初始化此表
//typedef 

// 初始化链表
//存储所有用户数据
LinkList list;

void InsertList(Node* );

//计算税费	参数:工资
float tax(float salary);
//主菜单框架
void menu_frame();
//菜单底部框架
void menu_bottom_frame();

//对用输入进入子菜单进行分配
void menu();
//主菜单无参数输入，返回用户输入的子菜单系统
int main_menu();
//信息录入菜单
void information_menu();
//员工工资查询菜单
void staff_search_menu();
//删除员工信息菜单
void delete_staff_menu();
//工资查询菜单
void staff_salary_search();
//进入统计功能菜单
void staff_statistics();

//文件保存功能 将结构体文件保存到本地
void save_staff(LinkList);
void open_staff_file();
//输出链表
// 输出链表
void printList(LinkList list);
//按年月份升序(同一月工号升序)
void sort_month(LinkList list);
//按照部门降序，实发工资升序
void sort_department(LinkList list);
//根据员工工号删除员工的信息
void delete_id(LinkList list,int id);
//根据姓名搜索所有员工工资信息
void search_name_salary(LinkList list, char name[20]);
//查找部门所有员工信息，按实发工资降序
//传入参数 部门
void dept_staff(LinkList list, char department[20]);
//根据年月，按部门降序输出所有员工工资
//参数链表，年份，月份
void year_month_salary(LinkList list, int year, int month);
//统计部分
//入职以来每个员工的平均工资，升序
void sort_id(LinkList list);
//TODO
void every_staff_average_salary(LinkList list);
//根据年份，总工资前三名，和最后三名
//根据部门输出员工信息，工资降序 得出前三名最高工资，最后三名最低
void dept_max_min(LinkList list,int year);

//参数 ：年月
//输出 ：部门 纳税总额 
//部门升序输出
//计算出每个人的纳税总额
void year_month_tax_all(LinkList list, int year, int month);