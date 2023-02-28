/*
读入一个文件并显示出其中0元素的位置
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main(void)
{
	ifstream file("integers", ios_base::in | ios_base::binary);
	if (file)
	{
		while (file)  //读到文件尾file为0
		{
			//tellg函数返回当前文件读指针的位置
			streampos here = file.tellg();
			int v;
			file.read(reinterpret_cast<char*>(&v), sizeof(int));
			if (file && v == 0)
				cout << "Position:\t" << here << "\tis 0" << endl;
		}
	}
	else
	{
		cout << "ERROR:Cannot open file \"integers\"." << endl;
	}
	file.close();
}