#include "student.h"
bool login()
{
	//��½
	/*�ӱ����ļ��л�ȡ�ļ������ƺ������� */
	int x = 0;
	char c='0';
	char user[20];
	char password[16];
	printf("\n\n\t\t\t�������û���:");
	scanf("%s", user);
	printf("\n\n\t\t\tpassword:");
	//13�ǻس�����ASCII��
	//do
	//{
	//	c = getchar();
	//	password[x++] = c;
	//	if (c != 13)
	//	{
	//		putchar('*');
	//	}
	//} while (x < 15 && c != 13);

	//����û�������Ȩ�û��У���������ȷ��������������


	printf("\n\n\n\t\t\t*****���ڽ������˵�*******");
	system("cls");
	return true;
	
}
int main(void)
{
	//��½
	int m = 1;
	if (login()&&1==m)
	{
		//�������˵�
		menus();
		//system("sleep 3");
		system("cls");
		m++;
	}
	else
	{
		printf("��½ʧ��!");
	}
	
	return 0;
	
}