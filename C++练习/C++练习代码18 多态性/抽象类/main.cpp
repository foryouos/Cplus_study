/* ������ 
* ���д��麯������ͽ����������ࡱ

*/
#include <iostream>
using namespace std;
class Base1
{
public:
	virtual void display() const = 0; //���麯��������û�нṹ�壬����0
	//�������ǲ���ʵ������
};
class Base2 :public Base1
{
public:
	virtual void display() const;//���ǻ�����麯��
}; 
void Base2::display() const
{
	cout << "Base2::display()" << endl;
}
class Derived :public Base2
{
public:
	virtual void display() const; //���ǻ�����麯��
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


