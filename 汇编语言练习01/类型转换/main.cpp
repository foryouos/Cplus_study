#include <iostream>
using namespace std;

class Person
{
	virtual void run()
	{

	}
};
class Student : public Person
{

};
class Car
{

};
void test_const()
{
	const Person* p1 = new Person();
	Person* p2 = const_cast<Person*>(p1);
	Person* p3 = (Person*)p1;
/*
	12: 	Person* p2 = const_cast<Person*>(p1);
00007FF773E2197C 48 8B 45 08          mov         rax,qword ptr [rbp+8]
00007FF773E21980 48 89 45 28          mov         qword ptr [rbp+28h],rax
	13: 	Person* p3 = (Person*)p1;
00007FF773E21984 48 8B 45 08          mov         rax,qword ptr [rbp+8]
00007FF773E21988 48 89 45 48          mov         qword ptr [rbp+48h],rax
*/
}
int main(void)
{
	Person* p1 = new Person();
	Person* p2 = new Student();
	cout << "P1 = " << p1 << endl;
	cout << "P2 = " << p2 << endl;
	//���ڶ�̬����ת��student��Personû�ж�̬û���麯���ᱨ��
	//��̫��ȫ��Person��ֵ��student�����ำֵ�����࣬����ȫ
	Student* stu1 = dynamic_cast<Student *>(p1); //����ȫ
	Student* stu2 = dynamic_cast<Student *>(p2); //��ȫ
	//������ʽ��ѵ�ַ��ȫת����
	cout << "stu1 = " << stu1 << endl; //����ȫ����գ���ȫ���
	cout << "stu2 = " << stu2 << endl;
	return 0;
}
/*
P1 = 0000019F7CD6C8B0
P2 = 0000019F7CD6C2C0 
stu1 = 0000000000000000 //p1��ֵʧ��
stu2 = 0000019F7CD6C2C0 //p2�ɹ�

*/