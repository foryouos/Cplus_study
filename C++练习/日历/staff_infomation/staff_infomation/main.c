//Ա����������ϵͳ ���ļ� ����
#include "head.h"
//�������ʼ��

int main()
{
	list = (LinkList)malloc(sizeof(LinkList)+sizeof(Employee)+sizeof(Node));
	list->head = NULL;
	list->size = 0;
	//TODO����ʱ���ļ��������û���Ϣ��ʼ��������
	if (_access(filename, 00)==0) //������ļ���զ
	{
		open_staff_file(list);
	}
	//open_staff_file(list);
	//����Ա����������ϵͳ�˵�
	menu();
	//printf("%.2f\n", tax(9500));

	
}