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
		//Clock() = default;
		Clock(int newH, int newM , int newS );  //���캯��
		Clock(); //Ĭ�Ϲ��캯��
		//�ⲿ�ӿڣ�����Ĭ�ϲ���ֵ
		void setTime(int newH, int newM, int newS);  
		void showTime();
	private: //���к�������˽�г�Ա
		int hour, minute, second;
};
Clock::Clock(int newH, int newM, int newS):hour(newH),minute(newM),second(newS)
{

}
Clock::Clock():Clock(0,0,0){}

//��Ա������ʵ�֣����еĺ���
void Clock::setTime(int newH, int newM, int newS) 
{
	this->hour = newH;
	minute = newM;
	second = newS;
}
void Clock::showTime()
{
	cout << "Time:" << hour << ":" << minute << ":" << second << endl;
};

int main(void)
{
	Clock C(6, 40, 30);
	Clock C2;  //�������
	cout << "First time set and output:" << endl;
	//C.setTime(); //������ʣ�ʹ��Ĭ��ʱ��
	C2.showTime(); //x��ʾʱ��
	//cout << "Second time set and output:" << endl;
	//C.setTime(12, 48, 30);  //�������
	//C.showTime();

	return 0;
}
