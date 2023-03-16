/*
从文件中读一个二进制记录到一个结构体
*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct SalaryInfo
{
	unsigned id;
	double salary;
};
int main(void)
{
	SalaryInfo employee1 = { 600001,8000 }; //声明结构体
	ofstream os("payroll", ios_base::out | ios_base::binary); //文件输出流，二进制类型
	//字符转换，大小
	os.write(reinterpret_cast<char*>(&employee1), sizeof(employee1)); //将结构体写入文件输出流
	os.close();
	ifstream is("payroll", ios_base::in | ios_base::binary); //读二进制文件。输入方式，二进制文件
	if (is)
	{
		SalaryInfo employee2;
		is.read(reinterpret_cast<char*>(&employee2),sizeof(employee2));
		cout << employee2.id << " " << employee2.salary << endl;
	}
	else
	{
		cout << "ERROR:Cannot open file 'payroll'" << endl;
	}
	is.close();
	return 0;
}