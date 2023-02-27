#include "student.h"
bool login()
{
	//登陆
	/*从本地文件中获取文件，类似函数调用 */
	int x = 0;
	char c='0';
	char user[20];
	char password[16];
	printf("\n\n\t\t\t请输入用户名:");
	scanf("%s", user);
	printf("\n\n\t\t\tpassword:");
	//13是回车符的ASCII码
	//do
	//{
	//	c = getchar();
	//	password[x++] = c;
	//	if (c != 13)
	//	{
	//		putchar('*');
	//	}
	//} while (x < 15 && c != 13);

	//如果用户名在特权用户中，且密码正确，否则重新输入


	printf("\n\n\n\t\t\t*****正在进入主菜单*******");
	system("cls");
	return true;
	
}
int main(void)
{
	//登陆
	int m = 1;
	if (login()&&1==m)
	{
		//进入主菜单
		menus();
		//system("sleep 3");
		system("cls");
		m++;
	}
	else
	{
		printf("登陆失败!");
	}
	
	return 0;
	
}