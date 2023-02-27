#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
struct student //定义的类型  结构体//第一种方式
{
	char name[30];
	int age;
	float score;
	char sex;
};
int main(void)
{
	struct student st = {"yuheshui",80,66.6F,'F'};  // 结构体变量
	struct student* pst = &st;
	pst->age = 99;//第二种方式  
	/* 
	pst->age 在计算机内部会被转化成（*pst).age 
	*/
	st.age = 10;//第一种方式
	struct student st2;
	strcpy(st2.name, "foryouos");
	//st2.name = "foryouos";  //数组名即地址是常量，非变量，也不能直接赋值
	st2.age = 10;
	st2.score = 88.6f;  //88.6在C语言中默认是double类型，
	//如果希望一个实数是float类型，则必须在末位在f或F，因此88.6f或88.6F 是float类型

	st2.sex = 'F';
	printf("%s %d %f %c\n",st.name, st.age, st.score, st.sex);
	printf("%s %d %f %c\n", st2.name, st2.age, st2.score, st2.sex);
	return 0;
}