/*
Project:读取HTML文件
environment:visual studio 2022
*/
#include <iostream>
#include <string>
#include <istream> //输入流函数
#include <fstream> //文本输出
#include <iomanip> //文本对齐头文件
using namespace std;

int main(void)
{
	ifstream html("hello.htm", ios_base::in | ios_base::binary);
	string out;
	if (html)
	{
		while (html)
		{
			getline(html, out);
			cout << out << endl;
		}
	}
	else
	{
		cout << "Error!" << endl;
	}
	html.close(); //关闭文件
	return 0;
}