#include <stdio.h>
//ֻ������һ���������ͣ���û�ж�����������������͵�������enum WeekDay��
//����ȡ�����ֵ
enum WeekDay
{ //�޸�Ĭ��ֵ��5��ʼ
	Monday=5,Tuesday,Wednesday,Thuesday,Friday,Saturday,Sunday
};

int main(void)
{
	enum WeekDay day = Wednesday; //ֻ��ȥö���е��κ�һ��

	printf("%d", day); //����� 2��ö�ٵ�ֵĬ�ϴ�0��ʼ
	return 0;
}