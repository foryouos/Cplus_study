/*
为输入流指定一个终止字符
*/

#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string line;
	cout << "Type a line terminated by '\t'" << endl;
	getline(cin, line, '\t');
	cout << line <<  endl;
}