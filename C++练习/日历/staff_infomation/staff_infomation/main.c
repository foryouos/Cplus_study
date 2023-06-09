//员工工作管理系统 主文件 调用
#include "head.h"
//单链表初始化

int main()
{
	list = (LinkList)malloc(sizeof(LinkList)+sizeof(Employee)+sizeof(Node));
	list->head = NULL;
	list->size = 0;
	//TODO启动时将文件中所有用户信息初始化到链表
	if (_access(filename, 00)==0) //如果此文件存咋
	{
		open_staff_file(list);
	}
	//open_staff_file(list);
	//进入员工工作管理系统菜单
	menu();
	//printf("%.2f\n", tax(9500));

	
}