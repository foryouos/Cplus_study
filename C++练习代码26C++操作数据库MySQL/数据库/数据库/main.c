#include <stdio.h>
#include <mysql.h>

int main(void)
{
	printf("MySQL Environment Successful\n");

	//��ʼ�����л���
	//�ú����������ʼ�����������¶��󣬲�ͨ�������������ȥ����MySQL������
	MYSQL* mysql = mysql_init(NULL);

	//�ж��Ƿ��ʼ���ɹ�
	if (mysql == NULL)
	{
		printf("mysql_init() error");
		return -1;
	}
	printf("���ݿ��ʼ���ɹ�\n");
	//����MySQL������
	mysql = mysql_real_connect
	(
		mysql, //mysql_init()��������ֵ
		"localhost", //mysql��IP��ַ
		"root", //myslq���û���
		"5211314", //mysql������
		"cpp",   //ʹ�õ����ݿ�����
		3306,     //�����˿ڣ�0ΪĬ��3306�˿�
		NULL,   //�����׽��֣���ָ��ΪNULL
		0       //Ĭ��0
	);
	//������ݿ��������
	if (mysql == NULL)
	{
		printf("mysql_real_connect() error\n");
		return -1;
	}
	printf("���ݿ����ӳɹ�\n");


	//���MySQL APIʹ�õı���,����Ϊ���ݿ����
	printf("mysql apiʹ�õ�Ĭ�ϱ���:%s\n", mysql_character_set_name(mysql));

	//�������ݿ����Ϊutf8,
	//���������ݿ���󣬱���
	mysql_set_character_set(mysql, "gbk"); //�������Ϊgbk�ſ��Խ������ݲ��룬��������
	printf("mysql api�޸ĺ�ı���Ϊ:%s\n", mysql_character_set_name(mysql));

	//ִ��sql���
	// ��ѯcpp���ݿ��µ�dept���ű�
	const char* sql = "select * from dept";
	//ִ��sql���
	//���������ݿ����const char*�����ݿ�ִ�����
	//ִ�гɹ�����0
	int ret = mysql_query(mysql, sql);
	if (ret != 0)
	{
		//mysql_error����mysql���ݿ�����������
		printf("mysql_query()ʧ���ˣ�ԭ��%s\n", mysql_error(mysql));
		return -1;
	}

	//ȡ�����,����mysql���ݶ���
	//MYSQL_RES��Ӧһ���ڴ�˴�ִ��֮��Ľ����
	//�����󣬷���NULL
	MYSQL_RES* res = mysql_store_result(mysql);
	if (res == NULL)
	{
		printf("mysql_store_result()ʧ���ˣ�ԭ����:%s\n", mysql_error(mysql));
		return -1;
	}

	//�õ�������е�����
	//����������mysql_store_result()�õ��ķ���ֵ
	int num = mysql_num_fields(res);

	//�õ������е����֣��������
	//��������mysql_store_result()�õ��ķ���ֵ
	//MYSQL_FIELD��Ӧ����һ���ṹ��
	MYSQL_FIELD* fields = mysql_fetch_fields(res);
	//�������mysql��name
	for (int i = 0; i < num; i++)
	{

		printf("%s\t\t", fields[i].name);
	}
	printf("\n");
	
	//����������е�������
	//������mysql_store_result()�õ��ķ���ֵ
	// �ɹ��õ���ǰ��¼��ÿһ���ֶε�ֵ
	// ʧ��/���ݶ��� ����NULL
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		// ����ǰ���е�ÿһ����Ϣ����
		for (int i = 0; i < num; ++i)
		{
			printf("%s\t\t", row[i]);
		}
		printf("\n");
	}

	//�ͷ���Դ -�����
	mysql_free_result(res);

	//д������
	//MySQLĬ���Զ��ύ���ݿ�
	//��������Ϊ�ֶ��ύ
	mysql_autocommit(mysql, 0);
	//ִ�гɹ�����0
	int ret1 = mysql_query(mysql, "insert into dept values(10,'��һ����','����')");
	int ret2 = mysql_query(mysql, "insert into dept values(11,'�ڶ�����','����')");
	int ret3 = mysql_query(mysql, "insert into dept values(12,'��������','����')");

	printf("ret1=%d  ret2 = %d  ret3 = %d\n", ret1, ret2, ret3);

	if (ret1 == 0 && ret2 == 0 && ret3 == 0)
	{
		printf("ִ�гɹ��������ύ����\n");
		//�ύ����
		mysql_commit(mysql);
	}
	else
	{
		printf("ִ��ʧ�ܣ����ڻع�....\n");
		printf("ִ��ʧ��ԭ��: %s\n", mysql_error(mysql));
		mysql_rollback(mysql);
	}
	//�ͷ����ݿ���Դ
	mysql_close(mysql);

	return 0;
}