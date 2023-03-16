/* 抽象类 
* 具有纯虚函数的类就叫做“抽象类”

*/
#include <iostream>
using namespace std;
class Base1
{
public:
	virtual void display() const = 0; //纯虚函数，函数没有结构体，等于0
	//抽象类是不能实例化的
};
class Base2 :public Base1
{
public:
	virtual void display() const;//覆盖基类的虚函数
}; 
void Base2::display() const
{
	cout << "Base2::display()" << endl;
}
class Derived :public Base2
{
public:
	virtual void display() const; //覆盖基类的虚函数
};
void Derived::display() const
{
	cout << "Derived::display()" << endl;
}
void fun(Base1* ptr)
{
	ptr->display();
}
int main(void)
{
	Base2 base2;
	Derived derived;
	fun(&base2);
	fun(&derived);


	return 0;
}


