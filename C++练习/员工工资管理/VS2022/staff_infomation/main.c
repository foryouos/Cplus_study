//Ա����������ϵͳ ���ļ� ����
#include "head.h"
//�������ʼ��

int main()
{
	list = (LinkList)malloc(sizeof(LinkList));
	list->head = NULL;
	list->size = 0;
	//TODO����ʱ���ļ��������û���Ϣ��ʼ��������
	if (_access(filename, 00)==0) //������ļ���զ
	{
		open_staff_file(list);
	}
	//printList(list);

#if 1
	//����Ա����������ϵͳ�˵�
	menu();
#elif 0
	//���Դ���
	//printf("��������");
	//sort_month(list);
	//sort_department(list);
	/*printList(list);
	delete_id(list,10);
	printList(list);*/
	//search_name_salary(list, "���»�");
	//dept_staff(list, "Ӫ����");
	//year_month_salary(list, 2023, 3);
	//ͳ�Ʋ���
	//sort_id(list);
	//every_staff_average_salary(list);
	//dept_max_min(list,2023);
	//year_month_tax_all(list, 2023, 5);
#endif
	return 0;
}