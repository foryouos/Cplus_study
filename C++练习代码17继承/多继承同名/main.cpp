#include <iostream>
using namespace std;
class Base0
{
public:
	int var0;
	void fun0()
	{
		cout << "member of bases1" << endl;
	}
};
class Base1:virtual public Base0
{
public:
	int var1;
	
};
class Base2 :virtual public Base0
{
public:
	int var2;

};
class Derived:public Base1,public Base2
{
public:
	int var;
	void fun()
	{
		cout << "member of Derived" << endl;
	}
};
int main(void)
{
	Derived d;
	d.var0 = 2; //ֱ�ӷ������������ݳ�Ա
	d.fun0(); //ֱ�ӷ��������ĺ�����Ա
	cout << &d.Base1::var0 << ", " << &d.Base2::var0 << endl; //�ռ��ַ��ͬ
	cout << &d.var0;
	
	return 0;
}
/*���:
member of bases1
00000066B05BF6E0, 00000066B05BF6E0
00000066B05BF6E0
*/