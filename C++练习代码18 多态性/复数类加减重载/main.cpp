#include <iostream>
using namespace std;
class Complex
{
public:
	Complex(double r = 0.0, double i = 0.0) :real(r), imag(i)
	{

	}
	//�����+���س�Ա����
	Complex operator + (const Complex& c2) const;
	//�����-���غ�����Ա
	Complex operator - (const Complex& c2) const;
	void display() const; //�������
private:
	double real; //����ʵ��
	double imag; //�����鲿
};

Complex Complex::operator+(const Complex& c2) const
{
	//����һ����ʱ����������Ϊ����ֵ
	return Complex(real + c2.real, imag + c2.imag);
}
Complex Complex::operator- (const Complex & c2) const //����������Ҳ�����
{
	return Complex(real - c2.real, imag - c2.imag);
}
void Complex::display() const
{
	cout << "(" << real << "," << imag << ")" << endl;
}

int main(void)
{
	Complex c1(5, 4), c2(2, 10), c3;
	cout << "c1 = ";
	c1.display();
	cout << "c2 = ";
	c2.display();
	c3 = c1 - c2;  //ʹ�������������ɸ�������
	cout << "c3 = c1 - c2 =";
	c3.display();
	c3 = c1 + c2; //ʹ�������������ɸ����ӷ�
	cout << "c3 = c1 + c2 =";
	c3.display();
	return 0;
}
/*
c1 = (5,4)
c2 = (2,10)
c3 = c1 - c2 =(3,-6)
c3 = c1 + c2 =(7,14)
*/

