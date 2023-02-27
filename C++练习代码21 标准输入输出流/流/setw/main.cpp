#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main(void)
{
	double values[] = { 1.23,35.36,653.7,4358.24 };
	string names[] = { "Zoot","Jimmy","AI","Stan" };
	for (int i = 0; i < 4; i++)
	{
		cout << setw(6) << names[i]
			<< setw(10) << values[i] << endl;
	}
	//���ö��뷽ʽ
	cout << "���ö��뷽ʽ" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << setiosflags(ios_base::left) //�����
			<< setw(6) << names[i]
			<< setw(10) << values[i] << endl;
	}
	//�������
	cout << "�����������" << endl;
	cout << setiosflags(ios_base::fixed);
	for (int i = 0; i < 4; i++)
	{
		cout << setiosflags(ios_base::left) //�����
			<< setw(6) << names[i]
			<< setw(10) << values[i]
			<< resetiosflags(ios_base::left)//������������
			<< setw(10) << setprecision(1) <<values[i]
			<<endl;
	}

	//�������scientific
	cout << "�����������scientific" << endl;
	cout << setiosflags(ios_base::scientific);
	for (int i = 0; i < 4; i++)
	{
		cout << setiosflags(ios_base::left) //�����
			<< setw(6) << names[i]
			<< resetiosflags(ios_base::left)//������������
			<< setw(10) << setprecision(1) << values[i]
			<< endl;
	}

	return 0;
}
/*
  Zoot      1.23
 Jimmy     35.36
	AI     653.7
  Stan   4358.24
���ö��뷽ʽ
Zoot  1.23
Jimmy 35.36
AI    653.7
Stan  4358.24
�����������
Zoot  1.230000         1.2
Jimmy 35.4            35.4
AI    653.7          653.7
Stan  4358.2        4358.2
�����������scientific
Zoot  0x1.3ae147ae147aep+0
Jimmy 0x1.1ae147ae147aep+5
AI    0x1.46d999999999ap+9
Stan  0x1.1063d70a3d70ap+12
*/