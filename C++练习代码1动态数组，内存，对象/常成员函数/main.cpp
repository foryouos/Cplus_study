#include <iostream>
using namespace std;
class A
{
public:
	A(int i);
	void print();
private:
	const int a;  //���κεط������ܸ�ֵ����
	static const int b;//��̬�����ݳ�Ա
};
//A::A(int i){a=1}  //���ܽ��и�ֵ��ֻ��д���ʼ���б�����
A::A(int i) :a(i)  //д���ʼ���б�
{

}




int main(void)
{
	R a(5, 4);
	a.print();
	const R b(20, 52);
	b.print();  //����void print() const
	return 0; 
}