#include "MySQLConnect.h"

void MySqlConnect::freeResult()
{
	if (m_result)
	{
		mysql_free_result(m_result);
		m_result = nullptr;
	}
}

MySqlConnect::MySqlConnect()
{
	m_conn = mysql_init(nullptr);
	mysql_set_character_set(m_conn, "utf8");
}

MySqlConnect::~MySqlConnect()
{
	if (m_conn != nullptr)
	{
		mysql_close(m_conn);
	}
	freeResult();
}

bool MySqlConnect::connect(string user, string passwd, string dbName, string ip, unsigned short port)
{
	//ip����Ϊstring��ʹ��.str��ipתΪchar *����
	MYSQL* ptr = mysql_real_connect(m_conn, ip.c_str(), user.c_str(), passwd.c_str(), dbName.c_str(), port, nullptr, 0);
	//���ӳɹ�����true
	//������ӳɹ�����TRUE��ʧ�ܷ���FALSE
	return ptr != nullptr;
}

bool MySqlConnect::update(string sql)
{
	//queryִ�гɹ�����0
	if (mysql_query(m_conn, sql.c_str()))
	{
		return false;
	};

	return true;
}

bool
MySqlConnect::query(string sql)
{
	freeResult();
	//queryִ�гɹ�����0
	if (mysql_query(m_conn, sql.c_str()))
	{
		return false;
	};
	m_result = mysql_store_result(m_conn);
	return true;
}

bool MySqlConnect::next()
{
	//��������Ϊ����û�б�Ҫ����
	if (m_result != nullptr)
	{
		//�����ŵ�ǰ�ֶε������е���ֵ
		m_row = mysql_fetch_row(m_result);
		return true;
	}
	return false;
}

string MySqlConnect::value(int index)
{
	//��ʾ�е�����
	int row_num = mysql_num_fields(m_result); //�����õ�������е�����
	//�����ѯ�ĵ�index�д������У���С��0���Ǵ����
	if (index >= row_num || index < 0)
	{
		return string();
	}
	char* val = m_row[index]; //��Ϊ���������ݣ��м�����"\0"��
	unsigned long length = mysql_fetch_lengths(m_result)[index];
	return string(val, length); //����length�Ͳ�����"\0"Ϊ������������ͨ�����ȰѶ�Ӧ���ַ�ת��Ϊstring����
}

bool MySqlConnect::transaction()
{
	return mysql_autocommit(m_conn, false); //��������ֵ�������bool����
}

bool MySqlConnect::commit()
{
	return mysql_commit(m_conn);//�ύ
}

bool MySqlConnect::rollback()
{
	return mysql_rollback(m_conn);//bool���ͣ������ɹ�����TRUE��ʧ�ܷ���FALSE
}
