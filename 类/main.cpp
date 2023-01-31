/*
* project:�ӱ���
* environment :VS2022
* time:2023��1��31��
*/
#include <iostream>
using namespace std;
class Clock  //������߽�
{
	public:  //�ض�����Ȩ��
		//�ⲿ�ӿڣ�����Ĭ�ϲ���ֵ
		void setTime(int newH = 0, int newM = 0, int newS = 0);  
		void showTime();
	private: //���к�������˽�г�Ա
		int hour, minute, second;
};
//��Ա������ʵ�֣����еĺ���
void Clock::setTime(int newH, int newM, int newS) 
{
	hour = newH;
	minute = newM;
	second = newS;
}
void Clock::showTime()
{
	cout << "Time:" << hour << ":" << minute << ":" << second << endl;
};

int main(void)
{
	Clock C;  //�������
	cout << "First time set and output:" << endl;
	C.setTime(); //������ʣ�ʹ��Ĭ��ʱ��
	C.showTime(); //x��ʾʱ��
	cout << "Second time set and output:" << endl;
	C.setTime(12, 48, 30);  //�������
	C.showTime();

	return 0;
}
