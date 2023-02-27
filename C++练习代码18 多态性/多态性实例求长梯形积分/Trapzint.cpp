/*��ʵ��*/
#include "Trapzint.h"
#include <cmath>
//��������
double MyFunction::operator()(double x) const
{
	return log(1.0 + x) / (1.0 + x * x);  //f(x)������ʵ��
}
//����������̣�����Ϊ�����()
double Trapz::operator()(double a, double b, double eps) const //�����ֵ����±��Լ����
{
	bool done = false;  //��Trapz����麯����Ա
	int n = 1;
	double h = b - a;
	double tn = h * (f(a) + f(b)) / 2;  //����n=1ʱ�Ļ���ֵ
	double t2n;
	do  //����f������a,b֮��Ļ��ֽ�������ּ��������eps�����ƣ�
	{
		double sum = 0;
		for (int k = 0; k < n; k++) //�ۼ�f(x)����
		{
			double x = a + (k + 0.5) * h;
			sum += f(x);
		}
		t2n = (tn + h * sum) / 2.0;  //�䲽�����η�����
		if (fabs(t2n - tn) < eps)  //�жϻ������
			done = true;
		else
		{
			tn = t2n;
			n *= 2;
			h /= 2;
		}
	} while (!done);
	return t2n;

}