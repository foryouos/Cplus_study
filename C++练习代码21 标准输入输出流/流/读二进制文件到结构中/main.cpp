/*
���ļ��ж�һ�������Ƽ�¼��һ���ṹ��
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct SalaryInfo
{
	unsigned id;
	double salary;
};
int main(void)
{
	SalaryInfo employee1 = { 600001,8000 }; //�����ṹ��
	ofstream os("payroll", ios_base::out | ios_base::binary); //�ļ������������������
	//�ַ�ת������С
	os.write(reinterpret_cast<char*>(&employee1), sizeof(employee1)); //���ṹ��д���ļ������
	os.close();
	ifstream is("payroll", ios_base::in | ios_base::binary); //���������ļ������뷽ʽ���������ļ�
	if (is)
	{
		SalaryInfo employee2;
		is.read(reinterpret_cast<char*>(&employee2),sizeof(employee2));
		cout << employee2.id << " " << employee2.salary << endl;
	}
	else
	{
		cout << "ERROR:Cannot open file 'payroll'" << endl;
	}
	is.close();
	return 0;
}