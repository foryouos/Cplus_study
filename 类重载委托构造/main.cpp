/*
* project:�����ϣ��߶Σ�Line����
* environment :VS2022
* time:2023��1��31��
*/
#include <iostream>
#include <cmath>
using namespace std;
class Point
{
public:
	Point(int xx, int yy)
	{
		x = xx;
		y = yy;
	};  //���캯��
	Point() :Point(5, 6) {};
	int getX() const { return x; } //������
	int getY() const { return y; }
private:
	int x, y;
};


int main(void)
{
	
	return 0;
}
