#include <iostream>
using namespace std;
struct Person
{
	int m_age;

	Person()
	{
		cout << "Person()" << endl;
	}
	~Person()
	{
		cout << "�ͷ�Person()" << endl;
	}
};
int main(void)
{
	Person person; //�����Ĭ�Ϲ��캯��
	Person* p = new Person; //����ռ�Ҳ�����Ĭ�Ϲ��캯��
	delete p;
	//malloc��������Ĭ�Ϲ��캯��,
	Person* q = (Person*)malloc(sizeof(Person));
	free(q); //Ҳ���������������
	return 0;
}