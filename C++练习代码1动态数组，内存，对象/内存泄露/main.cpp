#include <iostream>
int* newintvar()
{
	int* p = new int();  
	return p; //���صĵ�ַָ����Ƕ�̬����Ŀռ�
	//�������н���ʱ��p�еĵ�ַ����Ч
}
int main(void)
{
	int* newintvar();
	int* intptr = newintvar();
	*intptr = 5; //���ʵ��ǺϷ���Ч�ĵ�ַ
	delete intptr;  //��������������ͷţ�������ڴ�й¶
	return 0;
}