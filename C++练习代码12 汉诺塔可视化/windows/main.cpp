/*
*project ：测试GetAsyncKeyState函数
*/
/*
* project:验证光标移动
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>

void Pos(int x, int y)//设置光标位置，从哪里开始输出
{
    COORD pos;//表示一个字符在控制台屏幕上的坐标，左上角（0，0）
    pos.X = x;
    pos.Y = y;

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    //GetStdhandle用于从一个特定的标准设备（标准输入、标准输出或标准错误）中取得一个句柄（用来标识不同设备的数值）。可以嵌套使用。
    
    SetConsoleCursorPosition(handle, pos);
}
//定义隐藏光标函数
void HideCursor()
{
    CONSOLE_CURSOR_INFO cursor;     //定义游标信息
    cursor.bVisible = FALSE;        //设置游标不可见
    cursor.dwSize = sizeof(cursor);  //设置游标不可见的数值
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);  //定义光标的位置
}
int main(void)
{
    HideCursor();  //隐藏光标
    printf("汉诺塔层数：");
    Pos(45, 45);
    printf("光标位置在这里");
    getchar();
    return 0;
}