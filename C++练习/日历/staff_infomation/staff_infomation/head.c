//员工工资管理系统算法实现函数
#include "head.h"
float tax(float salary)
{
	//强制取整数
	//int t_salary = (int)salary;
	float tax_need; //需要交的税额
	//使用switch根据不同工资计算出其所需要的交的money
	 //参数必须为整形
	//除以5000根据其得出的结果，判断其税率区间
	//税率计算使用超额累进税率
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
		//工资大于8000小于17000
		//5000~8000按照3%税率，超过8000的部分按照10%
		tax_need = (8000 - 5000) * 0.03 + (salary - 8000) * 0.1;

	}
	else if (salary > 17000 && salary <= 30000)
	{
		//工资在17000到30000之间
		tax_need = (8000-5000) * 0.03 + (17000 - 8000) * 0.1 + (salary - 17000)*0.2;
	}
	else if (salary > 30000 && salary <= 40000)
	{
		//工资在30000到40000之间
		tax_need = (8000 - 5000) * 0.03 + (17000 - 8000) * 0.1 + (30000 - 17000) * 0.2 
			+ (salary - 30000) * 0.25;
	}
	else if (salary > 40000 && salary <= 60000)
	{
		//工资在4万 到6万之间
		tax_need = (8000 - 5000) * 0.03 + (17000 - 8000) * 0.1 + (30000 - 17000) * 0.24 
			+ (40000 - 30000) * 0.25 + (salary - 40000) * 0.3;
	}
	else if (salary > 60000 && salary <= 85000)
	{
		//工资在6万 到8.5万之间
		tax_need = (8000 - 5000) * 0.03 + (17000 - 8000) * 0.1 + (30000 - 17000) * 0.2 
			+ (40000 - 30000) * 0.25 + (60000 - 40000) * 0.3 + (salary - 60000) * 0.35;
	}
	else if (salary > 85000)
	{
		//工资大于8.5万的部分45%
		tax_need = (8000 - 5000) * 0.03 + (17000 - 8000) * 0.1 + (30000 - 17000) * 0.2 
			+ (40000 - 30000) * 0.25 + (60000 - 40000) * 0.3 + (85000 - 60000) * 0.35 
			+ (salary - 85000) * 0.45;
	}
	return tax_need;
}
//将节点数据插入到list表中
void InsertList(Node* n)
{
	Node *n_list = (Node*)malloc(sizeof(Node));
	n_list = n;
	n_list->next = NULL;
	LinkList listIsert = list;
	//list中的总长度+1
	if (listIsert->head == NULL)
	{
		listIsert->size++;
		listIsert->head = n_list;
		return;
	}
	Node* N_list = (NodeList)malloc(sizeof(NodeList));;
	N_list = NULL;
	N_list = listIsert->head;
	//根据n的信息判断插入位置
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
			N_list = N_list->next; //往后循环
		}
	}
	
	//li->head->next = N_list;
}
void save_staff(LinkList list_file)
{
	int ch;
	//TODO保存文件
	FILE* fp = NULL;
	fp = fopen(filename, "w"); //文件以只读的形式
	if (fp == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	//将头文件存入
	int length = list_file->size;
	NodeList staff = list_file->head;
	//写入数据
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
	int ch;  //用int类型的变量存储EOF
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
	//根据主菜单用户输入，分配子系统
	switch (main_menu())
	{
	case 1:
		system("cls"); //对cmd页面信息进行清空
		//printf("进入信息录入");
		information_menu();
		break;
	case 2:
		system("cls");
		//printf("进入员工信息查询");
		staff_search_menu();

		break;
	case 3:
		system("cls");
		//printf("删除员工信息");
		delete_staff_menu();

		break;
	case 4:
		system("cls");
		//printf("工资查询");
		staff_salary_search();

		break;
	case 5:
		system("cls");
		//printf("进入统计功能");
		staff_statistics();

		break;
	case 0:
		system("cls");
		printf("\t\t\t\t正在退出员工工资系统.....");
		exit(0);
		break;
	default:
		system("cls");
		printf("\t\t\t\t请重新输入！");
		menu();
		break;
	}
}
void menu_frame()
{
	system("cls");
	printf("\n");
	printf("\t\t\t\t  欢迎进入员工工资管理系统！您可以进行以下操作！\n");
	printf("\t\t\t\t********************************************\n");
	printf("\t\t\t\t               员工工资管理系统         \n");
	printf("\t\t\t\t********************************************\n");
	printf("\t\t\t\t\tNo.0—————[0]退 出 | 返回 主 系 统             \n");
}
void menu_bottom_frame()
{
	printf("\t\t\t\t\tNo.2*****[其它]返回上一层                \n");
	printf("\n\n");
	printf("\t\t\t\t====>请输入相对应功能的编号:");
}
int main_menu()
{
	int choose;
	menu_frame();
	printf("\t\t\t\t\tNo.1—————[1]信息录入                \n");
	printf("\t\t\t\t\tNo.2—————[2]查看员工信息            \n");
	printf("\t\t\t\t\tNo.3—————[3]删除员工信息            \n");
	printf("\t\t\t\t\tNo.4—————[4]工资查询                \n");
	printf("\t\t\t\t\tNo.5—————[5]统计功能                \n");
	menu_bottom_frame();
	scanf("%d", &choose);
	return choose;
}
//插入员工信息
void information_menu()
{
	//TODO
	//定义员工节点
	struct Node *staff =(Node*)malloc(sizeof(Node)); ;
	staff->next = NULL;
	menu_frame();
	printf("\t\t\t\t\tNo.0*****员工信息目录:                \n");
	printf("\n\n\t\t\t\t====>请输入对应的用户信息(空格分割):\n");
	printf("\n\t\t\t\t\tNo.1*****[1]年份:");
	scanf("%d",&staff->data.year);
	printf("\n\t\t\t\t\tNo.2*****[2]月份:");
	scanf("%d", &staff->data.month);
	printf("\n\t\t\t\t\tNo.2*****[3]部门(营销部,开发部,人事部):");
	scanf("%s", &staff->data.department);
	printf("\n\t\t\t\t\tNo.3*****[3]工号(8位):");
	scanf("%d", &staff->data.id);
	printf("\n\t\t\t\t\tNo.2*****[2]姓名:");
	scanf("%s", &staff->data.name);
	printf("\n\t\t\t\t\tNo.2*****[2]应发工资:");
	scanf("%f", &staff->data.salary);

	staff->data.realsalary = staff->data.salary - tax(staff->data.salary);
	printf("\t\t\t\t\tNo.1*****工号:%d\n \t\t\t\t\tNo.4*****姓名：%s\n\t\t\t\t\tNo.4*****部门: %s\n \t\t\t\t\tNo.4*****年份:%d\n \t\t\t\t\tNo.4*****月份:%d\n \t\t\t\t\tNo.4*****应发工资:%.2f\n \t\t\t\t\tNo.4*****实发工资:%.2f\n",
		staff->data.id, staff->data.name, staff->data.department, staff->data.year, staff->data.month, staff->data.salary,staff->data.realsalary);
	int choose;
	printf("\n\n");
	printf("\t\t\t\t\tNo.1*****[1]保存继续添加信息\n");
	printf("\t\t\t\t\tNo.2*****[2]删除不保存，重新添加信息\n");
	printf("\t\t\t\t\tNo.3*****[3]退出不保存信息\n");
	printf("\t\t\t\t\tNo.4*****[其它]退出保存信息\n");
	printf("\n\n\t\t\t\t====>请输入对应的用户信息(空格分割):");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		//插入输入函数，传入Node节点
		InsertList(staff);
		save_staff(list);
		//继续添加数据
		information_menu();
		break;
	case 2:
		//不保存继续添加数据
		information_menu();
		break;
	case 3:
		//不保存退回到主菜单
		main_menu();
		break;
	default:
		//插入输入函数，传入Node节点
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
	printf("\t\t\t\t\tNo.0*****请选择输出方式:                \n");
	printf("\t\t\t\t\tNo.1*****[1]按年月份升序(同一月工号升序)                \n");
	printf("\t\t\t\t\tNo.2*****[2]按照部门降序(实发工资升序)                \n");
	menu_bottom_frame();
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		//TODO按年月份升序(同一月工号升序)
		sort_month(list);
		
		printf("\t\t\t\t\tNo.1*****[0]退出系统                \n");
		printf("\t\t\t\t\tNo.2*****[1]返回员工信息输出                \n");
		printf("\t\t\t\t\tNo.2*****[3]返回主菜单                \n");
		printf("\t\t\t\t====>请输入相对应功能的编号(:");
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
		//TODO按照部门降序(实发工资升序) 
		//按照部门降序(实发工资升序)
		sort_department(list);

		printf("\t\t\t\t\tNo.1*****[0]退出系统                \n");
		printf("\t\t\t\t\tNo.2*****[1]返回员工信息输出                \n");
		printf("\t\t\t\t\tNo.2*****[3]返回主菜单                \n");
		printf("\t\t\t\t====>请输入相对应功能的编号(:");
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
		//返回上一层
		main_menu();
	}
}
void delete_staff_menu()
{
	int id; //员工if
	menu_frame();
	printf("\t\t\t\t\tNo.2*****[0]返回上一层                \n");
	printf("\t\t\t\t\tNo.2*****[工号]要删除的员工工号:       \n ");
	printf("\n\n");
	menu_bottom_frame();
	scanf("%d", &id);
	switch (id)
	{
	case 0:
		//返回主菜单
		menu();
		break;
	default:
		//根据工号删除相应的员工信息
		printf("删除员工信息");
		//TODO进入删除员工处理,传入参数id

		break;

	};


}
void staff_salary_search()
{
	int choose;
	menu_frame();
	printf("\t\t\t\t\tNo.0*****请选择输出方式:                \n");
	printf("\t\t\t\t\tNo.1*****[1]根据姓名查询(同名全部输出)                \n");
	printf("\t\t\t\t\tNo.2*****[2]根据部分查询(实发工资降序)                \n");
	printf("\t\t\t\t\tNo.2*****[3]根据年月查询(月份部门降序)                \n");
	menu_bottom_frame();
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		//TODO根据姓名查询(同名全部输出) 
	
		break;

	case 2:
		//TODO根据部分查询(实发工资降序)  

		break;
	case 3:
		//TODO根据年月查询(月份部门降序)   

		break;
	default:
		//返回主菜单
		menu();

		break;

	};

}
void staff_statistics()
{
	int choose;
	menu_frame();
	printf("\t\t\t\t\tNo.0*****请选择输出方式:                \n");
	printf("\t\t\t\t\tNo.1*****[1]每个员工平均工资(升序)                \n");
	printf("\t\t\t\t\tNo.2*****[2]年份工资前三名和后三名                \n");
	printf("\t\t\t\t\tNo.2*****[3]某年月每个部门纳税总额(按部门升序显示)                \n");
	menu_bottom_frame();
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		//TODO每个员工平均工资(升序)


		break;
	case 2:
		//TODO年份工资前三名和后三名

		break;
		
	case 3:
		//TODO某年月每个部门纳税总额(按部门升序显示)
		
		break;
	default:
		//返回主菜单
		menu(list);
		break;
	}
}
//对链表输出
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
//根据年份月份工号排序
void sort_month(LinkList list)
{
	//对list数据从首位开始，另一个依次向后，根据年份，月份，工号的顺序，若比首位小，两者交换顺序，依次类推到最后实现排序
	Node* p, * q, * temp; //p节点复制保存排序后的结果，q负责一直向后寻找小值替换p，temp为中间值
	p = list->head;
	for(int i = list->size;i>0;i--)
	{
		q = p->next; //q指向下一个节点
		//q负责一直向后循环寻找最小值与q所在位置替换
		while (q != NULL)
		{
			//如果条件满足，则替换，否则
			//q的年份小于p
			//或者q p年份相等，但是月份q小月p
			//年月相等但是q的id小于p 调换位置
			if (q->data.year < p->data.year || (q->data.year == p->data.year && q->data.month < p->data.month) || (q->data.year == p->data.year && q->data.month == p->data.month && q->data.id < p->data.id))
			{

				//q p 通过temp调换位置
				//节点交换
				temp = q;
				q = q->next;
				p->next = temp->next;
				temp->next = p;
				p = temp;
				//核心代码
			}
			else
			{
				q = q->next;
				p = p->next;
			}

		}
		p = list->head;
		p = p->next; //首节点最小，往后走继续判断
	}
	printList(list);
}
//按照部分降序，同部门工资升序排序
void sort_department(LinkList list)
{
	//思路:比较部门以及工资数
		//对list数据从首位开始，另一个依次向后，根据年份，月份，工号的顺序，若比首位小，两者交换顺序，依次类推到最后实现排序
	Node* p, * q, * temp; //p节点复制保存排序后的结果，q负责一直向后寻找小值替换p，temp为中间值
	p = list->head;
	for (int i = list->size; i > 0; i--)
	{
		q = p->next; //q指向下一个节点
		//q负责一直向后循环寻找最小值与q所在位置替换
		while (q != NULL)
		{
			//如果条件满足，则替换，否则
			//q的年份小于p
			//或者q p年份相等，但是月份q小月p
			//年月相等但是q的id小于p 调换位置
			if (q->data.department > p->data.department ||(q->data.department == p->data.department && q->data.realsalary < p->data.realsalary))
			{

				//q p 通过temp调换位置
				//节点交换
				temp = q;
				q = q->next;
				p->next = temp->next;
				temp->next = p;
				p = temp;
				//核心代码
			}
			else
			{
				q = q->next;
				p = p->next;
			}

		}
		p = list->head;
		p = p->next; //首节点最小，往后走继续判断
	}
	printList(list);
}