#include <iostream>
#include <fstream> //�ı� ���
#include <string> //�����ַ���
#include <iomanip>  //���������ͷ�ļ�
#include <istream>  //����������
using namespace std;

int main(void)
{
	//���ļ���Ĭ���ı���ʽ
	ofstream textout("test.txt",ios_base::out | ios_base::binary);
	string hello = "hello test\nhello second!";
	//textout.width(20);  //����ռ20���ֽ�
	textout 
		//<< setiosflags(ios_base::right)  //�Ҷ���
		<<hello<<endl;
	textout.close();

	//��ȡ��������
	ifstream myFile("test.txt", ios_base::in | ios_base::binary);
	string out;
	while (myFile) //ʹ��while��ȡһ��һ�еĶ���
	{
		//ʹ��getline��ȡ�ļ����ַ���
		//getline����ԭ�� getline(std::cin,string s��char ch),
		//��ʾ���ַ�ch�������ַ����Ķ��롣
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