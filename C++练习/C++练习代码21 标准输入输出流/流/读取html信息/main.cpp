/*
Project:��ȡHTML�ļ�
environment:visual studio 2022
*/
#include <iostream>
#include <string>
#include <istream> //����������
#include <fstream> //�ı����
#include <iomanip> //�ı�����ͷ�ļ�
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
	html.close(); //�ر��ļ�
	return 0;
}