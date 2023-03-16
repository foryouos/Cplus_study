#include  <iostream>
#include "math.h"
using namespace std;

/* 
两者引用：机器码相同，汇编相同
*/
int main()
{
	int a = 5;
	a = a + 1;
	/*
	    10: 	int a = 5;
00007FF6E7DA520D C7 45 04 05 00 00 00 mov         dword ptr [rbp+4],5  
    11: 	a = a + 1;
00007FF6E7DA5214 8B 45 04             mov         eax,dword ptr [rbp+4]  
00007FF6E7DA5217 FF C0                inc         eax  
00007FF6E7DA5219 89 45 04             mov         dword ptr [rbp+4],eax 
	*/



	int age = 22;
	int* p = &age;
	*p = 25;
	cout << age << endl;
	/*
	    11: 	int* p = &age;
00007FF6CD505214 48 8D 45 04          lea         rax,[rbp+4]  
00007FF6CD505218 48 89 45 28          mov         qword ptr [rbp+28h],rax  
    12: 	*p = 25;
00007FF6CD50521C 48 8B 45 28          mov         rax,qword ptr [rbp+28h]  
00007FF6CD505220 C7 00 19 00 00 00    mov         dword ptr [rax],19h  
	*/

	int& ref = age;
	ref = 30;
	cout << age << endl;
	/*
	 9: 	int& ref = age;
00007FF759091914 48 8D 45 04          lea         rax,[rbp+4]
00007FF759091918 48 89 45 28          mov         qword ptr [rbp+28h],rax
	10: 	ref = 30;
00007FF75909191C 48 8B 45 28          mov         rax,qword ptr [rbp+28h]
00007FF759091920 C7 00 1E 00 00 00    mov         dword ptr [rax],1Eh
	*/

	return 0;
}
