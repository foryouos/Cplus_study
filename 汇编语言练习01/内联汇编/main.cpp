#include <iostream>
using namespace std;

int main()
{
	int age = 10;
	const long& aAge = age;
	age = 30;
	/*
	00007FF71556184D C7 45 04 0A 00 00 00 mov         dword ptr [rbp+4],0Ah  
	00007FF715561854 8B 45 04             mov         eax,dword ptr [rbp+4]  
	00007FF715561857 89 45 44             mov         dword ptr [rbp+44h],eax  
	00007FF71556185A 48 8D 45 44          lea         rax,[rbp+44h]  
	00007FF71556185E 48 89 45 28          mov         qword ptr [rbp+28h],rax  
	00007FF715561862 C7 45 04 1E 00 00 00 mov         dword ptr [rbp+4],1Eh  
	*/
}