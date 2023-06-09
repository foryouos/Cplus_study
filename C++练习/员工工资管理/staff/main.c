//员工工作管理系统 主文件 调用
#include "head.h"
//单链表初始化

int main()
{
	list = (LinkList)malloc(sizeof(LinkList));
	list->head = NULL;
	list->size = 0;
	//TODO启动时将文件中所有用户信息初始化到链表
	if (_access(filename, 00)==0) //如果此文件存咋
	{
		open_staff_file(list);
	}
	//printList(list);

#if 1
	//进入员工工作管理系统菜单
	menu();
#elif 0
	//测试代码
	//printf("部门排序");
	//sort_month(list);
	//sort_department(list);
	/*printList(list);
	delete_id(list,10);
	printList(list);*/
	//search_name_salary(list, "刘德华");
	//dept_staff(list, "营销部");
	//year_month_salary(list, 2023, 3);
	//统计部分
	//sort_id(list);
	//every_staff_average_salary(list);
	//dept_max_min(list,2023);
	//year_month_tax_all(list, 2023, 5);
#endif
	return 0;
}