#include <iostream>
using namespace std;
struct Person
{
	int m_age;

	Person()
	{
		cout << "Person()" << endl;
	}
	~Person()
	{
		cout << "释放Person()" << endl;
	}
};
int main(void)
{
	Person person; //会调用默认构造函数
	Person* p = new Person; //申请空间也会调用默认构造函数
	delete p;
	//malloc并不调用默认构造函数,
	Person* q = (Person*)malloc(sizeof(Person));
	free(q); //也不会调用析构函数
	return 0;
}