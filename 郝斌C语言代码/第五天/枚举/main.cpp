#include <stdio.h>
//只定义了一个数据类型，并没有定义变量，该数据类型的名字是enum WeekDay，
//可以取下面的值
enum WeekDay
{ //修改默认值从5开始
	Monday=5,Tuesday,Wednesday,Thuesday,Friday,Saturday,Sunday
};

int main(void)
{
	enum WeekDay day = Wednesday; //只能去枚举中的任何一个

	printf("%d", day); //输出的 2，枚举的值默认从0开始
	return 0;
}