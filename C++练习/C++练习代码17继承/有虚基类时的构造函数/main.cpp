#include <iostream>
using namespace std;
class Base0
{
public:
	Base0(int var) :var0(var)
	{

	}
	int var0;
	void fun0()
	{
		cout << "member of bases0" << endl;
	}
};
class Base1 :virtual public Base0
{
public:
	Base1(int var) :Base0(var)
	{

	}
	int var1;

};
class Base2 :virtual public Base0
{
public:
	Base2(int var) :Base0(var)
	{

	}
	int var2;

};
class Derived :public Base1, public Base2
{
public:
	Derived(int var) :Base0(var), Base1(var), Base2(var) //
	{

	}
	int var;
	void fun()
	{
		cout << "member of Derived" << endl;
	}
};
int main(void)
{
	Derived d(1); //��Զ���������
	d.var0 = 2; //ֱ�ӷ������������ݳ�Ա
	d.fun0(); //ֱ�ӷ��������ĺ�����Ա

	return 0;
}
/*���:
member of bases0
*/