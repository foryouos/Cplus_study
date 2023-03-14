#include <stdio.h>
#include <mysql.h>

int main(void)
{
	printf("MySQL Environment Successful\n");

	//初始化运行环境
	//该函数将分配初始化，并返回新对象，并通过返回这个对象去连接MySQL服务器
	MYSQL* mysql = mysql_init(NULL);

	//判断是否初始化成功
	if (mysql == NULL)
	{
		printf("mysql_init() error");
		return -1;
	}
	printf("数据库初始化成功\n");
	//连接MySQL服务器
	mysql = mysql_real_connect
	(
		mysql, //mysql_init()函数返回值
		"localhost", //mysql的IP地址
		"root", //myslq的用户名
		"5211314", //mysql的密码
		"cpp",   //使用的数据库名称
		3306,     //监听端口，0为默认3306端口
		NULL,   //本地套接字，不指定为NULL
		0       //默认0
	);
	//检查数据库连接情况
	if (mysql == NULL)
	{
		printf("mysql_real_connect() error\n");
		return -1;
	}
	printf("数据库连接成功\n");


	//输出MySQL API使用的编码,参数为数据库对象
	printf("mysql api使用的默认编码:%s\n", mysql_character_set_name(mysql));

	//设置数据库编码为utf8,
	//参数：数据库对象，编码
	mysql_set_character_set(mysql, "gbk"); //将编码改为gbk才可以进行数据插入，报错，乱码
	printf("mysql api修改后的编码为:%s\n", mysql_character_set_name(mysql));

	//执行sql语句
	// 查询cpp数据库下的dept部门表
	const char* sql = "select * from dept";
	//执行sql语句
	//参数：数据库对象，const char*的数据库执行语句
	//执行成功返回0
	int ret = mysql_query(mysql, sql);
	if (ret != 0)
	{
		//mysql_error返回mysql数据库对象错误描述
		printf("mysql_query()失败了，原因：%s\n", mysql_error(mysql));
		return -1;
	}

	//取出结果,参数mysql数据对象
	//MYSQL_RES对应一块内存八寸执行之后的结果集
	//若错误，返回NULL
	MYSQL_RES* res = mysql_store_result(mysql);
	if (res == NULL)
	{
		printf("mysql_store_result()失败了，原因是:%s\n", mysql_error(mysql));
		return -1;
	}

	//得到结果集中的列数
	//参数：传入mysql_store_result()得到的返回值
	int num = mysql_num_fields(res);

	//得到所有列的名字，并且输出
	//参数传入mysql_store_result()得到的返回值
	//MYSQL_FIELD对应的是一个结构体
	MYSQL_FIELD* fields = mysql_fetch_fields(res);
	//遍历输出mysql的name
	for (int i = 0; i < num; i++)
	{

		printf("%s\t\t", fields[i].name);
	}
	printf("\n");
	
	//遍历结果集中的所有行
	//参数：mysql_store_result()得到的返回值
	// 成功得到当前记录中每一个字段的值
	// 失败/数据读完 返回NULL
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		// 将当前列中的每一列信息读出
		for (int i = 0; i < num; ++i)
		{
			printf("%s\t\t", row[i]);
		}
		printf("\n");
	}

	//释放资源 -结果集
	mysql_free_result(res);

	//写入数据
	//MySQL默认自动提交数据库
	//设置事务为手动提交
	mysql_autocommit(mysql, 0);
	//执行成功返回0
	int ret1 = mysql_query(mysql, "insert into dept values(10,'第一海军','海南')");
	int ret2 = mysql_query(mysql, "insert into dept values(11,'第二海军','福建')");
	int ret3 = mysql_query(mysql, "insert into dept values(12,'第三海军','辽宁')");

	printf("ret1=%d  ret2 = %d  ret3 = %d\n", ret1, ret2, ret3);

	if (ret1 == 0 && ret2 == 0 && ret3 == 0)
	{
		printf("执行成功，正在提交事务\n");
		//提交事务
		mysql_commit(mysql);
	}
	else
	{
		printf("执行失败，正在回滚....\n");
		printf("执行失败原因: %s\n", mysql_error(mysql));
		mysql_rollback(mysql);
	}
	//释放数据库资源
	mysql_close(mysql);

	return 0;
}