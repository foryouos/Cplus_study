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
	d.var0 = 2; //直接访问虚基类的数据成员
	d.fun0(); //直接访问虚基类的函数成员
	cout << &d.Base1::var0 << ", " << &d.Base2::var0 << endl; //空间地址相同
	cout << &d.var0;
	
	return 0;
}
/*输出:
member of bases1
00000066B05BF6E0, 00000066B05BF6E0
00000066B05BF6E0
*/