#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

//��ƽ���ĺ���
double square(double x)
{
	return x * x;
}
int main(void)
{
	//�ӱ�׼����������ɸ�ʵ�����ֱ����ǵ�ƽ�����
	transform(istream_iterator<double>(cin), istream_iterator<double>(), ostream_iterator<double>(cout, "\t"), square);
	//ͷ��β��д��������������
	//ͷ����������������double�� ������cin
	//βû�й��캯��������Ϊ�գ�----ָ������������
	//д����:cout
	//��������:square

	cout << endl;
}