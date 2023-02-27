/* 
Project：有关常量的几个问题
*/
#include <iostream>
using namespace std;
const int N = 6;   //N值不可修改
int const M = 9;
const int* p; //*p不可修改,p可以更改指针
int const *q = 0; //可通过赋值指针修改
const int* const A = &N; //只可初始化，不可膝盖
int main(void)
{
	//N = 7;//错误
	//M = 5; //此值也不允许修改
	int a = 7;
	p = &a;  //地址不能改变，也不能*p赋值
	//*p = 9; //左值也不可修改
	p = &N;
	//*q = 9; //左值不可修改
	q = &a;
	cout << *q << endl;
	return 0;
}