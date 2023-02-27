#include <iostream>
//C++��׼���������б�ʶ������������std�����ռ���
using namespace std;
class Point
{
public: //�ⲿ�ӿ�
	Point(int x = 0, int y = 0):x(x), y(x) //��������
	{
		//�ڹ��캯���ж�cout�ۼӣ����ж���ͬ��ͬά��һ��count
		count++;
	}
	Point(Point& p) //���ƹ��캯��
	{
		x = p.x;
		y = p.y;
		count++;
	}
	~Point()  //��������
	{
		count--;
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	static void showCount()  //��̬������Ա������������ֱ�ӵ��ò鿴count
	{
		cout << " Object count:" << count << endl;
	}
private:
	int x, y;
	static int count;  //��̬���ݳ�Ա���������ڼ�¼��ĸ���
};
int Point::count = 0;//��̬���ݳ�Ա����ͳ�ʼ����ʹ�������޶�
int main(void)
{
	Point::showCount(); //����������
	Point a(4, 5);
	cout << "Point A:" << a.getX() << "," << a.getY();
	a.showCount();//����������

	Point b(a);
	cout << "Point B:" << b.getX() << "," << b.getY();
	b.showCount();//����������
	return 0;
}
/*
* �����
Point A:4,4 Object count:1
Point B:4,4 Object count:2
*/