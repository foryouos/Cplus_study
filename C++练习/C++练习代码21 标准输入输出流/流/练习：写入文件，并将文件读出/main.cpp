#include <iostream>
#include <fstream> //文本 输出
#include <string> //引用字符串
#include <iomanip>  //对齐操作符头文件
#include <istream>  //输入流函数
using namespace std;

int main(void)
{
	//打开文件，默认文本形式
	ofstream textout("test.txt",ios_base::out | ios_base::binary);
	string hello = "hello test\nhello second!";
	//textout.width(20);  //文字占20个字节
	textout 
		//<< setiosflags(ios_base::right)  //右对齐
		<<hello<<endl;
	textout.close();

	//读取文章内容
	ifstream myFile("test.txt", ios_base::in | ios_base::binary);
	string out;
	while (myFile) //使用while读取一行一行的读入
	{
		//使用getline读取文件中字符，
		//getline函数原型 getline(std::cin,string s，char ch),
		//表示以字符ch来结束字符串的读入。
		getline(myFile, out);
		cout << out << endl;
	}
	/*else
	{
			cout << "ERROR:Cannot open file 'text.txt'" << endl;
	}*/
	myFile.close();
	return 0;
}