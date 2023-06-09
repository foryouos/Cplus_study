//Ա�����ʹ���ϵͳͷ�ļ�
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

// ��ʼ������
//�洢�����û�����
LinkList list;

void InsertList(Node );

//����˰��	����:����
float tax(double salary);
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