#include <iostream>
int* newintvar()
{
	int* p = new int();  
	return p; //返回的地址指向的是动态分配的空间
	//函数运行结束时，p中的地址仍有效
}
int main(void)
{
	int* newintvar();
	int* intptr = newintvar();
	*intptr = 5; //访问的是合法有效的地址
	delete intptr;  //如果忘记在这里释放，会造成内存泄露
	return 0;
}