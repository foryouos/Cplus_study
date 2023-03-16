#include <iostream>
using namespace std;

struct Person
{
	int m_age;
};
Person g_person;  //全局变量初始化为0
int g_age;  //全局变量默认初始化为 0
int main(void)
{
	//Person person; //堆空间：没有初始化成员变量

	//堆空间:没有初始化成员变量
	Person* p0 = new Person;
	//堆空间:成员变量初始化为0，//如果有构造函数则不进行初始化
	Person* p1 = new Person();
	cout << g_age << endl;
	cout << g_person.m_age << endl;
	//cout << person.m_age << endl;
	cout << p0->m_age << endl;
	cout << p1->m_age << endl;

	return 0;
}
/*输出:
0
0
-842150451
0
*/