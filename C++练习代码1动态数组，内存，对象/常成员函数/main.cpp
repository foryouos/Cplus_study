#include <iostream>
using namespace std;
class A
{
public:
	A(int i);
	void print();
private:
	const int a;  //在任何地方都不能赋值运算
	static const int b;//静态常数据成员
};
//A::A(int i){a=1}  //不能进行赋值，只能写入初始化列表里面
A::A(int i) :a(i)  //写入初始化列表
{

}




int main(void)
{
	R a(5, 4);
	a.print();
	const R b(20, 52);
	b.print();  //调用void print() const
	return 0; 
}