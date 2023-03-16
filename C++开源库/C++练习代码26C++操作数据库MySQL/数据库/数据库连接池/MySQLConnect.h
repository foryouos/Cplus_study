#pragma once
#ifndef MYSQLCONNECT_H
#define MYSQLCONNECT_H
#include <iostream>
#include <mysql.h>
using namespace std;
class MySqlConnect
{
private:
	//ʲôʱ������ͷŽ����
	//1,��������2�����ܻ�����ݿ���ж�β�ѯ��ÿ�β�ѯһ�ζ���õ����������ѯ����յ��ϴεĽ����
	void freeResult(); //�ͷŽ����
	MYSQL* m_conn = nullptr; //����MySQL��ʼ����˽�г�Ա
	MYSQL_RES* m_result = nullptr; //��������
	MYSQL_ROW m_row = nullptr; //�����ŵ�ǰ�ֶε������е���ֵ
public:
	//��ʼ�����ݿ�����
	MySqlConnect();
	//�ͷ����ݿ�����
	~MySqlConnect();
	//�������ݿ�,ʹ��Ĭ�϶˿ڿ�ʡ�Զ˿���д
	bool connect(string user, string passwd, string dbName, string ip, unsigned short port = 3306);
	//�������ݿ�(���룬���£�ɾ��)�������ַ���

	bool update(string sql);
	//��ѯ���ݿ�,����query:��ѯ
	bool query(string sql);

	//������ѯ�õ��Ľ����,ÿ��һ�Σ��ӽ������ȡ��һ������

	bool next();
	//�õ�������е��ֶ�ֵ��ȡ��¼�����ֶη���
	string value(int index);
	//����������ر��Զ��ύ
	bool transaction();
	//�ύ����
	bool commit();
	//����ع�;
	bool rollback();
};
#endif // !MYSQLCONNECT_H
