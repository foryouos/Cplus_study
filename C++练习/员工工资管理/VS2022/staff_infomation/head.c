//Ա�����ʹ���ϵͳ�㷨ʵ�ֺ���
#include "head.h"

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
	//����ID�������򱣴�
	sort_id(list);

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
	printf("\t\t\t\t====>���������Ӧ����Ϣ:");
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
//Ա����Ϣ�����˵�
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
		system("cls");
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
		system("cls");
		sort_department(list);

		printf("\t\t\t\t\tNo.1*****[0]�˳�ϵͳ                \n");
		printf("\t\t\t\t\tNo.2*****[1]����Ա����Ϣ���                \n");
		printf("\t\t\t\t\tNo.2*****[3]�������˵�                \n");
		printf("\t\t\t\t====>���������Ӧ���ܵı��(:");
		int m;
		scanf("%d", &m);
		switch (m)
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
//ɾ��Ա����Ϣ�˵�
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
		//����ɾ��Ա������,�������id
		delete_id(list, id);
		break;

	};


}
//Ա�����ʲ�ѯ�˵�
void staff_salary_search()
{
	int choose;
	int m;
	menu_frame();
	printf("\t\t\t\t\tNo.0*****��ѡ�������ʽ:                \n");
	printf("\t\t\t\t\tNo.1*****[1]����������ѯ(ͬ��ȫ�����)                \n");
	printf("\t\t\t\t\tNo.2*****[2]���ݲ��Ų�ѯ(ʵ�����ʽ���)                \n");
	printf("\t\t\t\t\tNo.2*****[3]�������²�ѯ(�·ݲ��Ž���)                \n");
	menu_bottom_frame();
	char name[20];
	char department[20];
	int year;
	int month;
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		//����������ѯ(ͬ��ȫ�����) 
		printf("\n\n\t\t\t\t====>��������Ҫ��ѯ��Ա������:");
		scanf("%s", &name);
		search_name_salary(list,name);
		printf("\n\n\t\t\t\t\tNo.1*****[0]�˳�ϵͳ                \n");
		printf("\t\t\t\t\tNo.2*****[1]������һ��                \n");
		printf("\t\t\t\t\tNo.2*****[3]�������˵�                \n");
		printf("\t\t\t\t====>���������Ӧ���ܵı��(:");
		
		scanf("%d", &m);
		switch (m)
		{
		case 0:
			exit(0);
			break;
		case 1:
			staff_salary_search();
			break;
		default:
			main_menu();
		}
		break;

	case 2:
		//���ݲ��Ų�ѯ(ʵ�����ʽ���)  
		printf("\n\n\t\t\t\t====>��������Ҫ��ѯ�Ĳ���:");
		scanf("%s", &department);
		dept_staff(list, department);
		printf("\n\n\t\t\t\t\tNo.1*****[0]�˳�ϵͳ                \n");
		printf("\t\t\t\t\tNo.2*****[1]������һ��                \n");
		printf("\t\t\t\t\tNo.2*****[3]�������˵�                \n");
		printf("\t\t\t\t====>���������Ӧ���ܵı��(:");
	
		scanf("%d", &m);
		switch (m)
		{
		case 0:
			exit(0);
			break;
		case 1:
			staff_salary_search();
			break;
		default:
			main_menu();
		}
		break;
		break;
	case 3:
		//�������²�ѯ(�·ݲ��Ž���)
		
		printf("\n\n\t\t\t\t====>��������Ҫ��ѯ�����:");
		scanf("%s", &year);
		printf("\n\t\t\t\t====>��������Ҫ��ѯ���·�:");
		scanf("%s", &month);
		year_month_salary(list,year,month);
		printf("\n\n\t\t\t\t\tNo.1*****[0]�˳�ϵͳ                \n");
		printf("\t\t\t\t\tNo.2*****[1]������һ��                \n");
		printf("\t\t\t\t\tNo.2*****[3]�������˵�                \n");
		printf("\t\t\t\t====>���������Ӧ���ܵı��(:");
		scanf("%d", &m);
		switch (m)
		{
		case 0:
			exit(0);
			break;
		case 1:
			staff_salary_search();
			break;
		default:
			main_menu();
		}
		break;
		break;
	default:
		//�������˵�
		menu();

		break;

	};

}
//Ա������ͳ��
void staff_statistics()
{
	int choose;
	int year =0;
	int month =0;
	int m;
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
		//ÿ��Ա��ƽ������(����)
		//sort_id(list);
		every_staff_average_salary(list);
		printf("\n\n\t\t\t\t\tNo.1*****[0]�˳�ϵͳ                \n");
		printf("\t\t\t\t\tNo.2*****[1]������һ��                \n");
		printf("\t\t\t\t\tNo.2*****[3]�������˵�                \n");
		printf("\t\t\t\t====>���������Ӧ���ܵı��(:");

		scanf("%d", &m);
		switch (m)
		{
		case 0:
			exit(0);
			break;
		case 1:
			staff_statistics();
			break;
		default:
			main_menu();
		}
		break;
	case 2:
		//��ݹ���ǰ�����ͺ�����
		printf("\n\n\t\t\t\t====>��������Ҫ��ѯ�����:");
		scanf("%d",&year);
		dept_max_min(list,year);
		printf("\n\n\t\t\t\t\tNo.1*****[0]�˳�ϵͳ                \n");
		printf("\t\t\t\t\tNo.2*****[1]������һ��                \n");
		printf("\t\t\t\t\tNo.2*****[3]�������˵�                \n");
		printf("\t\t\t\t====>���������Ӧ���ܵı��(:");
		
		scanf("%d", &m);
		switch (m)
		{
		case 0:
			exit(0);
			break;
		case 1:
			staff_statistics();
			break;
		default:
			main_menu();
		}
		break;
		
	case 3:
		//TODOĳ����ÿ��������˰�ܶ�(������������ʾ)
		printf("\n\n\t\t\t\t====>��������Ҫ��ѯ�����:");
		scanf("%d", &year);
		printf("\n\t\t\t\t====>��������Ҫ��ѯ���·�:");
		scanf("%d", &month);
		year_month_tax_all(list,year, month);
		printf("\n\n\t\t\t\t\tNo.1*****[0]�˳�ϵͳ                \n");
		printf("\t\t\t\t\tNo.2*****[1]������һ��                \n");
		printf("\t\t\t\t\tNo.2*****[3]�������˵�                \n");
		printf("\t\t\t\t====>���������Ӧ���ܵı��(:");
		scanf("%d", &m);
		switch (m)
		{
		case 0:
			exit(0);
			break;
		case 1:
			staff_statistics();
			break;
		default:
			main_menu();
		}
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
	temp = (Node*)malloc(sizeof(Node));
	p = list->head; //p�ĵ�ַ��ʹ��list�ĵ�ַ
	for(int i = list->size;i>0;i--)
	//while(p !=NULL)
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
				//temp = q;
				//q = q->next;
				////p->next = temp->next;   //�мǣ��ñ���list���ļ�
				//p->next = q;
				//temp->next = p;
				//p = temp;
				temp->data = p->data;
				p->data = q->data;
				q->data = temp->data;
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
	Node* p, * q, * temp; //p�ڵ㸴�Ʊ��������Ľ����q����һֱ���Ѱ��Сֵ�滻p��tempΪ�м�ֵ
	p = list->head;
	temp = (Node*)malloc(sizeof(Node));
	for (int i = list->size; i > 0; i--)
	{
		q = p->next; //qָ����һ���ڵ�
		//q����һֱ���ѭ��Ѱ����Сֵ��q����λ���滻
		while (q != NULL)
		{
			if (wcscmp(p->data.department, q->data.department) < 0  
				|| (wcscmp(p->data.department, q->data.department) == 0 && q->data.realsalary < p->data.realsalary))
			{

				temp->data = p->data;
				p->data = q->data;
				q->data = temp->data;
	
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
//���ݹ���ɾ��Ա����������Ϣ
void delete_id(LinkList list,int id)
{
	//��ɾ��
	Node*d,*pre; //p�ڵ㸴�Ʊ��������Ľ����q����һֱ���Ѱ��Сֵ�滻p��tempΪ�м�ֵ
	//Employee *temp;
	//H = list->head;
	d = list->head;
	pre = list->head;
	int lenght = list->size;
	while(d!=NULL)
	{
		if (d->data.id == id)
		{
			pre->next = d->next;
			list->size--;
		}
		pre = d;
		d = d->next;
	}
	//���汾��
	save_staff(list);

}
//����Ա���������ѡ����Ա��������Ϣ
void search_name_salary(LinkList list, char name[20])
{
	
	Node* s;
	s = list->head;
	while (s!=NULL)
	{
		if (strcmp(s->data.name, name) == 0)
		{
			printf("\n\t\t\t\t====>  %s��%d��%d����%s��ʵ������Ϊ%.2f",s->data.name,s->data.year,s->data.month,s->data.department,s->data.realsalary);
		}
		s = s->next;
	}
}
//���Ҳ�������Ա����Ϣ����ʵ�����ʽ���
void dept_staff(LinkList list, char department[20])
{
	Node* d,*s;
	d = list->head;
	struct Node* emp = (Node*)malloc(sizeof(Node));
	int length = 0;
	emp->next = NULL;
	s = emp;
	while (d != NULL)
	{
		if (strcmp(d->data.department, department) == 0)
		{
			//����Ӧ�Ĳ��ż�������
			Node *temp = (Node*)malloc(sizeof(Node));
			temp->next = NULL;
			temp->data = d->data;
			s->next = temp;
			s = s->next;
			length++;
		}
		
		d = d->next;
	}
	//��emp����ʵ�ʹ��ʽ���
	Node* p, * q, * temp; //p�ڵ㸴�Ʊ��������Ľ����q����һֱ���Ѱ��Сֵ�滻p��tempΪ�м�ֵ
	temp = (Node*)malloc(sizeof(Node));
	p = emp->next;
	printf("%d\n", length);
	for(int i=length;i>=0;i--)
	{
		q = p->next; //qָ����һ���ڵ�
		//q����һֱ���ѭ��Ѱ����Сֵ��q����λ���滻
		while (q != NULL)
		{
			if (p->data.realsalary < q->data.realsalary)
			{
				temp->data = p->data;
				p->data = q->data;
				q->data = temp->data;
				//���Ĵ���
			}
			else
			{
				q = q->next;
				p = p->next;
			}

		}
		p = emp;
		p = p->next; //�׽ڵ���С�������߼����ж�
	}
	//���emp
	emp = emp->next;
	while (emp != NULL)
	{
		printf("\n\t\t\t\t====>  %s��%d��%d����%s��ʵ������Ϊ%.2f", emp->data.name, emp->data.year, emp->data.month, emp->data.department, emp->data.realsalary);
		emp = emp->next;
	}
	
}

void year_month_salary(LinkList list, int year, int month)
{
	Node* d, * s;
	d = list->head;
	struct Node* emp = (Node*)malloc(sizeof(Node));
	int length = 0;
	emp->next = NULL;
	s = emp;
	while (d != NULL)
	{
		if (d->data.year==year && d->data.month == month)
		{
			//����Ӧ�Ĳ��ż�������
			Node* temp = (Node*)malloc(sizeof(Node));
			temp->next = NULL;
			temp->data = d->data;
			s->next = temp;
			s = s->next;
			length++;
		}

		d = d->next;
	}
	//��emp����ʵ�ʹ��ʽ���
	Node* p, * q, * temp; //p�ڵ㸴�Ʊ��������Ľ����q����һֱ���Ѱ��Сֵ�滻p��tempΪ�м�ֵ
	temp = (Node*)malloc(sizeof(Node));
	p = emp->next;
	printf("%d\n", length);
	for (int i = length; i >= 0; i--)
	{
		q = p->next; //qָ����һ���ڵ�
		//q����һֱ���ѭ��Ѱ����Сֵ��q����λ���滻
		while (q != NULL)
		{
			if (strcmp(p->data.department, q->data.department) < 0)
			{
				temp->data = p->data;
				p->data = q->data;
				q->data = temp->data;
				//���Ĵ���
			}
			else
			{
				q = q->next;
				p = p->next;
			}

		}
		p = emp;
		p = p->next; //�׽ڵ���С�������߼����ж�
	}
	//���emp
	emp = emp->next;
	while (emp != NULL)
	{
		printf("\n\t\t\t\t====>  %s��%d��%d����%s��ʵ������Ϊ%.2f", emp->data.name, emp->data.year, emp->data.month, emp->data.department, emp->data.realsalary);
		emp = emp->next;
	}

}
//����id��������
void sort_id(LinkList list)
{
	Node* p, * q, * temp; //p�ڵ㸴�Ʊ��������Ľ����q����һֱ���Ѱ��Сֵ�滻p��tempΪ�м�ֵ
	p = list->head;
	temp = (Node*)malloc(sizeof(Node));
	for (int i = list->size; i >= 0; i--)
	{
		q = p->next; //qָ����һ���ڵ�
		//q����һֱ���ѭ��Ѱ����Сֵ��q����λ���滻
		while (q != NULL)
		{
			if (p->data.id > q->data.id)
			{

				temp->data = p->data;
				p->data = q->data;
				q->data = temp->data;

			}
			else
			{
				q = q->next;
				p = p->next;
			}


		}
		p = list->head;
		//p = p->next; //�׽ڵ���С�������߼����ж�
	}
	//printList(list);
}
//ÿ��Ա����ƽ������
void every_staff_average_salary(LinkList list)
{
	struct average* s = (average*)malloc(sizeof(average));
	s->next = NULL;
	Node* d;
	average* a = (average*)malloc(sizeof(average));
	a->next = NULL;
	d = list->head;
	a = s;
	//����id��������
	// 
	sort_id(list);
	float total_salary ;
	int total_month;
	float average_salary;
	int p_id;
	char *name;
	int id_count;
	id_count = 0;
	//����˳��͹�����������Id��ְ������������/����
	while ( d != NULL)
	//for(int i=0;i<list->size;i++)
	{
		total_salary = 0;
		total_month = 0;
		p_id = d->data.id;
		name = d->data.name;
		while (d->data.id == p_id)
		{
			total_month++; //�����·�
			total_salary = total_salary + d->data.salary; //�����ܹ���
			d = d->next;
	
			if (d == NULL)
				break;
		}
		
		//�����ƽ������
		average_salary = total_salary / total_month;
		struct average* lin_a = (average*)malloc(sizeof(average));
		lin_a->next = NULL;
		lin_a->id = p_id;
		lin_a->name = name;
		lin_a->a_salary = average_salary;
		a->next = lin_a;
		a = a->next;
		id_count++;
	}
	free(a);
	//�����ɵ�ƽ�����ʽṹ����������ɱ�
	average* p, * q, * temp; //p�ڵ㸴�Ʊ��������Ľ����q����һֱ���Ѱ��Сֵ�滻p��tempΪ�м�ֵ
	p = s->next;
	temp = (average*)malloc(sizeof(average));
	//while (p != NULL)
	for(int i=0;i<id_count;i++)
	{
		q = p->next;
		for (int j = id_count -i; j >0; j--)
		{

			if (p->a_salary > q->a_salary)
			{

				temp->id = p->id;
				temp->name = p->name;
				temp->a_salary = p->a_salary;
				p->id = q->id;
				p->name = q->name;
				p->a_salary = q->a_salary;
				q->id = temp->id;
				q->name = temp->name;
				q->a_salary = temp->a_salary;
				q = q->next;
				if (q->id < 0 || q->a_salary < 0)
					break;
				p = p->next;
			}
			else
			{
				
				q = q->next;
				if ( q==NULL || q->id < 0 || q->a_salary < 0)
					break;
				p = p->next;
				
			}
		}
		p = s->next;

	}
	//������ŵ�����������
	for (int i = 0; i < id_count; i++)
	{
		s = s->next;
		if (s->id < 0 || s->a_salary < 0)
			break;
		printf("\t\t\t\t ID: %d,Name: %s,ƽ������: %.2f\n", s->id, s->name, s->a_salary);
	}
}
void dept_max_min(LinkList list,int year)
{
	struct salary* s = (salary*)malloc(sizeof(salary));
	s->next = NULL;
	Node* d;
	salary* a = (salary*)malloc(sizeof(salary));
	a->next = NULL;
	d = list->head;
	a = s;
	//����id��������
	sort_id(list);
	float total_salary;
	int total_month;
	char *department;//����
	int p_id;
	char *name;
	int id_count;
	id_count = 0;
	//���㲿�ţ�ÿ���˵��ܹ��ʣ������µ�����
	//����˳��͹�����������Id��ְ������������/����

		//for(int i=0;i<list->size;i++)
	while (d != NULL)
	{
		
		total_salary = 0;
		total_month = 0;
		p_id = d->data.id;
		name = d->data.name;
		department = d->data.department;
		while (d->data.id == p_id && d->data.year == year) //������ݣ��������ÿ���˵��ܹ���
		{
			total_month++; //�����·�
			total_salary = total_salary + d->data.salary; //�����ܹ���
			d = d->next;

			if (d == NULL)
				break;
		}
		if (total_month != 0)
		{
			//�����ƽ������
			struct salary* lin_a = (salary*)malloc(sizeof(salary));
			lin_a->next = NULL;
			lin_a->id = p_id;
			lin_a->name = name;
			lin_a->department = department;
			lin_a->all_salary = total_salary;
			a->next = lin_a;
			a = a->next;
			id_count++;
		}
		else
		{
			d = d->next;

			if (d == NULL)
				break;
		}
	}
	salary* p, * q, * temp; //p�ڵ㸴�Ʊ��������Ľ����q����һֱ���Ѱ��Сֵ�滻p��tempΪ�м�ֵ
	p = s->next;
	temp = (salary*)malloc(sizeof(salary));
	for (int i = list->size; i > 0 && p!=NULL; i--)
	{
		q = p->next; //qָ����һ���ڵ�
		//q����һֱ���ѭ��Ѱ����Сֵ��q����λ���滻
		while (q != NULL)
		{
			if (wcscmp(p->department, q->department) < 0
				|| (wcscmp(p->department, q->department) == 0 && q->all_salary > p->all_salary))
			{
				temp->id = p->id;
				temp->name = p->name;
				temp->department = p->department;
				temp->all_salary = p->all_salary;
				
				p->id = q->id;
				p->name = q->name;
				p->department = q->department;
				p->all_salary = q->all_salary;

			
				q->id = temp->id;
				q->name = temp->name;
				q->department = temp->department;
				q->all_salary = temp->all_salary;

			}
			else
			{
				q = q->next;
				p = p->next;
			}


		}
		p = s->next;
	}

	//�ó������£�����Ա���ܹ��ʵõ�������
	for (int i = 0; i < id_count; i++)
	{
		s = s->next;
		if (s == NULL || s->id < 0 || s->all_salary < 0)
			break;
		printf("\n\t\t\tID: %d,Name: %s,����: %s , ��%d�����ܹ��ʹ���: %.2f\n", s->id, s->name, s->department, year, s->all_salary);
	}

}
void year_month_tax_all(LinkList list, int year, int month)
{
	//�ҵ������ݽ����µ����������˰�ܶ� �����㼴�ɣ�
	char dept[3][20] = { "���²�","Ӫ����","������" };
	int Tax[3] = { 0,0,0 };
	int Person_tax = 0;//���²�
	int Sales_tax = 0;//���۲�
	int Develop_tax = 0;//������
	//�����ÿ�����ŵ���˰�ܶ��������ֱ�Ӹ��ݲ����������
	for (int j = 0; j < 3; j++)
	{
		
		//����List�����Ӧ���ŵ�����˰��
		Node* p; //p�ڵ㸴�Ʊ��������Ľ����q����һֱ���Ѱ��Сֵ�滻p��tempΪ�м�ֵ
		p = list->head;
		for (int i = list->size; i >= 0; i--)
		{
			if (strcmp(p->data.department, dept[j]) == 0)
			{
				Tax[j] = Tax[j] + (p->data.salary - p->data.realsalary);
			}
			p = p->next;
			if (p == NULL)
			{
				break;
			}
		}
	}
	for (int n = 0; n < 3; n++)
	{
		printf("\t\t\t\t %s ���ŵ�����˰��Ϊ�� %d\n", dept[n],Tax[n]);
	}
	

}