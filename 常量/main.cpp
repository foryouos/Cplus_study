/* 
Project���йس����ļ�������
*/
#include <iostream>
using namespace std;
const int N = 6;   //Nֵ�����޸�
int const M = 9;
const int* p; //*p�����޸�,p���Ը���ָ��
int const *q = 0; //��ͨ����ֵָ���޸�
const int* const A = &N; //ֻ�ɳ�ʼ��������ϥ��
int main(void)
{
	//N = 7;//����
	//M = 5; //��ֵҲ�������޸�
	int a = 7;
	p = &a;  //��ַ���ܸı䣬Ҳ����*p��ֵ
	//*p = 9; //��ֵҲ�����޸�
	p = &N;
	//*q = 9; //��ֵ�����޸�
	q = &a;
	cout << *q << endl;
	return 0;
}