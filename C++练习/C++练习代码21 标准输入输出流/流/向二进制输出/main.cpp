#include <fstream>
using namespace std;
struct Date
{
	int mon, day, year;
};
int main(void)
{
	Date dt = { 6,10,92 };
	ofstream file("date.dat", ios_base::binary); //¶þ½øÖÆ
	file.write(reinterpret_cast<char*>(&dt), sizeof(dt));
	file.close();
}