/* 
get����Ӧ��
*/
#include <iostream>
using namespace std;
int main(void)
{
	char ch;
	//�Ӽ��������룬Ȼ�����
	while ((ch = cin.get()) != EOF) 
	{
		cout.put(ch);
	}
	//ctrl+z����
	return 0;
}