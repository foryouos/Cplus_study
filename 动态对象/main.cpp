#include <iostream>
using namespace std;
class Point
{
public:
	Point(int x, int y)
	{
		cout << "Destructor called." << endl;
	};
	Point() :x(x), y(y)
	{
		cout << "Default Destructor called." << endl;
	};
	~Point()
	{
		cout << "Destructor called" << endl;
	}
	int getX() const { return x; } //������
	int getY() const { return y; }
	void move(int newX, int newY)
	{
		x = newX;
		y = newY;
	}
private:
	int x, y;
};

int main(void)
{
	Point* ptr = new Point[2];//������������
	ptr[0].move(5, 10); //ͨ��ָ���������Ԫ�صĳ�Ա
	ptr[1].move(15, 20); 
	cout << "Deleting..." << endl;
	delete[] ptr; //ɾ��������������
	return 0;
}
/*
Default Destructor called.
Default Destructor called.
Deleting...
Destructor called
Destructor called
*/
