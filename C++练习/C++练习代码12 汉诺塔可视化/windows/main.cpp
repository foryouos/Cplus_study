/*
*project ������GetAsyncKeyState����
*/
/*
* project:��֤����ƶ�
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>

void Pos(int x, int y)//���ù��λ�ã������￪ʼ���
{
    COORD pos;//��ʾһ���ַ��ڿ���̨��Ļ�ϵ����꣬���Ͻǣ�0��0��
    pos.X = x;
    pos.Y = y;

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    //GetStdhandle���ڴ�һ���ض��ı�׼�豸����׼���롢��׼������׼������ȡ��һ�������������ʶ��ͬ�豸����ֵ��������Ƕ��ʹ�á�
    
    SetConsoleCursorPosition(handle, pos);
}
//�������ع�꺯��
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor;     //�����α���Ϣ
    cursor.bVisible = FALSE;        //�����α겻�ɼ�
    cursor.dwSize = sizeof(cursor);  //�����α겻�ɼ�����ֵ
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);  //�������λ��
}
int main(void)
{
    HideCursor();  //���ع��
    printf("��ŵ��������");
    Pos(45, 45);
    printf("���λ��������");
    getchar();
    return 0;
}