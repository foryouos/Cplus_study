#include <iostream>
using namespace std;

struct Person
{
	int m_age;
};
Person g_person;  //ȫ�ֱ�����ʼ��Ϊ0
int g_age;  //ȫ�ֱ���Ĭ�ϳ�ʼ��Ϊ 0
int main(void)
{
	//Person person; //�ѿռ䣺û�г�ʼ����Ա����

	//�ѿռ�:û�г�ʼ����Ա����
	Person* p0 = new Person;
	//�ѿռ�:��Ա������ʼ��Ϊ0��//����й��캯���򲻽��г�ʼ��
	Person* p1 = new Person();
	cout << g_age << endl;
	cout << g_person.m_age << endl;
	//cout << person.m_age << endl;
	cout << p0->m_age << endl;
	cout << p1->m_age << endl;

	return 0;
}
/*���:
0
0
-842150451
0
*/