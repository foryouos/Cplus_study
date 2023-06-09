//Ա�����ʹ���ϵͳͷ�ļ�
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <wchar.h>
#include <io.h>  //�ж��ļ��Ƿ����
#define filename "staff.txt"  //������ļ�����
/*
* �洢����
* ˳������Ϊ����ݣ��·ݣ����ţ�Ա�����
*/
typedef struct
{
	int id; //����
	char name[20]; //����
	char department[20];//����
	int year;  //���
	int month;  //�·�
	float salary; //Ӧ������
	float realsalary; //ʵ������
}Employee;
//����ṹ��
typedef struct Node
{
	Employee data;  //Ա����Ϣ
	struct Node* next; //��һ���ڵ�ָ��
}Node,*NodeList;
//Ա����Ϣ����ṹ��
typedef struct
{
	struct Node* head; //ͷ���
	int size; //������
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
	char* department;//����
	struct salary* next;
}salary;
//��˰��  ����˰�ʵ�ʱ����Գ�ʼ���˱�
//typedef 

// ��ʼ������
//�洢�����û�����
LinkList list;

void InsertList(Node* );

//����˰��	����:����
float tax(float salary);
//���˵����
void menu_frame();
//�˵��ײ����
void menu_bottom_frame();

//������������Ӳ˵����з���
void menu();
//���˵��޲������룬�����û�������Ӳ˵�ϵͳ
int main_menu();
//��Ϣ¼��˵�
void information_menu();
//Ա�����ʲ�ѯ�˵�
void staff_search_menu();
//ɾ��Ա����Ϣ�˵�
void delete_staff_menu();
//���ʲ�ѯ�˵�
void staff_salary_search();
//����ͳ�ƹ��ܲ˵�
void staff_statistics();

//�ļ����湦�� ���ṹ���ļ����浽����
void save_staff(LinkList);
void open_staff_file();
//�������
// �������
void printList(LinkList list);
//�����·�����(ͬһ�¹�������)
void sort_month(LinkList list);
//���ղ��Ž���ʵ����������
void sort_department(LinkList list);
//����Ա������ɾ��Ա������Ϣ
void delete_id(LinkList list,int id);
//����������������Ա��������Ϣ
void search_name_salary(LinkList list, char name[20]);
//���Ҳ�������Ա����Ϣ����ʵ�����ʽ���
//������� ����
void dept_staff(LinkList list, char department[20]);
//�������£������Ž����������Ա������
//����������ݣ��·�
void year_month_salary(LinkList list, int year, int month);
//ͳ�Ʋ���
//��ְ����ÿ��Ա����ƽ�����ʣ�����
void sort_id(LinkList list);
//TODO
void every_staff_average_salary(LinkList list);
//������ݣ��ܹ���ǰ���������������
//���ݲ������Ա����Ϣ�����ʽ��� �ó�ǰ������߹��ʣ�����������
void dept_max_min(LinkList list,int year);

//���� ������
//��� ������ ��˰�ܶ� 
//�����������
//�����ÿ���˵���˰�ܶ�
void year_month_tax_all(LinkList list, int year, int month);