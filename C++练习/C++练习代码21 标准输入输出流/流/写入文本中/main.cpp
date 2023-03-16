#include <fstream>
using namespace std;
int main(void)
{
	ofstream txtout("file1.txt");
	double values[] = { 1.23,35.36,653.7,4358.24 ,124567899 };
	for (int i = 0; i < 5; i++)
	{
		txtout.width(10);
		txtout <<  values[i] << endl;
	}
	txtout.close(); //¼ÇµÃ¹Ø±Õ
	return 0;
}