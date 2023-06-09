//Ա�����ʹ���ϵͳ�㷨ʵ�ֺ���
#include "head.h"
float tax(float salary)
{
	//ǿ��ȡ����
	//int t_salary = (int)salary;
	float tax_need; //��Ҫ����˰��
	//ʹ��switch���ݲ�ͬ���ʼ����������Ҫ�Ľ���money
	 //��������Ϊ����
	//����5000������ó��Ľ�����ж���˰������
	//˰�ʼ���ʹ�ó����۽�˰��
	if (salary <= 5000)
	{
		tax_need = 0;
	}
	else if (salary > 5000 && salary <= 8000)
	{
		tax_need = (salary - 5000) * 0.03;
	}
	else if (salary > 8000 && salary <= 17000) 
	{
		//���ʴ���8000С��17000
		//5000~8000����3%˰�ʣ�����8000�Ĳ��ְ���10%
		tax_need = (8000 - 5000) * 0.03 + (salary - 8000) * 0.1;

	}
	else if (salary > 17000 && salary <= 30000)
	{
		//������17000��30000֮��
		tax_need = (8000-5000) * 0.03 + (17000 - 8000) * 0.1 + (salary - 17000)*0.2;
	}
	else if (salary > 30000 && salary <= 40000)
	{
		//������30000��40000֮��
		tax_need = (8000 - 5000) * 0.03 + (17000 - 8000) * 0.1 + (30000 - 17000) * 0.2 
			+ (salary - 30000) * 0.25;
	}
	else if (salary > 40000 && salary <= 60000)
	{
		//������4�� ��6��֮��
		tax_need = (8000 - 5000) * 0.03 + (17000 - 8000) * 0.1 + (30000 - 17000) * 0.24 
			+ (40000 - 30000) * 0.25 + (salary - 40000) * 0.3;
	}
	else if (salary > 60000 && salary <= 85000)
	{
		//������6�� ��8.5��֮��
		tax_need = (8000 - 5000) * 0.03 + (17000 - 8000) * 0.1 + (30000 - 17000) * 0.2 
			+ (40000 - 30000) * 0.25 + (60000 - 40000) * 0.3 + (salary - 60000) * 0.35;
	}
	else if (salary > 85000)
	{
		//���ʴ���8.5��Ĳ���45%
		tax_need = (8000 - 5000) * 0.03 + (17000 - 8000) * 0.1 + (30000 - 17000) * 0.2 
			+ (40000 - 30000) * 0.25 + (60000 - 40000) * 0.3 + (85000 - 60000) * 0.35 
			+ (salary - 85000) * 0.45;
	}
	return tax_need;
}
//���ڵ����ݲ��뵽list����
void InsertList(Node* n)
{
	Node *n_list = (Node*)malloc(sizeof(Node));
	n_list = n;
	n_list->next = NULL;
	LinkList listIsert = list;
	//list�е��ܳ���+1
	if (listIsert->head == NULL)
	{
		listIsert->size++;
		listIsert->head = n_list;
		return;
	}
	Node* N_list = (NodeList)malloc(sizeof(NodeList));;
	N_list = NULL;
	N_list = listIsert->head;
	//����n����Ϣ�жϲ���λ��
	for (int i = 0; i < listIsert->size; i++)
	{
		if (n_list->data.id <= N_list->data.id  )
		{
			n_list->next = N_list;
			//N_list = &n;
			listIsert->head = n_list;
			listIsert->size++;
			return;
		}
		//TODO
		//else if (n.data.id > N_list->data.id &&  N_list->next != NULL)
		else if (n_list->data.id > N_list->data.id )
		{
			n_list->next = N_list->next;
			N_list->next = n_list;
			listIsert->size++;
			return;

		}
		else
		{
			N_list = N_list->next; //����ѭ��
		}
	}
	
	//li->head->next = N_list;
}
void save_staff(LinkList list_file)
{
	int ch;
	//TODO�����ļ�
	FILE* fp = NULL;
	fp = fopen(filename, "w"); //�ļ���ֻ������ʽ
	if (fp == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	//��ͷ�ļ�����
	int length = list_file->size;
	NodeList staff = list_file->head;
	//д������
	for(int i=0;i<length;i++)
	{
		fprintf(fp, "%d %s %s %d %d %.2f %.2f\n",
			staff->data.id,staff->data.name,staff->data.department,staff->data.year,staff->data.month,staff->data.salary,staff->data.realsalary );
		staff = staff->next;
	}
	fclose(fp);
	fp = NULL;


}
void open_staff_file()
{
	int ch;  //��int���͵ı����洢EOF
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	while (!feof(fp))
	{
		struct Node  *staff = (Node*)malloc(sizeof(Node));;
		staff->data.id = NULL;
		staff->next = NULL;
		if (fscanf(fp, "%d %s %s %d %d %f %f\n",
			&staff->data.id, staff->data.name, staff->data.department,
			&staff->data.year, &staff->data.month, &staff->data.salary, &staff->data.realsalary) != 7)
		{
			break;
		}
		if (staff->data.id != NULL)
		{
			InsertList(staff);
		}
		

	}
	fclose(fp);
	fp = NULL;
}

void menu()
{
	//�������˵��û����룬������ϵͳ
	switch (main_menu())
	{
	case 1:
		system("cls"); //��cmdҳ����Ϣ�������
		//printf("������Ϣ¼��");
		information_menu();
		break;
	case 2:
		system("cls");
		//printf("����Ա����Ϣ��ѯ");
		staff_search_menu();

		break;
	case 3:
		system("cls");
		//printf("ɾ��Ա����Ϣ");
		delete_staff_menu();

		break;
	case 4:
		system("cls");
		//printf("���ʲ�ѯ");
		staff_salary_search();

		break;
	case 5:
		system("cls");
		//printf("����ͳ�ƹ���");
		staff_statistics();

		break;
	case 0:
		system("cls");
		printf("\t\t\t\t�����˳�Ա������ϵͳ.....");
		exit(0);
		break;
	default:
		system("cls");
		printf("\t\t\t\t���������룡");
		menu();
		break;
	}
}
void menu_frame()
{
	system("cls");
	printf("\n");
	printf("\t\t\t\t  ��ӭ����Ա�����ʹ���ϵͳ�������Խ������²�����\n");
	printf("\t\t\t\t********************************************\n");
	printf("\t\t\t\t               Ա�����ʹ���ϵͳ         \n");
	printf("\t\t\t\t********************************************\n");
	printf("\t\t\t\t\tNo.0����������[0]�� �� | ���� �� ϵ ͳ             \n");
}
void menu_bottom_frame()
{
	printf("\t\t\t\t\tNo.2*****[����]������һ��                \n");
	printf("\n\n");
	printf("\t\t\t\t====>���������Ӧ���ܵı��:");
}
int main_menu()
{
	int choose;
	menu_frame();
	printf("\t\t\t\t\tNo.1����������[1]��Ϣ¼��                \n");
	printf("\t\t\t\t\tNo.2����������[2]�鿴Ա����Ϣ            \n");
	printf("\t\t\t\t\tNo.3����������[3]ɾ��Ա����Ϣ            \n");
	printf("\t\t\t\t\tNo.4����������[4]���ʲ�ѯ                \n");
	printf("\t\t\t\t\tNo.5����������[5]ͳ�ƹ���                \n");
	menu_bottom_frame();
	scanf("%d", &choose);
	return choose;
}
//����Ա����Ϣ
void information_menu()
{
	//TODO
	//����Ա���ڵ�
	struct Node *staff =(Node*)malloc(sizeof(Node)); ;
	staff->next = NULL;
	menu_frame();
	printf("\t\t\t\t\tNo.0*****Ա����ϢĿ¼:                \n");
	printf("\n\n\t\t\t\t====>�������Ӧ���û���Ϣ(�ո�ָ�):\n");
	printf("\n\t\t\t\t\tNo.1*****[1]���:");
	scanf("%d",&staff->data.year);
	printf("\n\t\t\t\t\tNo.2*****[2]�·�:");
	scanf("%d", &staff->data.month);
	printf("\n\t\t\t\t\tNo.2*****[3]����(Ӫ����,������,���²�):");
	scanf("%s", &staff->data.department);
	printf("\n\t\t\t\t\tNo.3*****[3]����(8λ):");
	scanf("%d", &staff->data.id);
	printf("\n\t\t\t\t\tNo.2*****[2]����:");
	scanf("%s", &staff->data.name);
	printf("\n\t\t\t\t\tNo.2*****[2]Ӧ������:");
	scanf("%f", &staff->data.salary);

	staff->data.realsalary = staff->data.salary - tax(staff->data.salary);
	printf("\t\t\t\t\tNo.1*****����:%d\n \t\t\t\t\tNo.4*****������%s\n\t\t\t\t\tNo.4*****����: %s\n \t\t\t\t\tNo.4*****���:%d\n \t\t\t\t\tNo.4*****�·�:%d\n \t\t\t\t\tNo.4*****Ӧ������:%.2f\n \t\t\t\t\tNo.4*****ʵ������:%.2f\n",
		staff->data.id, staff->data.name, staff->data.department, staff->data.year, staff->data.month, staff->data.salary,staff->data.realsalary);
	int choose;
	printf("\n\n");
	printf("\t\t\t\t\tNo.1*****[1]������������Ϣ\n");
	printf("\t\t\t\t\tNo.2*****[2]ɾ�������棬���������Ϣ\n");
	printf("\t\t\t\t\tNo.3*****[3]�˳���������Ϣ\n");
	printf("\t\t\t\t\tNo.4*****[����]�˳�������Ϣ\n");
	printf("\n\n\t\t\t\t====>�������Ӧ���û���Ϣ(�ո�ָ�):");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		//�������뺯��������Node�ڵ�
		InsertList(staff);
		save_staff(list);
		//�����������
		information_menu();
		break;
	case 2:
		//����������������
		information_menu();
		break;
	case 3:
		//�������˻ص����˵�
		main_menu();
		break;
	default:
		//�������뺯��������Node�ڵ�
		InsertList( staff);
		save_staff(list);
		main_menu();
		break;
	}
	
}
void staff_search_menu()
{
	int choose;
	menu_frame();
	printf("\t\t\t\t\tNo.0*****��ѡ�������ʽ:                \n");
	printf("\t\t\t\t\tNo.1*****[1]�����·�����(ͬһ�¹�������)                \n");
	printf("\t\t\t\t\tNo.2*****[2]���ղ��Ž���(ʵ����������)                \n");
	menu_bottom_frame();
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		//TODO�����·�����(ͬһ�¹�������)
		sort_month(list);
		
		printf("\t\t\t\t\tNo.1*****[0]�˳�ϵͳ                \n");
		printf("\t\t\t\t\tNo.2*****[1]����Ա����Ϣ���                \n");
		printf("\t\t\t\t\tNo.2*****[3]�������˵�                \n");
		printf("\t\t\t\t====>���������Ӧ���ܵı��(:");
		int i;
		scanf("%d", &i);
		switch (i)
		{
		case 0:
			exit(0);
			break;
		case 1:
			staff_search_menu();
			break;
		default:
			main_menu();
		}
	case 2:
		//TODO���ղ��Ž���(ʵ����������) 
		//���ղ��Ž���(ʵ����������)
		sort_department(list);

		printf("\t\t\t\t\tNo.1*****[0]�˳�ϵͳ                \n");
		printf("\t\t\t\t\tNo.2*****[1]����Ա����Ϣ���                \n");
		printf("\t\t\t\t\tNo.2*****[3]�������˵�                \n");
		printf("\t\t\t\t====>���������Ӧ���ܵı��(:");
		int i;
		scanf("%d", &i);
		switch (i)
		{
		case 0:
			exit(0);
			break;
		case 1:
			staff_search_menu();
			break;
		default:
			main_menu();
		}

	default:
		//������һ��
		main_menu();
	}
}
void delete_staff_menu()
{
	int id; //Ա��if
	menu_frame();
	printf("\t\t\t\t\tNo.2*****[0]������һ��                \n");
	printf("\t\t\t\t\tNo.2*****[����]Ҫɾ����Ա������:       \n ");
	printf("\n\n");
	menu_bottom_frame();
	scanf("%d", &id);
	switch (id)
	{
	case 0:
		//�������˵�
		menu();
		break;
	default:
		//���ݹ���ɾ����Ӧ��Ա����Ϣ
		printf("ɾ��Ա����Ϣ");
		//TODO����ɾ��Ա������,�������id

		break;

	};


}
void staff_salary_search()
{
	int choose;
	menu_frame();
	printf("\t\t\t\t\tNo.0*****��ѡ�������ʽ:                \n");
	printf("\t\t\t\t\tNo.1*****[1]����������ѯ(ͬ��ȫ�����)                \n");
	printf("\t\t\t\t\tNo.2*****[2]���ݲ��ֲ�ѯ(ʵ�����ʽ���)                \n");
	printf("\t\t\t\t\tNo.2*****[3]�������²�ѯ(�·ݲ��Ž���)                \n");
	menu_bottom_frame();
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		//TODO����������ѯ(ͬ��ȫ�����) 
	
		break;

	case 2:
		//TODO���ݲ��ֲ�ѯ(ʵ�����ʽ���)  

		break;
	case 3:
		//TODO�������²�ѯ(�·ݲ��Ž���)   

		break;
	default:
		//�������˵�
		menu();

		break;

	};

}
void staff_statistics()
{
	int choose;
	menu_frame();
	printf("\t\t\t\t\tNo.0*****��ѡ�������ʽ:                \n");
	printf("\t\t\t\t\tNo.1*****[1]ÿ��Ա��ƽ������(����)                \n");
	printf("\t\t\t\t\tNo.2*****[2]��ݹ���ǰ�����ͺ�����                \n");
	printf("\t\t\t\t\tNo.2*****[3]ĳ����ÿ��������˰�ܶ�(������������ʾ)                \n");
	menu_bottom_frame();
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		//TODOÿ��Ա��ƽ������(����)


		break;
	case 2:
		//TODO��ݹ���ǰ�����ͺ�����

		break;
		
	case 3:
		//TODOĳ����ÿ��������˰�ܶ�(������������ʾ)
		
		break;
	default:
		//�������˵�
		menu(list);
		break;
	}
}
//���������
void printList(LinkList list)
{
	Node* p;
	p = list->head;
	while (p != NULL)
	{
		printf("\t\t\t\t\t%d %s %s %d %d %.2f %.2f\n", p->data.id, p->data.name, p->data.department, p->data.year, p->data.month, p->data.salary, p->data.realsalary);
		p = p->next;
	}
}
//��������·ݹ�������
void sort_month(LinkList list)
{
	//��list���ݴ���λ��ʼ����һ��������󣬸�����ݣ��·ݣ����ŵ�˳��������λС�����߽���˳���������Ƶ����ʵ������
	Node* p, * q, * temp; //p�ڵ㸴�Ʊ��������Ľ����q����һֱ���Ѱ��Сֵ�滻p��tempΪ�м�ֵ
	p = list->head;
	for(int i = list->size;i>0;i--)
	{
		q = p->next; //qָ����һ���ڵ�
		//q����һֱ���ѭ��Ѱ����Сֵ��q����λ���滻
		while (q != NULL)
		{
			//����������㣬���滻������
			//q�����С��p
			//����q p�����ȣ������·�qС��p
			//������ȵ���q��idС��p ����λ��
			if (q->data.year < p->data.year || (q->data.year == p->data.year && q->data.month < p->data.month) || (q->data.year == p->data.year && q->data.month == p->data.month && q->data.id < p->data.id))
			{

				//q p ͨ��temp����λ��
				//�ڵ㽻��
				temp = q;
				q = q->next;
				p->next = temp->next;
				temp->next = p;
				p = temp;
				//���Ĵ���
			}
			else
			{
				q = q->next;
				p = p->next;
			}

		}
		p = list->head;
		p = p->next; //�׽ڵ���С�������߼����ж�
	}
	printList(list);
}
//���ղ��ֽ���ͬ���Ź�����������
void sort_department(LinkList list)
{
	//˼·:�Ƚϲ����Լ�������
		//��list���ݴ���λ��ʼ����һ��������󣬸�����ݣ��·ݣ����ŵ�˳��������λС�����߽���˳���������Ƶ����ʵ������
	Node* p, * q, * temp; //p�ڵ㸴�Ʊ��������Ľ����q����һֱ���Ѱ��Сֵ�滻p��tempΪ�м�ֵ
	p = list->head;
	for (int i = list->size; i > 0; i--)
	{
		q = p->next; //qָ����һ���ڵ�
		//q����һֱ���ѭ��Ѱ����Сֵ��q����λ���滻
		while (q != NULL)
		{
			//����������㣬���滻������
			//q�����С��p
			//����q p�����ȣ������·�qС��p
			//������ȵ���q��idС��p ����λ��
			if (q->data.department > p->data.department ||(q->data.department == p->data.department && q->data.realsalary < p->data.realsalary))
			{

				//q p ͨ��temp����λ��
				//�ڵ㽻��
				temp = q;
				q = q->next;
				p->next = temp->next;
				temp->next = p;
				p = temp;
				//���Ĵ���
			}
			else
			{
				q = q->next;
				p = p->next;
			}

		}
		p = list->head;
		p = p->next; //�׽ڵ���С�������߼����ж�
	}
	printList(list);
}