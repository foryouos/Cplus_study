/*
����һ���ļ�����ʾ������0Ԫ�ص�λ��
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
		while (file)  //�����ļ�βfileΪ0
		{
			//tellg�������ص�ǰ�ļ���ָ���λ��
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