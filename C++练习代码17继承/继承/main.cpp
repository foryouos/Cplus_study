/*
* project :����λ�ã���ļ̳�
*/
#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(void)
{
	Rectangle rect;//����Rectangle��Ķ���
	//���þ�������
	rect.initRectangle(2, 3, 20, 10);//���þ�������
	rect.move(3, 2);//�ƶ�����λ��
	cout << "The data of rect(x,y,w,h):" << endl;
	//������ε���������
	cout << rect.getX() << "," << rect.getY() << "," << rect.getW() <<"," << rect.getH() << endl;
	return 0;
}
/*
The data of rect(x,y,w,h):
5,5,20,10
*/