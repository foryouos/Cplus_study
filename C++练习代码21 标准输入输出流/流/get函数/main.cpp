/* 
get函数应用
*/
#include <iostream>
using namespace std;
int main(void)
{
	char ch;
	//从键盘中输入，然后输出
	while ((ch = cin.get()) != EOF) 
	{
		cout.put(ch);
	}
	//ctrl+z结束
	return 0;
}